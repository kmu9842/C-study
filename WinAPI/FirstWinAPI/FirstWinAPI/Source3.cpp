/*#include <windows.h>

int flag[4] = { 0, };

// 이벤트 드리븐 방식 = 이벤트 기반 방식
// 메세지 드리븐 방식 = 메세지 기반 방식

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // 사용자와 시스템이 보내오는 메시지를 처리하는 역할
													  // WndProc와 WinMain둘다 필수 함수
													  // WinMain은 윈도우를 만들고 표시하기만 할뿐 대부분의 일은 WndProc에서 이루어짐

HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First");	// 윈도우 클래스를 정의하는데 사용됨

									// APIENTRY는 윈도우즈의 표준 호출 규약 _stdcall을 사용한다는 뜻.
									// WinMain의 매개 변수
									// hInstance 프로그램의 인스턴스 핸들
									// hPrevInstance 바로 앞에 실행된 현재 프로그램의 인스턴스 핸들이다. 없을 경우 NULL이 되면 Win32에서는 항상 NULL이다. 16비트를 지원하기 위한 인수
									// lpszCmdParam 명령행으로 입력된 프로그램 인수. 도스의 argv인수에 해당하며 실행 직후 열파일의 경로가 전달된다.
									// nCmdShow 프로그램이 실행될 형태이며 최소화, 보통 모양 등이 전달된다.

									// 인스턴스라는 말은 실행중인 프로그램 하나를 칭하는 용어이다.
									// 프로그램 내부에서 자신을 가리키는 1인칭 대명사 같은것
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {

	HWND hWnd; // 윈도우 핸들
	WNDCLASSEX WndClass;
	MSG Message;

	g_hInst = hInstance;

	WndClass.cbSize = sizeof(WNDCLASSEX);
	WndClass.cbClsExtra = 0;										// 클래스와 윈도우를 위한 여분의 메모리 크기
	WndClass.cbWndExtra = 0;										//	``
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 윈도우의 배경색
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// 기본 커서
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// 기본 아이콘
	WndClass.hInstance = hInstance;									// 메인 함수에 첫번째 매개변수로 넘어온 인스턴스 값
	WndClass.lpfnWndProc = WndProc;									// 메시지 처리에 사용될 함수의 이름 기재
	WndClass.lpszClassName = lpszClass;								// 윈도우 클래스의 이름
	WndClass.lpszMenuName = lpszClass;								// 메뉴의 이름
	WndClass.style = CS_HREDRAW | CS_VREDRAW;						// 윈도우가 출력되는 형태
	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&WndClass);										// 커널에 윈도우 클래스 등록

	hWnd = CreateWindow(		// 윈도우 생성 함수, 보여주지는 않음, false가 뜰경우 종료
		lpszClass,				// 윈도우 클래스 이름
		lpszClass,				// 윈도우 타이틀 이름
		WS_OVERLAPPEDWINDOW,	// 윈도우 스타일
		CW_USEDEFAULT,			// 윈도우 위치 X좌표
		CW_USEDEFAULT,			// 윈도우 위치 Y좌표
		CW_USEDEFAULT,			// 윈도우 가로 크기
		CW_USEDEFAULT,			// 윈도우 세로 크기
		NULL,					// 부모 윈도우 핸들
		(HMENU)NULL,			// 메뉴 핸들
		hInstance,				// 응용프로그램 인스턴스
		NULL					// 생성 윈도우 정보
		);

	ShowWindow(hWnd, nCmdShow); // 윈도우를 화면에 보여줌

	while (GetMessage(&Message, NULL, 0, 0)) { // 메세지 받아오기
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return (int)Message.wParam;
}

// 메세지 처리 함수
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;

	HBRUSH MyBrush1, MyBrush2;
	RECT rt[4] = { {0, 290, 100, 310},
	{ 200, 290, 300, 310 },
	{ 100, 90, 200, 110 },
	{ 100, 490, 200, 510 } };
	
	char a[4][10] = {"왼쪽","오른쪽","위쪽","아래쪽"};

	//flag[2] = 1;

	switch (iMessage) {
	case WM_CREATE:	// 생성 이벤트시 호출
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		MyBrush1 = CreateSolidBrush(RGB(255, 254, 255));	 // 브러쉬 정보 생성
		MyBrush2 = CreateSolidBrush(RGB(255, 0, 0));	 // 브러쉬 정보 생성

		if (flag[0]) SelectObject(hdc,MyBrush2);
		else SelectObject(hdc,MyBrush1);

		Rectangle(hdc, 100, 0, 200, 200);
		DrawTextA(hdc, a[2], 4, &rt[2], DT_CENTER | DT_WORDBREAK);

		if (flag[1]) SelectObject(hdc, MyBrush2);
		else SelectObject(hdc, MyBrush1);

		Rectangle(hdc, 0, 200, 100, 400);
		DrawTextA(hdc, a[0], 4, &rt[0], DT_CENTER | DT_WORDBREAK);

		if (flag[2]) SelectObject(hdc, MyBrush2);
		else SelectObject(hdc, MyBrush1);
		Rectangle(hdc, 200, 200, 300, 400);
		DrawTextA(hdc, a[1], 6, &rt[1], DT_CENTER | DT_WORDBREAK);

		if (flag[3]) SelectObject(hdc, MyBrush2);
		else SelectObject(hdc, MyBrush1);

		Rectangle(hdc, 100, 400, 200, 600);
		DrawTextA(hdc, a[3], 6, &rt[3], DT_CENTER | DT_WORDBREAK);
		
		EndPaint(hWnd, &ps);
		break;

	case WM_KEYDOWN:
		switch (wParam) {
		case VK_RIGHT:
			flag[2] = true;
			break;
		case VK_LEFT:
			flag[1] = true;
			break;
		case VK_UP:
			flag[0] = true;
			break;
		case VK_DOWN:
			flag[3] = true;
			break;
		default:
			break;
		}

		InvalidateRgn(hWnd, NULL, true);
		break;

	case WM_KEYUP:
		switch (wParam) {
		case VK_RIGHT:
			flag[2] = false;
			break;
		case VK_LEFT:
			flag[1] = false;
			break;
		case VK_UP:
			flag[0] = false;
			break;
		case VK_DOWN:
			flag[3] = false;
			break;
		default:
			break;
		}

		InvalidateRgn(hWnd, NULL, true);
		break;

	case WM_DESTROY:	// 종료 이벤트시 호출
		PostQuitMessage(0); // 종료
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}*/
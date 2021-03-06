/*#include <windows.h>

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
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM IParam) {
	HDC hdc;
	PAINTSTRUCT ps;

	int x = 0, y = 0;
	static int count = 0;
	static int cursorPos = 0;
	static int lastLSize = 0;
	static char str[200];

	POINT point[5] = { {200,20},{ 250,50 },{ 500,100 },{ 400,200 },{ 200,200 } };

	LPCSTR a;
	SIZE size;

	switch (iMessage) {
	case WM_CREATE:	// 생성 이벤트시 호출
		CreateCaret(hWnd, NULL, 5, 15);
		ShowCaret(hWnd);
		count = 0;
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd,&ps);

		for (int i = 0;i<count;i++) {
			if (str[i] == '\n') {
				y+=20;
				x = 0;
				SetCaretPos(x, y);
			}
			else {
				a = &str[i];
				TextOutA(hdc, x, y, a, 1);
				GetTextExtentPointA(hdc,&str[i],1,&size);
				lastLSize = size.cx;
				x += size.cx;
				cursorPos++;
				SetCaretPos(x,y);
			}
		}

		if (count == 0) {
			x = 0;
			y = 0;
			SetCaretPos(x, y);
		}

		MoveToEx(hdc,100,100,NULL);
		LineTo(hdc,150,150);

		Ellipse(hdc,0,0,40,40);

		Rectangle(hdc,50,50,80,80);

		Polygon(hdc,point,5);

		EndPaint(hWnd,&ps);

		break;
	case WM_KEYDOWN :

		if (wParam == VK_BACK && count>0) {
			count--;
			cursorPos--;
		}

		else if (wParam == VK_RIGHT) {
			cursorPos++;
		}

		else if (wParam == VK_LEFT) {
			cursorPos--;
		}

		else if (wParam == VK_RETURN) {
			str[count++] = '\n';
			str[count] = '\0';
		}
		else {
			if (wParam != '\b') {
				str[count++] = wParam;
			}
			cursorPos++;
			str[count] = '\0';
		}

		// 화면 영역 수정 함수 (수정될 영역이 포함된 윈도우의 핸들값, 수정될 영역에 대한 핸들값(NULL값은 전체), 모두 삭제 할지 삭제하지 않고 수정되는 부분만 추가 할지)
		// WM_PAINT를 다시 호출하는것
		InvalidateRgn(hWnd, NULL, true);

		break;

	case WM_CHAR :
		
		

		break;

	case WM_DESTROY:	// 종료 이벤트시 호출
		PostQuitMessage(0); // 종료
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, IParam));
}*/
#include <windows.h>

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
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	// 윈도우의 배경색
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// 기본 커서
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// 기본 아이콘
	WndClass.hInstance = hInstance;									// 메인 함수에 첫번째 매개변수로 넘어온 인스턴스 값
	WndClass.lpfnWndProc = WndProc;									// 메시지 처리에 사용될 함수의 이름 기재
	WndClass.lpszClassName = lpszClass;								// 윈도우 클래스의 이름
	WndClass.lpszMenuName = lpszClass;								// 메뉴의 이름
	WndClass.style = WS_OVERLAPPEDWINDOW| CS_HREDRAW | CS_VREDRAW;// | WS_OVERLAPPEDWINDOW;						// 윈도우가 출력되는 형태
	WndClass.hIconSm = LoadIcon(NULL,IDI_APPLICATION);

	RegisterClassEx(&WndClass);										// 커널에 윈도우 클래스 등록

	hWnd = CreateWindow(
		lpszClass, 
		lpszClass, 
		WS_EX_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT,
		NULL, 
		(HMENU)NULL, 
		hInstance, 
		NULL
	);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM IParam) {
	switch (iMessage) {
	case WM_CREATE :
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, IParam));
}
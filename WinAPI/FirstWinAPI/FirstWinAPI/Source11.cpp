//#include <windows.h>
//#include <math.h>
//#include <string>
//
//#include "resource.h"
//
//// 이벤트 드리븐 방식 = 이벤트 기반 방식
//// 메세지 드리븐 방식 = 메세지 기반 방식
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // 사용자와 시스템이 보내오는 메시지를 처리하는 역할
//													  // WndProc와 WinMain둘다 필수 함수
//													  // WinMain은 윈도우를 만들고 표시하기만 할뿐 대부분의 일은 WndProc에서 이루어짐
//
//HINSTANCE g_hInst;
//LPCTSTR lpszClass = TEXT("First");	// 윈도우 클래스를 정의하는데 사용됨
//
//									// APIENTRY는 윈도우즈의 표준 호출 규약 _stdcall을 사용한다는 뜻.
//									// WinMain의 매개 변수 
//									// hInstance 프로그램의 인스턴스 핸들
//									// hPrevInstance 바로 앞에 실행된 현재 프로그램의 인스턴스 핸들이다. 없을 경우 NULL이 되면 Win32에서는 항상 NULL이다. 16비트를 지원하기 위한 인수
//									// lpszCmdParam 명령행으로 입력된 프로그램 인수. 도스의 argv인수에 해당하며 실행 직후 열파일의 경로가 전달된다.
//									// nCmdShow 프로그램이 실행될 형태이며 최소화, 보통 모양 등이 전달된다.
//
//									// 인스턴스라는 말은 실행중인 프로그램 하나를 칭하는 용어이다. 
//									// 프로그램 내부에서 자신을 가리키는 1인칭 대명사 같은것
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
//
//	HWND hWnd; // 윈도우 핸들
//	WNDCLASSEX WndClass;
//	MSG Message;
//
//	g_hInst = hInstance;
//
//	WndClass.cbSize = sizeof(WNDCLASSEX);
//	WndClass.cbClsExtra = 0;										// 클래스와 윈도우를 위한 여분의 메모리 크기 
//	WndClass.cbWndExtra = 0;										//	``
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 윈도우의 배경색
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// 기본 커서
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// 기본 아이콘
//	WndClass.hInstance = hInstance;									// 메인 함수에 첫번째 매개변수로 넘어온 인스턴스 값
//	WndClass.lpfnWndProc = WndProc;									// 메시지 처리에 사용될 함수의 이름 기재
//	WndClass.lpszClassName = lpszClass;								// 윈도우 클래스의 이름
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);				// 메뉴의 이름
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;						// 윈도우가 출력되는 형태
//	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//
//	RegisterClassEx(&WndClass);										// 커널에 윈도우 클래스 등록
//
//	hWnd = CreateWindow(		// 윈도우 생성 함수, 보여주지는 않음, false가 뜰경우 종료
//		lpszClass,				// 윈도우 클래스 이름
//		lpszClass,				// 윈도우 타이틀 이름
//		WS_OVERLAPPEDWINDOW,	// 윈도우 스타일
//		CW_USEDEFAULT,			// 윈도우 위치 X좌표
//		CW_USEDEFAULT,			// 윈도우 위치 Y좌표
//		CW_USEDEFAULT,			// 윈도우 가로 크기
//		CW_USEDEFAULT,			// 윈도우 세로 크기
//		NULL,					// 부모 윈도우 핸들
//		(HMENU)NULL,			// 메뉴 핸들
//		hInstance,				// 응용프로그램 인스턴스
//		NULL					// 생성 윈도우 정보
//		);
//
//	ShowWindow(hWnd, nCmdShow); // 윈도우를 화면에 보여줌
//
//	while (GetMessage(&Message, NULL, 0, 0)) { // 메세지 받아오기
//		TranslateMessage(&Message);
//		DispatchMessage(&Message);
//	}
//
//	return (int)Message.wParam;
//}
//
//#include <math.h>
//#define BSIZE 20
//double LengthPts(int x1, int y1, int x2, int y2)
//{
//	return(sqrt((float)((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))));
//}
//
//BOOL InCircle(int x, int y, int mx, int my)
//{
//	if (LengthPts(x, y, mx, my) < BSIZE) return TRUE;
//	else return FALSE;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//	static HMENU hMenu, hSubMenu;
//	int mx, my;
//	static bool Select;
//	static bool Copy;
//	static int xy[10][2] = {0,};
//	static int x, y;
//	static int max;
//
//	bool sw = false;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		hMenu = GetMenu(hwnd);
//		hSubMenu = GetSubMenu(hMenu, 1);
//		Select = FALSE;
//		Copy = FALSE;
//		xy[0][0] = 50;	xy[0][1] = 50;
//		max = 1;
//
//		EnableMenuItem(hMenu, ID_EDITCOPY, MF_GRAYED);
//		EnableMenuItem(hMenu, ID_EDITPASTE, MF_GRAYED);
//
//		return 0;
//	case WM_PAINT:
//		EnableMenuItem(hMenu, ID_EDITCOPY,
//			Select ? MF_ENABLED : MF_GRAYED);
//		EnableMenuItem(hMenu, ID_EDITPASTE,
//			Copy ? MF_ENABLED : MF_GRAYED);
//		hdc = BeginPaint(hwnd, &ps);
//		if (Select)
//			Rectangle(hdc, x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);
//
//		for (int i = 0; i < max;i++) {
//			Ellipse(hdc, xy[i][0] - BSIZE, xy[i][1] - BSIZE, xy[i][0] + BSIZE, xy[i][1] + BSIZE);
//		}
//		EndPaint(hwnd, &ps);
//		return 0;
//	case WM_COMMAND:
//		if (LOWORD(wParam) == ID_EDITCOPY)
//		{
//			Copy = true;
//			InvalidateRgn(hwnd, NULL, TRUE);
//		}
//		if (LOWORD(wParam) == ID_EDITPASTE && max<=10) {
//			xy[max][0] = xy[max - 1][0] + 50;
//			xy[max][1] = xy[max - 1][1] + 50;
//			max++;
//			InvalidateRgn(hwnd, NULL, TRUE);
//		}
//		if (LOWORD(wParam) == ID_CANCLE) {
//			Select = false;
//			Copy = false;
//			InvalidateRgn(hwnd, NULL, TRUE);
//		}
//		break;
//	case WM_LBUTTONDOWN:
//		mx = LOWORD(lParam);
//		my = HIWORD(lParam);
//
//		for (int i = 0; i < max; i++) {
//			if (InCircle(xy[i][0], xy[i][1], mx, my)) {
//				Select = true;
//				x = xy[i][0];
//				y = xy[i][1];
//				break;
//				sw = true;
//			}
//		}
//
//		InvalidateRgn(hwnd, NULL, TRUE);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

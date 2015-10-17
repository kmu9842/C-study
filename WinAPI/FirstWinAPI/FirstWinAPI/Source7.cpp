//#include <windows.h>
//#include <math.h>
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
//	WndClass.lpszMenuName = lpszClass;								// 메뉴의 이름
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
//// 메세지 처리 함수
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
//	HDC hdc;
//	PAINTSTRUCT ps;
//
//	RECT lp = { 0,0,0,0 };
//
//	static int x2 = 20, y2 = 20;
//	static int x = 60, y = 20, mx, my;
//	static int sw = 0;
//	static int sw2 = 0;
//	static int sw3 = 0;
//	static int sw4 = 0;
//
//	HPEN pens1, pens2;
//
//	switch (iMessage) {
//	case WM_CREATE:	// 생성 이벤트시 호출
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//
//		pens1 = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
//		pens2 = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
//
//		if (sw2 == 0) {
//			SelectObject(hdc, pens1);
//		}
//		if (sw2 == 1) {
//			SelectObject(hdc, pens2);
//		}
//
//		Ellipse(hdc, x, y, x + 40, y + 40);			// 원 그리기
//
//		if (sw2 == 0) {
//			SelectObject(hdc, pens2);
//		}
//		if (sw2 == 1) {
//			SelectObject(hdc, pens1);
//		}
//		Ellipse(hdc, x2, y2, x2 + 40, y2 + 40);			// 원 그리기
//
//		EndPaint(hWnd, &ps);
//		break;
//
//	case WM_SIZE:
//
//		break;
//
//	case WM_KEYDOWN:
//		if (wParam == VK_RETURN) {
//			switch (sw) {
//			case 0:
//				sw = 1;
//				sw3 = 1;
//				SetTimer(hWnd,1,0.1f,NULL);
//				break;
//			case 1:
//				sw = 0;
//				sw3 = 1;
//				SetTimer(hWnd, 1, 0.1f, NULL);
//				break;
//			}
//		}
//
//		else if (wParam == VK_RIGHT) {
//			if (sw2 != 0) {
//				switch (sw) {
//				case 1: sw = 3; break;
//				case 2: sw = 4; break;
//				case 3: sw = 1; break;
//				case 4: sw = 2; break;
//				}
//
//				switch (sw3) {
//				case 1: sw3 = 3; break;
//				case 2: sw3 = 4; break;
//				case 3: sw3 = 1; break;
//				case 4: sw3 = 2; break;
//				}
//			}
//			sw2 = 0;
//		}
//		else if (wParam == VK_LEFT) {
//			if (sw2 != 1) {
//				switch (sw) {
//				case 1: sw = 3; break;
//				case 2: sw = 4; break;
//				case 3: sw = 1; break;
//				case 4: sw = 2; break;
//				}
//
//				switch (sw3) {
//				case 1: sw3 = 3; break;
//				case 2: sw3 = 4; break;
//				case 3: sw3 = 1; break;
//				case 4: sw3 = 2; break;
//				}
//			}
//			sw2 = 1;
//		}
//
//		break;
//
//	case WM_TIMER:
//		
//		if (sw2 == 0) {
//			switch (sw) {
//			case 0:
//				break;
//			case 1:
//				GetClientRect(hWnd, &lp);
//				if (x + 40 <= lp.right) {
//					x += 4;
//				}
//				else {
//					sw = 2;
//				}
//				break;
//			case 2:
//				GetClientRect(hWnd, &lp);
//				if (y + 40 <= lp.bottom) {
//					y += 4;
//				}
//				else {
//					sw = 3;
//				}
//				break;
//			case 3:
//				GetClientRect(hWnd, &lp);
//				if (x - 4 >= lp.left) {
//					x -= 4;
//				}
//				else {
//					sw = 4;
//				}
//				break;
//			case 4:
//				GetClientRect(hWnd, &lp);
//				if (y - 4 >= lp.top) {
//					y -= 4;
//
//				}
//				else {
//					sw = 1;
//				}
//				break;
//			default:
//				break;
//			}
//
//			switch (sw3) {
//			case 0:
//				break;
//			case 1:
//				GetClientRect(hWnd, &lp);
//				if (x2 + 40 <= lp.right) {
//					x2 += 4;
//				}
//				else {
//					sw3 = 2;
//				}
//				break;
//			case 2:
//				GetClientRect(hWnd, &lp);
//				if (y2 + 40 <= lp.bottom) {
//					y2 += 4;
//				}
//				else {
//					sw3 = 3;
//				}
//				break;
//			case 3:
//				GetClientRect(hWnd, &lp);
//				if (x2 - 4 >= lp.left) {
//					x2 -= 4;
//				}
//				else {
//					sw3 = 4;
//				}
//				break;
//			case 4:
//				GetClientRect(hWnd, &lp);
//				if (y2 - 4 >= lp.top) {
//					y2 -= 4;
//
//				}
//				else {
//					sw3 = 1;
//				}
//				break;
//			default:
//				break;
//			}
//		}
//
//		else if (sw2 == 1) {
//			switch (sw) {
//			case 0:
//				break;
//			case 1:
//				GetClientRect(hWnd, &lp);
//				if (x + 40 <= lp.right) {
//					x += 4;
//
//				}
//				else {
//					sw = 4;
//				}
//				break;
//			case 2:
//				GetClientRect(hWnd, &lp);
//				if (y + 40 <= lp.bottom) {
//					y += 4;
//
//				}
//				else {
//					sw = 1;
//				}
//				break;
//			case 3:
//				GetClientRect(hWnd, &lp);
//				if (x - 4 >= lp.left) {
//					x -= 4;
//				}
//				else {
//					sw = 2;
//				}
//				break;
//			case 4:
//				GetClientRect(hWnd, &lp);
//				if (y - 4 >= lp.top) {
//					y -= 4;
//
//				}
//				else {
//					sw = 3;
//				}
//				break;
//			default:
//				break;
//			}
//			switch (sw3) {
//			case 0:
//				break;
//			case 1:
//				GetClientRect(hWnd, &lp);
//				if (x2 + 40 <= lp.right) {
//					x2 += 4;
//
//				}
//				else {
//					sw3 = 4;
//				}
//				break;
//			case 2:
//				GetClientRect(hWnd, &lp);
//				if (y2 + 40 <= lp.bottom) {
//					y2 += 4;
//
//				}
//				else {
//					sw3 = 1;
//				}
//				break;
//			case 3:
//				GetClientRect(hWnd, &lp);
//				if (x2 - 4 >= lp.left) {
//					x2 -= 4;
//				}
//				else {
//					sw3 = 2;
//				}
//				break;
//			case 4:
//				GetClientRect(hWnd, &lp);
//				if (y2 - 4 >= lp.top) {
//					y2 -= 4;
//
//				}
//				else {
//					sw3 = 3;
//				}
//				break;
//			default:
//				break;
//			}
//		}
//		
//		InvalidateRgn(hWnd, NULL, true);
//
//		break;
//
//	case WM_LBUTTONDOWN:
//		break;
//
//	case WM_LBUTTONUP:
//		break;
//
//	case WM_MOUSEMOVE:
//		break;
//
//	case WM_DESTROY:	// 종료 이벤트시 호출
//		PostQuitMessage(0); // 종료
//		return 0;
//	}
//
//	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
//}
//
//// 연습문제 4,6,9번

//#include <windows.h>
//#include <string>
//#include <time.h>
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
//	WNDCLASS WndClass;
//	MSG Message;
//
//	g_hInst = hInstance;
//
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;						// 윈도우가 출력되는 형태
//	WndClass.lpfnWndProc = WndProc;									// 메시지 처리에 사용될 함수의 이름 기재
//	WndClass.cbClsExtra = 0;										// 클래스와 윈도우를 위한 여분의 메모리 크기 
//	WndClass.cbWndExtra = 0;										//	``
//	WndClass.hInstance = hInstance;									// 메인 함수에 첫번째 매개변수로 넘어온 인스턴스 값
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// 기본 아이콘
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// 기본 커서
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 윈도우의 배경색
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);				// 메뉴의 이름
//	WndClass.lpszClassName = lpszClass;								// 윈도우 클래스의 이름
//
//	RegisterClass(&WndClass);										// 커널에 윈도우 클래스 등록
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
//	);
//								
//
//	ShowWindow(hWnd, nCmdShow); // 윈도우를 화면에 보여줌
//	UpdateWindow(hWnd);
//
//	while (GetMessage(&Message, NULL, 0, 0)) { // 메세지 받아오기
//		TranslateMessage(&Message);
//		DispatchMessage(&Message);
//	}
//
//	return (int)Message.wParam;
//}
//
//
//POINT board[5][5];
//int Partition;
//int width, height;
//int blankX, blankY;
//int count;
//bool start;
//int diX, diY;
//int oldX, oldY, SelectX, SelectY;
//POINT point;
//HBITMAP hBitmap, Bitmap;
//
//void NewGame(HWND hwnd)
//{
//	int i, j;
//	srand((unsigned int)time(NULL) / 2);
//
//	for (i = 0; i < Partition; i++) {
//		for (j = 0; j < Partition; j++) {
//			int x, y, k, l, exist;
//			exist = 1;
//			while (exist)
//			{
//				x = rand() % Partition;
//				y = rand() % Partition;
//				exist = 0;
//				for (k = 0; k < i; k++)
//					for (l = 0; l < Partition; l++)
//						if (x == board[k][l].x && y == board[k][l].y) exist = 1;
//				for (l = 0; l < j; l++)
//					if (x == board[k][l].x && y == board[k][l].y) exist = 1;
//			}
//			board[i][j].x = x;
//			board[i][j].y = y;
//			if (x == Partition - 1 && y == Partition - 1) {
//				blankX = i;
//				blankY = j;
//			}
//		}
//	}
//
//	board[blankX][blankY].x = board[blankX][blankY].y = -1;
//	InvalidateRgn(hwnd, NULL, TRUE);
//	start = true;
//	count = -1;
//}
//
//void BlockMoving(HWND hwnd) {
//	HDC hdc, memdc, deletedc;
//
//	count++;
//	if (count == 10) {
//		board[blankX][blankY] = board[SelectX][SelectY];
//		blankX = SelectX;
//		blankY = SelectY;
//		board[blankX][blankY].x = board[blankX][blankY].y = -1;
//		KillTimer(hwnd, 1);
//		InvalidateRgn(hwnd, NULL, TRUE);
//		count = -1;
//		return;
//	}
//
//	hdc = GetDC(hwnd);
//
//	memdc = CreateCompatibleDC(hdc);
//	SelectObject(memdc, hBitmap);
//	deletedc = CreateCompatibleDC(hdc);
//	SelectObject(deletedc, Bitmap);
//	BitBlt(hdc, oldX, oldY, width, height, deletedc, 0, 0, SRCCOPY);
//	oldX = oldX + (diX / 10);
//	oldY = oldY + (diY / 10);
//	BitBlt(hdc, oldX, oldY, width, height, memdc, point.x*width, point.y*height, SRCCOPY);
//
//	DeleteDC(deletedc);
//	DeleteDC(memdc);
//
//	ReleaseDC(hwnd, hdc);
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	HDC         hdc, memdc;
//	PAINTSTRUCT ps;
//	int i, j;
//	switch (iMsg)
//	{
//	case WM_CREATE:
//
//		Partition = 5;
//		width = (int)819 / Partition;
//		height = (int)614 / Partition;
//		hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
//		Bitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
//		NewGame(hwnd);
//
//		return 0;
//	case WM_SIZE:
//		break;
//
//	case WM_PAINT:
//
//		hdc = BeginPaint(hwnd, &ps);
//		memdc = CreateCompatibleDC(hdc);
//		SelectObject(memdc, hBitmap);
//
//		for (i = 0; i < Partition; i++) {
//			for (j = 0; j < Partition; j++) {
//				if (board[i][j].x != -1 && board[i][j].y != -1) {
//					BitBlt(hdc, i*width, j*height, width, height, memdc, board[i][j].x*width, board[i][j].y*height, SRCCOPY);
//				}
//			}
//		}
//
//		DeleteDC(memdc);
//		EndPaint(hwnd, &ps);
//
//		break;
//
//	case WM_LBUTTONDOWN:
//
//		if (!start || LOWORD(lParam)>819 || HIWORD(lParam)>614 || count > -1) { break; }
//		SelectX = LOWORD(lParam) / width;
//		SelectY = HIWORD(lParam) / height;
//		diX = (blankX - SelectX)*width;
//		diY = (blankY - SelectY)*height;
//		if ((abs(diX) == width || abs(diY) == height) && (abs(diX) == 0 || abs(diY) == 0)) {
//			count = -1;
//			oldX = SelectX*width;
//			oldY = SelectY*height;
//			point.x = board[SelectX][SelectY].x;
//			point.y = board[SelectX][SelectY].y;
//			SetTimer(hwnd, 1, 5, NULL);
//		}
//
//		break;
//	case WM_COMMAND:
//		switch (LOWORD(wParam)) {
//		case ID_40001:
//			if (start) { break; }
//			NewGame(hwnd);
//
//			break;
//		case ID_40002:
//
//			DeleteObject(hBitmap);
//			DeleteObject(Bitmap);
//			PostQuitMessage(0);
//
//			break;
//		case ID_40003:
//
//			for (i = 0; i < Partition; i++) {
//				for (j = 0; j < Partition; j++) {
//					board[i][j].x = i;
//					board[i][j].y = j;
//				}
//			}
//
//			start = false;
//			InvalidateRgn(hwnd, NULL, TRUE);
//
//			break;
//		case ID_40004:
//
//			Partition = 3;
//			width = (int)819 / Partition;
//			height = (int)614 / Partition;
//			NewGame(hwnd);
//			break;
//
//		case ID_40005:
//
//			Partition = 4;
//
//			width = (int)819 / Partition;
//			height = (int)614 / Partition;
//
//			NewGame(hwnd);
//			break;
//
//		case ID_40006:
//
//			Partition = 5;
//
//			width = (int)819 / Partition;
//			height = (int)614 / Partition;
//
//			NewGame(hwnd);
//			break;
//
//		default:
//			break;
//		}
//		break;
//	case WM_TIMER:
//
//		BlockMoving(hwnd);
//		break;
//
//	case WM_DESTROY:
//
//		DeleteObject(hBitmap);
//		DeleteObject(Bitmap);
//		PostQuitMessage(0);
//		return 0;
//	}
//
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
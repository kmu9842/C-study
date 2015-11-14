//#include <windows.h>
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);								// 메뉴의 이름
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
//enum {
//	PEN = 1, BRUSH, LINE = 1, ELLIPSE = 2, RECTANGLE = 3
//};
//
//class OBJECTS
//{
//public :
//	int startX;
//	int startY;
//	int endX;
//	int endY;
//	int kind;
//
//	COLORREF PenColor;
//	COLORREF BrushColor;
//
//	void DrawAllObjects(HDC hdc);
//};
//
//OBJECTS inform[200];
//int count;
//
//void OBJECTS::DrawAllObjects(HDC hdc) {
//
//	HPEN hPen, oldPen;
//	HBRUSH hBrush, oldBrush;
//
//	SetROP2(hdc, R2_XORPEN);
//	hPen = CreatePen(PS_SOLID, 1, this->PenColor);
//	hBrush = CreateSolidBrush(this->BrushColor);
//	oldPen = (HPEN)SelectObject(hdc, hPen);
//	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
//	switch (this->kind)
//	{
//	case LINE:
//		MoveToEx(hdc, this->startX, this->startY, NULL);
//		LineTo(hdc, this->endX, this->endY);
//		break;
//	case ELLIPSE:
//		Ellipse(hdc, this->startX, this->startY, this->endX, this->endY);
//		break;
//	case RECTANGLE:
//		Rectangle(hdc, this->startX, this->startY, this->endX, this->endY);
//		break;
//	}
//	SelectObject(hdc, oldPen);
//	SelectObject(hdc, oldBrush);
//	DeleteObject(hPen);
//	DeleteObject(hBrush);
//	
//
//}
//
//COLORREF ColorSelection(HWND hwnd, int kind)
//{
//	COLORREF tmp[16], Color;
//	CHOOSECOLOR COLOR;
//	for (int i = 0; i<16; i++)
//		tmp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
//	memset(&COLOR, 0, sizeof(CHOOSECOLOR));
//	COLOR.lStructSize = sizeof(CHOOSECOLOR);
//	COLOR.hwndOwner = hwnd;
//	COLOR.lpCustColors = tmp;
//	COLOR.Flags = CC_FULLOPEN;
//	if (ChooseColor(&COLOR) != 0) {
//		Color = COLOR.rgbResult;
//		return RGB(GetRValue(Color) ^ 255, GetGValue(Color) ^ 255, GetBValue(Color) ^ 255);
//	}
//	else {
//		switch (kind) {
//		case PEN:
//			return RGB(255, 255, 255);
//			break;
//		case BRUSH:
//			return RGB(0, 0, 0);
//			break;
//		}
//	}
//}
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//
//	static HPEN hPen, oldPen;
//	static HBRUSH hBrush, oldBrush;
//	static int object_mode, color_mode, startX, startY, oldX, oldY;
//	static BOOL Drag;
//	static COLORREF PenColor, BrushColor;
//
//	HBITMAP hBitmap;
//
//	int endX, endY;
//
//	switch (iMsg) {
//	case WM_CREATE:
//		object_mode = 0;
//		color_mode = 0;
//		Drag = FALSE;
//		count = 0;
//		hPen = (HPEN)GetStockObject(WHITE_PEN);
//		hBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
//		PenColor = RGB(255, 255, 255);
//		BrushColor = RGB(0, 0, 0);
//		hBitmap = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstacne, MAKEINTRESOURCE(IDB_BITMAP1));
//
//		break;
//
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		for (int i = 0; i < count; i++) {
//			inform[i].DrawAllObjects(hdc);
//		}
//		EndPaint(hWnd, &ps);
//		break;
//
//	case WM_LBUTTONDOWN:
//		startX = oldX = LOWORD(lParam);
//		startY = oldY = HIWORD(lParam);
//		Drag = TRUE;
//		break;
//
//	case WM_LBUTTONUP:
//		Drag = FALSE;
//		inform[count].startX = startX;
//		inform[count].startY = startY;
//		inform[count].endX = oldX;
//		inform[count].endY = oldY;
//		inform[count].kind = object_mode;
//		inform[count].PenColor = PenColor;
//		inform[count].BrushColor = BrushColor;
//		count++;
//		break;
//
//	case WM_MOUSEMOVE:
//		hdc = GetDC(hWnd);
//		if (Drag)
//		{
//			SetROP2(hdc, R2_XORPEN);
//			oldPen = (HPEN)SelectObject(hdc, hPen);
//			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
//			endX = LOWORD(lParam);
//			endY = HIWORD(lParam);
//			switch (object_mode)
//			{
//			case LINE:
//				MoveToEx(hdc, startX, startY, NULL);
//				LineTo(hdc, oldX, oldY);
//				MoveToEx(hdc, startX, startY, NULL);
//				LineTo(hdc, endX, endY);
//				break;
//			case ELLIPSE:
//				Ellipse(hdc, startX, startY, oldX, oldY);
//				Ellipse(hdc, startX, startY, endX, endY);
//				break;
//			case RECTANGLE:
//				Rectangle(hdc, startX, startY, oldX, oldY);
//				Rectangle(hdc, startX, startY, endX, endY);
//				break;
//			}
//			oldX = endX; oldY = endY;
//			SelectObject(hdc, oldPen);
//			SelectObject(hdc, oldBrush);
//		}
//		ReleaseDC(hWnd, hdc);
//		break;
//	case WM_COMMAND:
//		switch (LOWORD(wParam))
//		{
//		case ID_LINE:
//			object_mode = LINE;
//			break;
//		case ID_YEE_B:
//			object_mode = ELLIPSE;
//			break;
//		case ID_YEE_C:
//			object_mode = RECTANGLE;
//			break;
//		case ID_YEE_D:
//			color_mode = PEN;
//			PenColor = ColorSelection(hWnd, color_mode);
//			hPen = CreatePen(PS_SOLID, 1, PenColor);
//			break;
//		case ID_YEE_E:
//			color_mode = BRUSH;
//			BrushColor = ColorSelection(hWnd, color_mode);
//			hBrush = CreateSolidBrush(BrushColor);
//			break;
//		}
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return DefWindowProc(hWnd, iMsg, wParam, lParam);
//}
//#include <windows.h>
//#include <string>
//
//#include "resource.h"
//
//// �̺�Ʈ �帮�� ��� = �̺�Ʈ ��� ���
//// �޼��� �帮�� ��� = �޼��� ��� ���
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // ����ڿ� �ý����� �������� �޽����� ó���ϴ� ����
//													  // WndProc�� WinMain�Ѵ� �ʼ� �Լ�
//													  // WinMain�� �����츦 ����� ǥ���ϱ⸸ �һ� ��κ��� ���� WndProc���� �̷����
//
//HINSTANCE g_hInst;
//LPCTSTR lpszClass = TEXT("First");	// ������ Ŭ������ �����ϴµ� ����
//
//									// APIENTRY�� ���������� ǥ�� ȣ�� �Ծ� _stdcall�� ����Ѵٴ� ��.
//									// WinMain�� �Ű� ���� 
//									// hInstance ���α׷��� �ν��Ͻ� �ڵ�
//									// hPrevInstance �ٷ� �տ� ����� ���� ���α׷��� �ν��Ͻ� �ڵ��̴�. ���� ��� NULL�� �Ǹ� Win32������ �׻� NULL�̴�. 16��Ʈ�� �����ϱ� ���� �μ�
//									// lpszCmdParam ��������� �Էµ� ���α׷� �μ�. ������ argv�μ��� �ش��ϸ� ���� ���� �������� ��ΰ� ���޵ȴ�.
//									// nCmdShow ���α׷��� ����� �����̸� �ּ�ȭ, ���� ��� ���� ���޵ȴ�.
//
//									// �ν��Ͻ���� ���� �������� ���α׷� �ϳ��� Ī�ϴ� ����̴�. 
//									// ���α׷� ���ο��� �ڽ��� ����Ű�� 1��Ī ���� ������
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
//
//	HWND hWnd; // ������ �ڵ�
//	WNDCLASSEX WndClass;
//	MSG Message;
//
//	g_hInst = hInstance;
//
//	WndClass.cbSize = sizeof(WNDCLASSEX);
//	WndClass.cbClsExtra = 0;										// Ŭ������ �����츦 ���� ������ �޸� ũ�� 
//	WndClass.cbWndExtra = 0;										//	``
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �������� ����
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// �⺻ Ŀ��
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �⺻ ������
//	WndClass.hInstance = hInstance;									// ���� �Լ��� ù��° �Ű������� �Ѿ�� �ν��Ͻ� ��
//	WndClass.lpfnWndProc = WndProc;									// �޽��� ó���� ���� �Լ��� �̸� ����
//	WndClass.lpszClassName = lpszClass;								// ������ Ŭ������ �̸�
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);								// �޴��� �̸�
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;						// �����찡 ��µǴ� ����
//	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//
//	RegisterClassEx(&WndClass);										// Ŀ�ο� ������ Ŭ���� ���
//
//	hWnd = CreateWindow(		// ������ ���� �Լ�, ���������� ����, false�� ���� ����
//		lpszClass,				// ������ Ŭ���� �̸�
//		lpszClass,				// ������ Ÿ��Ʋ �̸�
//		WS_OVERLAPPEDWINDOW,	// ������ ��Ÿ��
//		CW_USEDEFAULT,			// ������ ��ġ X��ǥ
//		CW_USEDEFAULT,			// ������ ��ġ Y��ǥ
//		CW_USEDEFAULT,			// ������ ���� ũ��
//		CW_USEDEFAULT,			// ������ ���� ũ��
//		NULL,					// �θ� ������ �ڵ�
//		(HMENU)NULL,			// �޴� �ڵ�
//		hInstance,				// �������α׷� �ν��Ͻ�
//		NULL					// ���� ������ ����
//		);
//
//	ShowWindow(hWnd, nCmdShow); // �����츦 ȭ�鿡 ������
//
//	while (GetMessage(&Message, NULL, 0, 0)) { // �޼��� �޾ƿ���
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
//COLORREF ColorSelection(HWND hWnd, int kind) {
//	int i;
//	COLORREF tmp[16], Color;
//	CHOOSECOLOR COLOR;
//	for (i = 0; i < 16; i++) {
//		tmp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
//	}
//	memset(&COLOR, 0, sizeof(CHOOSECOLOR));
//	COLOR.lStructSize = sizeof(CHOOSECOLOR);
//	COLOR.hwndOwner = hWnd;
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
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
//	HDC hdc;
//	PAINTSTRUCT ps;
//
//	static HPEN hPen, oldPen;
//	static HBRUSH hBrush, oldBrush;
//	static int object_mode, color_mode, startX, startY, oldX, oldY;
//	static BOOL Drag;
//
//	int endX, endY;
//
//	switch (iMsg) {
//	case WM_CREATE:
//		object_mode = 0;
//		color_mode = 0;
//		Drag = FALSE;
//		hPen = (HPEN)GetStockObject(WHITE_PEN);
//		hBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
//		break;
//
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
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
//		break;
//
//	case WM_MOUSEMOVE:
//		hdc = GetDC(hWnd);
//		if (Drag) {
//			SetROP2(hdc, R2_XORPEN);
//			oldPen = (HPEN)SelectObject(hdc, hPen);
//			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
//			endX = LOWORD(lParam);
//			endY = HIWORD(lParam);
//			switch (object_mode){
//			case LINE:
//				MoveToEx(hdc, startX, startY, NULL);
//				LineTo(hdc, oldX, oldY);
//				MoveToEx(hdc, startX, startY, NULL);
//				LineTo(hdc, endX, endY);
//				break;
//
//			case ELLIPSE:
//				Ellipse(hdc, startX, startY, oldX, oldY);
//				Ellipse(hdc, startX, startY, endX, endY);
//				break;
//
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
//
//	case WM_COMMAND:
//		switch (LOWORD(wParam)){
//		case ID_LINE:
//			object_mode = LINE;
//			break;
//		case ID_ELLIPSE:
//			object_mode = ELLIPSE;
//			break;
//		case ID_RECTANGLE:
//			object_mode = RECTANGLE;
//			break;
//		case ID_PENCOLOR:
//			color_mode = PEN;
//			hPen = CreatePen(PS_SOLID, 1, ColorSelection(hWnd, color_mode));
//			break;
//		case ID_FACECOLOR:
//			color_mode = BRUSH;
//			hBrush = CreateSolidBrush(ColorSelection(hWnd, color_mode));
//			break;
//		}
//		break;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//
//	return DefWindowProc(hWnd, iMsg, wParam, lParam);
//}
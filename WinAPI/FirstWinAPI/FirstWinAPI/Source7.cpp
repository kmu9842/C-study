//#include <windows.h>
//#include <math.h>
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
//	WndClass.lpszMenuName = lpszClass;								// �޴��� �̸�
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
//// �޼��� ó�� �Լ�
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
//	case WM_CREATE:	// ���� �̺�Ʈ�� ȣ��
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
//		Ellipse(hdc, x, y, x + 40, y + 40);			// �� �׸���
//
//		if (sw2 == 0) {
//			SelectObject(hdc, pens2);
//		}
//		if (sw2 == 1) {
//			SelectObject(hdc, pens1);
//		}
//		Ellipse(hdc, x2, y2, x2 + 40, y2 + 40);			// �� �׸���
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
//	case WM_DESTROY:	// ���� �̺�Ʈ�� ȣ��
//		PostQuitMessage(0); // ����
//		return 0;
//	}
//
//	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
//}
//
//// �������� 4,6,9��

//#include <windows.h>
//#include <math.h>
//
//// �̺�Ʈ �帮�� ��� = �̺�Ʈ ��� ���
//// �޼��� �帮�� ��� = �޼��� ��� ���
//
//
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
//	static RECT rt = { 0, 0, 50, 75 };
//	static RECT rt2 = { 0, 0, 50, 50 };
//
//	static int x = 40, y = 40, mx, my;
//	static int sw = 0, sw2 = 0;
//
//	HPEN pens;
//	HBRUSH brush;
//
//	switch (iMessage) {
//	case WM_CREATE:	// ���� �̺�Ʈ�� ȣ��
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//
//		if (sw2==1){
//			DrawTextA(hdc, "��", 2, &rt2, DT_CENTER | DT_WORDBREAK);
//		}
//		DrawTextA(hdc, "�����", 6, &rt, DT_CENTER | DT_WORDBREAK);
//
//		EndPaint(hWnd, &ps);
//		break;
//
//	case WM_SIZE:
//		break;
//
//	case WM_KEYDOWN:
//		break;
//
//	case WM_TIMER:
//
//		if (x > mx) {
//			x-=2;
//		}
//		if (x < mx) {
//			x+=2;
//		}
//
//		if (y < my) {
//			y+=2;
//		}
//		if (y > my) {
//			y-=2;
//		}
//		rt.left = x - 25;
//		rt.right = x + 25;
//		rt.top = y - 25;
//		rt.bottom = y + 25;
//
//		InvalidateRgn(hWnd, NULL, true);
//		break;
//
//	case WM_LBUTTONDOWN:
//		sw2 = 1;
//		SetTimer(hWnd, 1, 0.1f, NULL);
//
//		mx = LOWORD(lParam);
//		my = HIWORD(lParam);
//
//		rt2.left = mx - 25;
//		rt2.right = mx + 25;
//		rt2.top = my - 25;
//		rt2.bottom = my + 25;
//
//		InvalidateRgn(hWnd, NULL, true);
//		break;
//
//	case WM_LBUTTONUP:
//		sw2 = 0;
//		KillTimer(hWnd,1);
//		InvalidateRgn(hWnd, NULL, true);
//		break;
//
//	case WM_MOUSEMOVE:
//
//		mx = LOWORD(lParam);
//		my = HIWORD(lParam);
//
//		rt2.left = mx - 25;
//		rt2.right = mx + 25;
//		rt2.top = my - 25;
//		rt2.bottom = my + 25;
//
//		InvalidateRgn(hWnd, NULL, true);
//
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

/*#include <windows.h>

int flag[4] = { 0, };

// �̺�Ʈ �帮�� ��� = �̺�Ʈ ��� ���
// �޼��� �帮�� ��� = �޼��� ��� ���

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // ����ڿ� �ý����� �������� �޽����� ó���ϴ� ����
													  // WndProc�� WinMain�Ѵ� �ʼ� �Լ�
													  // WinMain�� �����츦 ����� ǥ���ϱ⸸ �һ� ��κ��� ���� WndProc���� �̷����

HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First");	// ������ Ŭ������ �����ϴµ� ����

									// APIENTRY�� ���������� ǥ�� ȣ�� �Ծ� _stdcall�� ����Ѵٴ� ��.
									// WinMain�� �Ű� ����
									// hInstance ���α׷��� �ν��Ͻ� �ڵ�
									// hPrevInstance �ٷ� �տ� ����� ���� ���α׷��� �ν��Ͻ� �ڵ��̴�. ���� ��� NULL�� �Ǹ� Win32������ �׻� NULL�̴�. 16��Ʈ�� �����ϱ� ���� �μ�
									// lpszCmdParam ��������� �Էµ� ���α׷� �μ�. ������ argv�μ��� �ش��ϸ� ���� ���� �������� ��ΰ� ���޵ȴ�.
									// nCmdShow ���α׷��� ����� �����̸� �ּ�ȭ, ���� ��� ���� ���޵ȴ�.

									// �ν��Ͻ���� ���� �������� ���α׷� �ϳ��� Ī�ϴ� ����̴�.
									// ���α׷� ���ο��� �ڽ��� ����Ű�� 1��Ī ���� ������
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {

	HWND hWnd; // ������ �ڵ�
	WNDCLASSEX WndClass;
	MSG Message;

	g_hInst = hInstance;

	WndClass.cbSize = sizeof(WNDCLASSEX);
	WndClass.cbClsExtra = 0;										// Ŭ������ �����츦 ���� ������ �޸� ũ��
	WndClass.cbWndExtra = 0;										//	``
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �������� ����
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// �⺻ Ŀ��
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �⺻ ������
	WndClass.hInstance = hInstance;									// ���� �Լ��� ù��° �Ű������� �Ѿ�� �ν��Ͻ� ��
	WndClass.lpfnWndProc = WndProc;									// �޽��� ó���� ���� �Լ��� �̸� ����
	WndClass.lpszClassName = lpszClass;								// ������ Ŭ������ �̸�
	WndClass.lpszMenuName = lpszClass;								// �޴��� �̸�
	WndClass.style = CS_HREDRAW | CS_VREDRAW;						// �����찡 ��µǴ� ����
	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&WndClass);										// Ŀ�ο� ������ Ŭ���� ���

	hWnd = CreateWindow(		// ������ ���� �Լ�, ���������� ����, false�� ���� ����
		lpszClass,				// ������ Ŭ���� �̸�
		lpszClass,				// ������ Ÿ��Ʋ �̸�
		WS_OVERLAPPEDWINDOW,	// ������ ��Ÿ��
		CW_USEDEFAULT,			// ������ ��ġ X��ǥ
		CW_USEDEFAULT,			// ������ ��ġ Y��ǥ
		CW_USEDEFAULT,			// ������ ���� ũ��
		CW_USEDEFAULT,			// ������ ���� ũ��
		NULL,					// �θ� ������ �ڵ�
		(HMENU)NULL,			// �޴� �ڵ�
		hInstance,				// �������α׷� �ν��Ͻ�
		NULL					// ���� ������ ����
		);

	ShowWindow(hWnd, nCmdShow); // �����츦 ȭ�鿡 ������

	while (GetMessage(&Message, NULL, 0, 0)) { // �޼��� �޾ƿ���
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return (int)Message.wParam;
}

// �޼��� ó�� �Լ�
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;

	HBRUSH MyBrush1, MyBrush2;
	RECT rt[4] = { {0, 290, 100, 310},
	{ 200, 290, 300, 310 },
	{ 100, 90, 200, 110 },
	{ 100, 490, 200, 510 } };
	
	char a[4][10] = {"����","������","����","�Ʒ���"};

	//flag[2] = 1;

	switch (iMessage) {
	case WM_CREATE:	// ���� �̺�Ʈ�� ȣ��
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		MyBrush1 = CreateSolidBrush(RGB(255, 254, 255));	 // �귯�� ���� ����
		MyBrush2 = CreateSolidBrush(RGB(255, 0, 0));	 // �귯�� ���� ����

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

	case WM_DESTROY:	// ���� �̺�Ʈ�� ȣ��
		PostQuitMessage(0); // ����
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}*/
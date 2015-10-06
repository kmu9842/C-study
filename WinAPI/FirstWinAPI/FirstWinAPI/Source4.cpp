#include <windows.h>

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
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM IParam) {
	HDC hdc;
	PAINTSTRUCT ps;

	RECT lp = {0,0,0,0};

	static int x = 0, y = 0;

	switch (iMessage) {
	case WM_CREATE:	// ���� �̺�Ʈ�� ȣ��
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		Ellipse(hdc, x, y, x+100, y+100);			// �� �׸���

		EndPaint(hWnd, &ps);
		break;
	case WM_SIZE:
		switch (wParam) {
		case SIZE_RESTORED :
			GetClientRect(hWnd, &lp);
			if (x+100 >=lp.right) {
				x = lp.right-100;
			}
			else if (y+100 >= lp.bottom) {
				y = lp.bottom - 100;
			}
			break;
		}

		InvalidateRgn(hWnd, NULL, true);
		break;
	case WM_KEYDOWN:
		GetClientRect(hWnd, &lp);
		switch(wParam){
		case VK_RIGHT:
			if (x + 100 < lp.right) {
				x += 10;
			}
			break;
		case VK_LEFT:
			if (x > lp.left) {
				x -= 10;
			}
			break;
		case VK_DOWN:
			if (y + 100 < lp.bottom) {
				y += 10;
			}
			break;
		case VK_UP:
			if (y > lp.top) {
				y -= 10;
			}
			break;
		}

		InvalidateRgn(hWnd, NULL, true);
		break;
	case WM_DESTROY:	// ���� �̺�Ʈ�� ȣ��
		PostQuitMessage(0); // ����
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, IParam));
}
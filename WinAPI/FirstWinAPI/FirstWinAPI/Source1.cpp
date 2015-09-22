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

	int x = 0, y = 0;
	static int count = 0;
	static int cursorPos = 0;
	static int lastLSize = 0;
	static char str[200];

	POINT point[5] = { {200,20},{ 250,50 },{ 500,100 },{ 400,200 },{ 200,200 } };

	LPCSTR a;
	SIZE size;

	switch (iMessage) {
	case WM_CREATE:	// ���� �̺�Ʈ�� ȣ��
		CreateCaret(hWnd, NULL, 5, 15);
		ShowCaret(hWnd);
		count = 0;
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd,&ps);

		for (int i = 0;i<count;i++) {
			if (str[i] == '\n') {
				y+=20;
				x = 0;
				SetCaretPos(x, y);
			}
			else {
				a = &str[i];
				TextOutA(hdc, x, y, a, 1);
				GetTextExtentPointA(hdc,&str[i],1,&size);
				lastLSize = size.cx;
				x += size.cx;
				cursorPos++;
				SetCaretPos(x,y);
			}
		}

		if (count == 0) {
			x = 0;
			y = 0;
			SetCaretPos(x, y);
		}

		MoveToEx(hdc,100,100,NULL);
		LineTo(hdc,150,150);

		Ellipse(hdc,0,0,40,40);

		Rectangle(hdc,50,50,80,80);

		Polygon(hdc,point,5);

		EndPaint(hWnd,&ps);

		break;
	case WM_KEYDOWN :

		if (wParam == VK_BACK && count>0) {
			count--;
			cursorPos--;
		}

		else if (wParam == VK_RIGHT) {
			cursorPos++;
		}

		else if (wParam == VK_LEFT) {
			cursorPos--;
		}

		else if (wParam == VK_RETURN) {
			str[count++] = '\n';
			str[count] = '\0';
		}
		else {
			if (wParam != '\b') {
				str[count++] = wParam;
			}
			cursorPos++;
			str[count] = '\0';
		}

		// ȭ�� ���� ���� �Լ� (������ ������ ���Ե� �������� �ڵ鰪, ������ ������ ���� �ڵ鰪(NULL���� ��ü), ��� ���� ���� �������� �ʰ� �����Ǵ� �κи� �߰� ����)
		// WM_PAINT�� �ٽ� ȣ���ϴ°�
		InvalidateRgn(hWnd, NULL, true);

		break;

	case WM_CHAR :
		
		

		break;

	case WM_DESTROY:	// ���� �̺�Ʈ�� ȣ��
		PostQuitMessage(0); // ����
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, IParam));
}
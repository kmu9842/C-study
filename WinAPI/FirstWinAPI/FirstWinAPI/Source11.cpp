#include <windows.h>
#include <math.h>
#include <string>

#include "resource.h"

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
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);								// �޴��� �̸�
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int x, y, r1;
	static int mx, my;
	static int ex, ey;
	static bool selection;
	HBRUSH hBrush, oldBrush;

	int answer;

	switch (iMsg)
	{
	case WM_CREATE:
		x = 0;
		y = 0;
		r1 = 80;
		selection = FALSE;
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		if (selection == TRUE) {
			Rectangle(hdc, x, y, x + r1, y + r1);
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			Ellipse(hdc, x, y, x + r1, y + r1);
			SelectObject(hdc, oldBrush);
			DeleteObject(hBrush);
		}

		else
			Ellipse(hdc, x, y, x + r1, y + r1);

		EndPaint(hWnd, &ps);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_YEE_1:
			MessageBoxA(hWnd, "?", "?", MB_OKCANCEL);
			break;
		case ID_YEE_2:
			answer = MessageBoxA(hWnd, "??", "?", MB_YESNO);
			if (answer == IDNO) {
				PostQuitMessage(0); // ����
			}
			break;

		case ID_LOL:
			MessageBoxA(hWnd, "?", "?", MB_OKCANCEL);
			break;
		}

		break;
	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		if (x <= mx && (x + r1) >= mx  && y <= my && (y + r1) >= my) {
			selection = TRUE;
			ex = mx - x;
			ey = my - y;
			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;
	case WM_LBUTTONUP:
		selection = FALSE;
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_MOUSEMOVE:
		if (selection == TRUE) {
			x = LOWORD(lParam) - ex;
			y = HIWORD(lParam) - ey;
			InvalidateRgn(hWnd, NULL, TRUE);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}
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
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);				// �޴��� �̸�
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

#include <math.h>
#define BSIZE 20
double LengthPts(int x1, int y1, int x2, int y2)
{
	return(sqrt((float)((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))));
}

BOOL InCircle(int x, int y, int mx, int my)
{
	if (LengthPts(x, y, mx, my) < BSIZE) return TRUE;
	else return FALSE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static HMENU hMenu, hSubMenu;
	int mx, my;
	static bool Select;
	static bool Copy;
	static int xy[10][2] = {0,};
	static int x, y;
	static int max;

	bool sw = false;

	switch (iMsg)
	{
	case WM_CREATE:
		hMenu = GetMenu(hwnd);
		hSubMenu = GetSubMenu(hMenu, 1);
		Select = FALSE;
		Copy = FALSE;
		xy[0][0] = 50;	xy[0][1] = 50;
		max = 1;

		EnableMenuItem(hMenu, ID_EDITCOPY, MF_GRAYED);
		EnableMenuItem(hMenu, ID_EDITPASTE, MF_GRAYED);

		return 0;
	case WM_PAINT:
		EnableMenuItem(hMenu, ID_EDITCOPY,
			Select ? MF_ENABLED : MF_GRAYED);
		EnableMenuItem(hMenu, ID_EDITPASTE,
			Copy ? MF_ENABLED : MF_GRAYED);
		hdc = BeginPaint(hwnd, &ps);
		if (Select)
			Rectangle(hdc, x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);

		for (int i = 0; i < max;i++) {
			Ellipse(hdc, xy[i][0] - BSIZE, xy[i][1] - BSIZE, xy[i][0] + BSIZE, xy[i][1] + BSIZE);
		}
		EndPaint(hwnd, &ps);
		return 0;
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_EDITCOPY)
		{
			Copy = true;
			InvalidateRgn(hwnd, NULL, TRUE);
		}
		if (LOWORD(wParam) == ID_EDITPASTE && max<=10) {
			xy[max][0] = xy[max - 1][0] + 50;
			xy[max][1] = xy[max - 1][1] + 50;
			max++;
			InvalidateRgn(hwnd, NULL, TRUE);
		}
		if (LOWORD(wParam) == ID_CANCLE) {
			Select = false;
			Copy = false;
			InvalidateRgn(hwnd, NULL, TRUE);
		}
		break;
	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		for (int i = 0; i < max; i++) {
			if (InCircle(xy[i][0], xy[i][1], mx, my)) {
				Select = true;
				x = xy[i][0];
				y = xy[i][1];
				break;
				sw = true;
			}
		}

		InvalidateRgn(hwnd, NULL, TRUE);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

//#include <windows.h>
//#include <string>
//#include <time.h>
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
//	WNDCLASS WndClass;
//	MSG Message;
//
//	g_hInst = hInstance;
//
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;						// �����찡 ��µǴ� ����
//	WndClass.lpfnWndProc = WndProc;									// �޽��� ó���� ���� �Լ��� �̸� ����
//	WndClass.cbClsExtra = 0;										// Ŭ������ �����츦 ���� ������ �޸� ũ�� 
//	WndClass.cbWndExtra = 0;										//	``
//	WndClass.hInstance = hInstance;									// ���� �Լ��� ù��° �Ű������� �Ѿ�� �ν��Ͻ� ��
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �⺻ ������
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// �⺻ Ŀ��
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �������� ����
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);				// �޴��� �̸�
//	WndClass.lpszClassName = lpszClass;								// ������ Ŭ������ �̸�
//
//	RegisterClass(&WndClass);										// Ŀ�ο� ������ Ŭ���� ���
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
//	);
//								
//
//	ShowWindow(hWnd, nCmdShow); // �����츦 ȭ�鿡 ������
//	UpdateWindow(hWnd);
//
//	while (GetMessage(&Message, NULL, 0, 0)) { // �޼��� �޾ƿ���
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
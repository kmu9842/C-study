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
//									// lpszCmdParam ���������� �Էµ� ���α׷� �μ�. ������ argv�μ��� �ش��ϸ� ���� ���� �������� ��ΰ� ���޵ȴ�.
//									// nCmdShow ���α׷��� ����� �����̸� �ּ�ȭ, ���� ��� ���� ���޵ȴ�.
//
//									// �ν��Ͻ���� ���� �������� ���α׷� �ϳ��� Ī�ϴ� ����̴�. 
//									// ���α׷� ���ο��� �ڽ��� ����Ű�� 1��Ī ����� ������
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
//class Pannel {
//public:
//	int num;
//	int nx, ny;
//	int x = 0, y = 0;
//};
//
//class ImagePannels {
//public:
//	Pannel images[5][5];
//	int Partition;
//	int width, height;
//	HBITMAP hbitmap;
//};
//
//ImagePannels pan;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc, memdc, memBackdc;
//	PAINTSTRUCT ps;
//
//	switch (iMsg) {
//
//	case WM_CREATE:
//		pan.Partition = 5;
//		pan.hbitmap = (HBITMAP)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP8));
//		pan.width = 1024 / pan.Partition;
//		pan.height = 720 / pan.Partition;
//
//		for (int i = 0; i<5; i++) {
//			for (int j = 0; j<5; j++) {
//				pan.images[i][j].y = i;
//				pan.images[i][j].x = j;
//
//				pan.images[i][j].nx = (1024 / pan.Partition) * j;
//				pan.images[i][j].ny = (720 / pan.Partition) * i;
//
//				pan.images[i][j].num = i * 5 + j;
//			}
//		}
//		break;
//
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		memdc = CreateCompatibleDC(hdc);
//
//		pan.hbitmap = (HBITMAP)SelectObject(memdc, pan.hbitmap);
//		//BitBlt(hdc, 0, 0, 1024, 720, memdc, 0, 0, SRCCOPY);
//
//		//pan.hbitmap = (HBITMAP)SelectObject(memdc, pan.hbitmap);
//		for (int i = 0; i < 5; i++) {
//			for (int j = 0; j < 5; j++) {
//				if (i != 4 && j != 3) {
//					BitBlt(hdc,
//						j*pan.width, i * pan.height,
//						pan.width, pan.height,
//						memdc,
//						pan.images[i][j].nx, pan.images[i][j].ny,
//						SRCCOPY);
//				}
//			}
//		}
//
//		EndPaint(hwnd, &ps);
//		break;
//
//	case WM_LBUTTONDOWN:
//
//		break;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//#include <windows.h>
//#include <string>
//
//#include "resource.h"
//
// �̺�Ʈ �帮�� ��� = �̺�Ʈ ��� ���
// �޼��� �帮�� ��� = �޼��� ��� ���
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // ����ڿ� �ý����� �������� �޽����� ó���ϴ� ����
//													   WndProc�� WinMain�Ѵ� �ʼ� �Լ�
//													   WinMain�� �����츦 ����� ǥ���ϱ⸸ �һ� ��κ��� ���� WndProc���� �̷����
//
//HINSTANCE g_hInst;
//LPCTSTR lpszClass = TEXT("First");	// ������ Ŭ������ �����ϴµ� ����
//
//									 APIENTRY�� ���������� ǥ�� ȣ�� �Ծ� _stdcall�� ����Ѵٴ� ��.
//									 WinMain�� �Ű� ���� 
//									 hInstance ���α׷��� �ν��Ͻ� �ڵ�
//									 hPrevInstance �ٷ� �տ� ����� ���� ���α׷��� �ν��Ͻ� �ڵ��̴�. ���� ��� NULL�� �Ǹ� Win32������ �׻� NULL�̴�. 16��Ʈ�� �����ϱ� ���� �μ�
//									 lpszCmdParam ��������� �Էµ� ���α׷� �μ�. ������ argv�μ��� �ش��ϸ� ���� ���� �������� ��ΰ� ���޵ȴ�.
//									 nCmdShow ���α׷��� ����� �����̸� �ּ�ȭ, ���� ��� ���� ���޵ȴ�.
//
//									 �ν��Ͻ���� ���� �������� ���α׷� �ϳ��� Ī�ϴ� ����̴�. 
//									 ���α׷� ���ο��� �ڽ��� ����Ű�� 1��Ī ���� ������
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
//char str[10][100];
//int line, count;
//
// �޼��� ó�� �Լ�
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM IParam) {
//	HDC hdc;
//	PAINTSTRUCT ps;
//	int i;
//	static SIZE size;
//	OPENFILENAME SFN;
//	char lpstrFile[100] = "";
//	char filter[] = "Every File(*.*) \0*.*\0Text File\0*.txt;*.doc\0";
//
//	FILE *fPtr;
//
//	switch (iMessage) {
//	case WM_CREATE:
//		line = 0;
//		count = 0;
//		CreateCaret(hWnd, NULL, 5, 15);
//		ShowCaret(hWnd);
//		return 0;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		for (i = 0; i < line; i++) {
//			TextOut(hdc, 0, i * 20, str[i], strlen(str[i]));
//		}
//		GetTextExtentPoint(hdc, str[line], strlen(str[line]), &size);
//		TextOut(hdc, 0, line * 20, str[line], strlen(str[line]));
//		SetCaretPos(size.cx, line * 20);
//		EndPaint(hWnd, &ps);
//		break;
//	case WM_CHAR:
//		if (wParam == VK_BACK) {
//			count--;
//		}
//		else if (wParam == VK_RETURN)
//		{
//			count = 0;
//			line = line + 1;
//		}
//		else str[line][count++] = wParam;
//		str[line][count] = '\0';
//		InvalidateRgn(hWnd, NULL, TRUE);
//		return 0;
//	case WM_COMMAND:
//		switch (LOWORD(wParam))
//		{
//		case ID_FILESAVE:
//			memset(&SFN, 0, sizeof(OPENFILENAME));
//			SFN.lStructSize = sizeof(OPENFILENAME);
//			SFN.hwndOwner = hWnd;
//			SFN.lpstrFilter = filter;
//			SFN.lpstrFile = lpstrFile;
//			SFN.nMaxFile = 256;
//			SFN.lpstrInitialDir = ".";
//			if (GetSaveFileName(&SFN) != 0) {
//				int i;
//				fPtr = fopen(SFN.lpstrFile, "w");
//				for (i = 0; i <= line; i++)
//				{
//					fputs(str[i], fPtr);
//					fputs("\r\n", fPtr);
//				}
//
//				fclose(fPtr);
//			}
//			break;
//		}
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		HideCaret(hWnd);
//		DestroyCaret();
//		return 0;
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, IParam));
//}
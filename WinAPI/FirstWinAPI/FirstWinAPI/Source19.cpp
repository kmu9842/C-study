#include <windows.h>
#include <stdio.h>
#include "resource.h"

// �̺�Ʈ �帮�� ��� = �̺�Ʈ ��� ���
// �޼��� �帮�� ��� = �޼��� ��� ���

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // ����ڿ� �ý����� �������� �޽����� ó���ϴ� ����
													  // WndProc�� WinMain�Ѵ� �ʼ� �Լ�
													  // WinMain�� �����츦 ����� ǥ���ϱ⸸ �һ� ��κ��� ���� WndProc���� �̷����
BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

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
	WNDCLASS WndClass;
	MSG Message;

	g_hInst = hInstance;

	WndClass.style = CS_HREDRAW | CS_VREDRAW;						// �����찡 ��µǴ� ����
	WndClass.lpfnWndProc = WndProc;									// �޽��� ó���� ���� �Լ��� �̸� ����
	WndClass.cbClsExtra = 0;										// Ŭ������ �����츦 ���� ������ �޸� ũ�� 
	WndClass.cbWndExtra = 0;										//	``
	WndClass.hInstance = hInstance;									// ���� �Լ��� ù��° �Ű������� �Ѿ�� �ν��Ͻ� ��
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �⺻ ������
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// �⺻ Ŀ��
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �������� ����
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);				// �޴��� �̸�
	WndClass.lpszClassName = lpszClass;								// ������ Ŭ������ �̸�

	RegisterClass(&WndClass);										// Ŀ�ο� ������ Ŭ���� ���

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
	UpdateWindow(hWnd);

	while (GetMessage(&Message, NULL, 0, 0)) { // �޼��� �޾ƿ���
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg) {
	case WM_CREATE:
		DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DlgProc);
		break;
		//break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_40001:
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

enum {
 NOOP =	0,
 PLUS, 
 MINUS, 
 MULTI, 
 DIVIDE, 
};

double operation(double opnd1, int op, double opnd2) {
	switch (op) {
	case PLUS:
		return(opnd1 + opnd2);
		break;
	case MINUS:
		return(opnd1 - opnd2);
		break;
	case MULTI:
		return(opnd1 * opnd2);
		break;
	case DIVIDE:
		return(opnd1 / opnd2);
		break;
	}
	return opnd2;
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam) {

	static char num[20], ans[20];
	static int count, PrevOp;
	static double number, res;

	switch (iMsg) {
	case WM_INITDIALOG:
		count = 0;
		PrevOp = NOOP;
		res = (double)0;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_PLUS:
		case IDC_MINUS:
		case IDC_MULTI:
		case IDC_DIVIDE:
		case IDC_ANS:
			number = atof(num);
			if (res != 0.0 && number == 0.0)
				number = res;
			num[0] = '\0';
			count = 0;
			res = operation(res, PrevOp, number);
			switch (LOWORD(wParam))
			{
			case IDC_PLUS:
				PrevOp = PLUS;
				break;
			case IDC_MINUS:
				PrevOp = MINUS;
				break;
			case IDC_MULTI:
				PrevOp = MULTI;
				break;
			case IDC_DIVIDE:
				PrevOp = DIVIDE;
				break;
			case IDC_ANS:
				PrevOp = NOOP;
				break;
			}
			sprintf(ans, "%f", res);
			SetDlgItemTextA(hDlg, IDC_EDIT1, ans);
			break;

		case IDC_0:
			num[count] = '0';
			count++;
			num[count] = '\0';
			SetDlgItemTextA(hDlg, IDC_EDIT1, num);
			break;
		case IDC_1:
			num[count] = '1';
			count++;
			num[count] = '\0';
			SetDlgItemTextA(hDlg, IDC_EDIT1, num);
			break;
		case IDC_2:
			num[count] = '2';
			count++;
			num[count] = '\0';
			SetDlgItemTextA(hDlg, IDC_EDIT1, num);
			break;
		case IDC_3:
			num[count] = '3';
			count++;
			num[count] = '\0';
			SetDlgItemTextA(hDlg, IDC_EDIT1, num);
			break;
		case IDC_4:
			num[count] = '4';
			count++;
			num[count] = '\0';
			SetDlgItemTextA(hDlg, IDC_EDIT1, num);
			break;
		case IDC_5:
			num[count] = '5';
			count++;
			num[count] = '\0';
			SetDlgItemTextA(hDlg, IDC_EDIT1, num);
			break;
		case IDC_6:
			num[count] = '6';
			count++;
			num[count] = '\0';
			SetDlgItemTextA(hDlg, IDC_EDIT1, num);
			break;
		case IDC_7:
			num[count] = '7';
			count++;
			num[count] = '\0';
			SetDlgItemTextA(hDlg, IDC_EDIT1, num);
			break;
		case IDC_8:
			num[count] = '8';
			count++;
			num[count] = '\0';
			SetDlgItemTextA(hDlg, IDC_EDIT1, num);
			break;
		case IDC_9:
			num[count] = '9';
			count++;
			num[count] = '\0';
			SetDlgItemTextA(hDlg, IDC_EDIT1, num);
			break;
		case IDC_POINT:
			num[count] = '.';
			count++;
			num[count] = '\0';
			SetDlgItemTextA(hDlg, IDC_EDIT1, num);
			break;
		case IDCLOSE:
			PostQuitMessage(0);
			EndDialog(hDlg, 0);
			break;
		case IDCANCEL:
			PostQuitMessage(0);
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return 0;
}

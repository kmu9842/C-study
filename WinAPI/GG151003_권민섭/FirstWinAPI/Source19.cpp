#include <windows.h>
#include <stdio.h>
#include "resource.h"

// 이벤트 드리븐 방식 = 이벤트 기반 방식
// 메세지 드리븐 방식 = 메세지 기반 방식

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // 사용자와 시스템이 보내오는 메시지를 처리하는 역할
													  // WndProc와 WinMain둘다 필수 함수
													  // WinMain은 윈도우를 만들고 표시하기만 할뿐 대부분의 일은 WndProc에서 이루어짐
BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First");	// 윈도우 클래스를 정의하는데 사용됨

									// APIENTRY는 윈도우즈의 표준 호출 규약 _stdcall을 사용한다는 뜻.
									// WinMain의 매개 변수 
									// hInstance 프로그램의 인스턴스 핸들
									// hPrevInstance 바로 앞에 실행된 현재 프로그램의 인스턴스 핸들이다. 없을 경우 NULL이 되면 Win32에서는 항상 NULL이다. 16비트를 지원하기 위한 인수
									// lpszCmdParam 명령행으로 입력된 프로그램 인수. 도스의 argv인수에 해당하며 실행 직후 열파일의 경로가 전달된다.
									// nCmdShow 프로그램이 실행될 형태이며 최소화, 보통 모양 등이 전달된다.

									// 인스턴스라는 말은 실행중인 프로그램 하나를 칭하는 용어이다. 
									// 프로그램 내부에서 자신을 가리키는 1인칭 대명사 같은것
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {

	HWND hWnd; // 윈도우 핸들
	WNDCLASS WndClass;
	MSG Message;

	g_hInst = hInstance;

	WndClass.style = CS_HREDRAW | CS_VREDRAW;						// 윈도우가 출력되는 형태
	WndClass.lpfnWndProc = WndProc;									// 메시지 처리에 사용될 함수의 이름 기재
	WndClass.cbClsExtra = 0;										// 클래스와 윈도우를 위한 여분의 메모리 크기 
	WndClass.cbWndExtra = 0;										//	``
	WndClass.hInstance = hInstance;									// 메인 함수에 첫번째 매개변수로 넘어온 인스턴스 값
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// 기본 아이콘
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// 기본 커서
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 윈도우의 배경색
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);				// 메뉴의 이름
	WndClass.lpszClassName = lpszClass;								// 윈도우 클래스의 이름

	RegisterClass(&WndClass);										// 커널에 윈도우 클래스 등록

	hWnd = CreateWindow(		// 윈도우 생성 함수, 보여주지는 않음, false가 뜰경우 종료
		lpszClass,				// 윈도우 클래스 이름
		lpszClass,				// 윈도우 타이틀 이름
		WS_OVERLAPPEDWINDOW,	// 윈도우 스타일
		CW_USEDEFAULT,			// 윈도우 위치 X좌표
		CW_USEDEFAULT,			// 윈도우 위치 Y좌표
		CW_USEDEFAULT,			// 윈도우 가로 크기
		CW_USEDEFAULT,			// 윈도우 세로 크기
		NULL,					// 부모 윈도우 핸들
		(HMENU)NULL,			// 메뉴 핸들
		hInstance,				// 응용프로그램 인스턴스
		NULL					// 생성 윈도우 정보
		);


	ShowWindow(hWnd, nCmdShow); // 윈도우를 화면에 보여줌
	UpdateWindow(hWnd);

	while (GetMessage(&Message, NULL, 0, 0)) { // 메세지 받아오기
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

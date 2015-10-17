#include <windows.h>
#include <math.h>
#include <string>

// 이벤트 드리븐 방식 = 이벤트 기반 방식
// 메세지 드리븐 방식 = 메세지 기반 방식

class player{
private :
	int x, y;
	int score;

public :
	player() {
		x = 0;
		y = 0;
	}

	int getX() { return x; };
	int getY() { return y; };
	int getScore() { return score; };

	void setX(int x2) { x = x2; };
	void setY(int y2) { y = y2; };
	void setScore(int _score) { score = _score; };

	void draw(HDC hdc) {
		HBRUSH brush1 = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, brush1);

		Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
	}
};

class enemy {
private:
	int x, y;
	int size;
	int x2, y2;
	bool collision = true;

public :
	int getX() { return x; };
	int getY() { return y; };
	int getX2() { return x2; };
	int getY2() { return y2; };
	int getSize() { return size; };
	bool getCol() { return collision; };

	void setX(int xs) { x = xs; };
	void setY(int ys) { y = ys; };
	void setX2(int x2s) { x2 = x2s; };
	void setY2(int y2s) { y2 = y2s; };
	void setSize(int s) { size = s; };
	void setCol(int col) { collision = col; };

	void draw(HDC hdc) {

		HBRUSH brush1 = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH brush2 = CreateSolidBrush(RGB(255, 0, 0));

		if (collision) {
			SelectObject(hdc, brush1);
		}
		else {
			SelectObject(hdc, brush2);
		}
		Ellipse(hdc, x, y, x2, y2);
	}
};

player a;
enemy enmys[10];
int sum = 0;
float times = 0;
char s[15] = { "sum : " };
bool EndSW = false;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // 사용자와 시스템이 보내오는 메시지를 처리하는 역할
// WndProc와 WinMain둘다 필수 함수
// WinMain은 윈도우를 만들고 표시하기만 할뿐 대부분의 일은 WndProc에서 이루어짐

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
	WNDCLASSEX WndClass;
	MSG Message;

	g_hInst = hInstance;

	WndClass.cbSize = sizeof(WNDCLASSEX);
	WndClass.cbClsExtra = 0;										// 클래스와 윈도우를 위한 여분의 메모리 크기 
	WndClass.cbWndExtra = 0;										//	``
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 윈도우의 배경색
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// 기본 커서
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// 기본 아이콘
	WndClass.hInstance = hInstance;									// 메인 함수에 첫번째 매개변수로 넘어온 인스턴스 값
	WndClass.lpfnWndProc = WndProc;									// 메시지 처리에 사용될 함수의 이름 기재
	WndClass.lpszClassName = lpszClass;								// 윈도우 클래스의 이름
	WndClass.lpszMenuName = lpszClass;								// 메뉴의 이름
	WndClass.style = CS_HREDRAW | CS_VREDRAW;						// 윈도우가 출력되는 형태
	WndClass.hIconSm = LoadIcon(NULL,IDI_APPLICATION);

	RegisterClassEx(&WndClass);										// 커널에 윈도우 클래스 등록

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

	enmys[0].setX(100);
	enmys[0].setY(100);
	enmys[0].setX2(180);
	enmys[0].setY2(180);
	enmys[0].setSize(80);

	enmys[1].setX(250);
	enmys[1].setY(250);
	enmys[1].setX2(400);
	enmys[1].setY2(400);
	enmys[1].setSize(150);

	enmys[2].setX(0);
	enmys[2].setY(500);
	enmys[2].setX2(0);
	enmys[2].setY2(550);
	enmys[2].setSize(50);

	enmys[3].setX(450);
	enmys[3].setY(450);
	enmys[3].setX2(560);
	enmys[3].setY2(560);
	enmys[3].setSize(90);

	enmys[4].setX(600);
	enmys[4].setY(200);
	enmys[4].setX2(650);
	enmys[4].setY2(250);
	enmys[4].setSize(50);

	ShowWindow(hWnd, nCmdShow); // 윈도우를 화면에 보여줌

	while (GetMessage(&Message, NULL, 0, 0)) { // 메세지 받아오기
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return (int)Message.wParam;
}

// 메세지 처리 함수
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM IParam) { 
	HDC hdc;
	PAINTSTRUCT ps;

	RECT lp = { 0,0,0,0 };
	RECT rt = { 0, 290, 100, 310 };
	RECT rt2 = { 0, 320, 100, 350 };
	
	switch (iMessage) {
	case WM_CREATE :	// 생성 이벤트시 호출
		SetTimer(hWnd,1,0.1f,NULL);
		break;
	case WM_PAINT :
		hdc = BeginPaint(hWnd, &ps);

		a.draw(hdc);
		for (int i = 0;i<5;i++) {
			enmys[i].draw(hdc);
		}

		if (EndSW) {
			sprintf(s, "Error = %d ", sum);
			DrawTextA(hdc, s, strlen(s), &rt, DT_CENTER | DT_WORDBREAK);
			sprintf(s, "Time = %.1f ", times/10);
			DrawTextA(hdc, s, strlen(s), &rt2, DT_CENTER | DT_WORDBREAK);
		}

		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:

		GetClientRect(hWnd, &lp);
		if (EndSW) {
			switch (wParam) {

			case VK_RIGHT:
				a.setX(a.getX() + 10);
				break;

			case VK_LEFT:
				a.setX(a.getX() - 10);
				break;

			case VK_DOWN:
				a.setY(a.getY() + 10);
				break;

			case VK_UP:
				a.setY(a.getY() + 10);
				break;
			}

			for (int i = 0; i < 5; i++) {
				int n = sqrt((a.getX() - (enmys[i].getX() + enmys[i].getSize() / 2)) * (a.getX() - (enmys[i].getX() + enmys[i].getSize() / 2)) +
					(a.getY() - (enmys[i].getY() + enmys[i].getSize() / 2)) * (a.getY() - (enmys[i].getY() + enmys[i].getSize() / 2)));
				if (n < 20 + enmys[i].getSize() / 2) {
					if (enmys[i].getCol()) {
						sum++;
					}
					enmys[i].setCol(false);
				}
			}

			if (a.getX() >= lp.right && a.getY() >= lp.left) {
				KillTimer(hWnd, 1);
				EndSW = true;
			}

			InvalidateRgn(hWnd, NULL, true);
		}
		break;

	case WM_TIMER:
		times += 0.1f;
		break;

	case WM_DESTROY:	// 종료 이벤트시 호출
		PostQuitMessage(0); // 종료
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, IParam));
}
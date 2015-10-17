#include <windows.h>
#include <math.h>
#include <string>

// �̺�Ʈ �帮�� ��� = �̺�Ʈ ��� ���
// �޼��� �帮�� ��� = �޼��� ��� ���

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
	WndClass.hIconSm = LoadIcon(NULL,IDI_APPLICATION);

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

	RECT lp = { 0,0,0,0 };
	RECT rt = { 0, 290, 100, 310 };
	RECT rt2 = { 0, 320, 100, 350 };
	
	switch (iMessage) {
	case WM_CREATE :	// ���� �̺�Ʈ�� ȣ��
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

	case WM_DESTROY:	// ���� �̺�Ʈ�� ȣ��
		PostQuitMessage(0); // ����
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, IParam));
}
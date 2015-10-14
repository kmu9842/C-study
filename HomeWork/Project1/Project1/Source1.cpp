/*#include <iostream>
using namespace std;

int a = 20;
void main() {
	int arr;
	int c1 = 0, c2 = 0, c3 = 0;
	int max, min;

	cin >> arr;
	if (arr > 0) {
		c1++;
	}
	else if (arr < 0) {
		c2++;
	}
	else if (arr == 0) {
		c3++;
	}
	max = arr;
	min = arr;

	for (int i = 0;i<9;i++) {
		cin >> arr;
		if (arr > 0) {
			c1++;
		}
		else if (arr < 0) {
			c2++;
		}
		else if (arr == 0) {
			c3++;
		}

		if (arr > max) max = arr;
		if (arr < min) min = arr;
	}

	cout << c1 << " " << c2 << " " << c3 << "\n" << max << " " << min << " ";

	cin >>  a;;
}*/
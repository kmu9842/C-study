#include <iostream>

using namespace std;

void main() {
	int a, n, c = 0;
	cin >> n;

	for (int i = 0;i<20;i++) {
		cin >> a;
		if (a == n) {
			c++;
		}
	}
	cout << c << "\n";
}
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int N,sum = 0;
//int arr[200][100] = { 0, };
//int y = 49;
//int x = 0;
//
//bool blockComplete() {
//
//	int sw = 0;
//
//	for (int i = 0; i < 200; i++) {
//		sw = 0;
//		for (int j = 0; j < 100; j++) {
//			if (sw == 0 &&arr[i][j] == 1) {
//				sw++;
//			}
//			else if (sw == 1 && arr[i][j] == 0) {
//				sw++;
//			}
//			else if (sw == 2 && arr[i][j] == 1) {
//				sw++;
//			}
//		}
//
//		if (sw >= 3) {
//			return false;
//		}
//	}
//
//	return true;
//}
//
//void blockSet(int n) {
//	
//	if (n == N-1) {
//		if (blockComplete()) {
//			sum++;
//		}
//	}
//	else {
//		if (arr[y - 1][x] != 1 && y - 1 >= 0 ) {
//			arr[y - 1][x] = 1;
//			y--;
//
//			blockSet(n + 1);
//			arr[y][x] = 0;
//			y++;
//		}
//
//		if (arr[y][x + 1] != 1 && x + 1 <= 100) {
//			arr[y][x + 1] = 1;
//			x++;
//
//			blockSet(n + 1);
//			arr[y][x] = 0;
//			x--;
//		}
//
//		if (arr[y + 1][x] != 1 && y + 1 <= 200) {
//			arr[y + 1][x] = 1;
//			y++;
//
//			blockSet(n + 1);
//			arr[y][x] = 0;
//			y--;
//		}
//
//		if (arr[y][x - 1] != 1 && x - 1 >= 0) {
//			arr[y][x - 1] = 1;
//			x--;
//
//			blockSet(n + 1);
//			arr[y][x] = 0;
//			x++;
//		}
//	}
//
//	return;
//}
//
//void main() {
//
//	cin >> N;
//
//	arr[y][x] = 1;
//	blockSet(0);
//	cout << sum << "\n";
//
//	int a;
//	cin >> a;
//}
//#include <iostream>
//
//template <typename T1, typename  T2>
//void change(T1 a, T2 b) {
//	auto tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main() {
//	int a = 3, b = 5;
//	int c = 2;
//	double d = 3.6;
//
//	change(&a, &b);
//	std::cout << a << " " << b << std::endl;
//	change(&c, &d);
//	std::cout << c << " " << d << std::endl;
//}
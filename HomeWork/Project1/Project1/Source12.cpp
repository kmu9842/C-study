#include <iostream>

template <typename T1, typename  T2>
auto max(T1 a, T2 b)->decltype(a > b ? a : b) {
	return (a > b ? a : b);
}

int main() {
	std::cout << max(3, 4) << std::endl;
	std::cout << max(3, 4.5) << std::endl;
}
#include <iostream>

void main() {
	auto a = [](int x) ->int { return x;  };

	std::cout << a(1) << std::endl;
}
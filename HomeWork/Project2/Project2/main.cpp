
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define PI 3.141592

template <typename T>
T add(T& a, T& b) {
	return a + b;
}

template <typename T>
T sub(T a, T b) {
	return a - b;
}

template <typename T>
T mul(T a, T b) {
	return a * b;
}

template <typename T>
T div(T a, T b) {
	return a / b;
}

int main(void) {
	std::string c;

	cin >> c;

	float a, b;
	if (c == "add") {
		cin >> a;
		cin >> b;
		cout << add(a, b) << "\n";
	}
	else if (c == "sub") {
		cin >> a;
		cin >> b;
		cout << sub(a, b) << "\n";
	}
	else if (c == "mul") {
		cin >> a;
		cin >> b;
		cout << mul(a, b) << "\n";
	}
	else if (c == "div") {
		cin >> a;
		cin >> b;
		cout << div(a, b) << "\n";
	}
	else if (c == "pow") {
		cin >> a;
		cin >> b;
		cout << pow(a, b) << "\n";
	}
	else if (c == "sin") {
		cin >> a;
		cout << sin(a * PI / 180.) << "\n";
	}
	else if (c == "cos") {
		cin >> a;
		a = cos(a * PI / 180.);
		a = ((int)(a*pow(10.0, 3)) / pow(10.0, 3));
		cout << a << "\n";
	}

	int d;
	cin >> d;
}
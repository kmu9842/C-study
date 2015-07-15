// Scoped enum
// C/C++에서 기존에 사용하던 열거형에는 몇가지 문제가 존재하는데, 그 문제들이란
// 1. A 열거체에서 사용한 C라는 이름을 B 열거체에서는 사용할수 없으며,
// 2. 서로 다른 열거체 변수끼리 더하거나 비교할 수 있다.(기본적으로 열거체의 타입은 int기 때문)

// C++ 11에서는 이런 문제들을 보완한 범위 지정 열거체를 제공한다.
// enum 대신 enum class를 사용, 명시적으로 타입을 지정하지 않으면 오류가 나며, (묵시적 변환 X)
// 서로 다른 열거체 변수끼리 연산할 수 없다.

#include <iostream>

using namespace std;
int main() {
	enum TrafficLight { Red, Yellow, Green };
	enum Job { Warrior, Ranger, Wizard, Green }; // 에러 발생
	enum coffe : unsigned char { Latte = 10, Mocha = 25 };

	int jobNum = Warrior;
	int i = Green + Latte;

	if (Yellow == Ranger)
		cout << "Same!" << std::endl; // 같은 값으로 인식됨
	else
		cout << "Different!" << std::endl;

	return 0;
}

#include <iostream>

using namespace std;
int main() {
	enum class TrafficLight { Red, Yellow, Green };
	enum class Job { Warrior, Ranger, Wizard, Green };
	enum class Coffee : unsigned char { Latte = 10, Mocha = 25 };

	// int jobNum = Warrior; // 다른 열거체끼리 연산 할 수 없으며 형식을 이용해야함!
	// int i = Green + Latte;

	// ->

	Job jobNum = Job::Warrior;
	int i = static_cast<int>(TrafficLight::Green) + static_cast<int>(Coffee::Latte);

	if (Yellow == Ranger) // 에러 발생!
		cout << "Same!" << std::endl; // 같은 값으로 인식됨
	else
		cout << "Different!" << std::endl;

	return 0;
}


// Binary Literal, separator
// C/C++에서는 10진수 외에 8진수, 16진수를 표현할 수 있음
// - 그러나 2진수를 표현 하는 방법이 없었음
// C++ 14에서 2진수를 표현할 수 있는 방법 추가! : 0b~
// 또한 기존 C/C++에서는 큰 숫자를 읽기 힘듬
// C++ 14에서는 구분자가 추가되어 큰 숫자를 읽기 쉬워짐
// int INT_MAX = 21'4748'3647;

#include <iostream>

int main() {
	int decimal = 52;
	int octal = 064; // 8진수
	int hexadecimal = 0x34; // 16진수
	int bianry = 0b110100; // 2진수, C++14

	int maxInt_Cpp98 = 2417483647;
	int maxInt_Cpp14 = 21'4748'3647;

	return 0;
}


// std::string
// c에서는 문자열을 나타내기 위해 char[]이나 char*를 사용
// 그러나 비교 연결 길이 등 문자열 관련 함수들을 사용할 때 불편함
// C++에서는 std::string을 사용하여 문자열을 나타냄
// 비교, 연결, 길이 등의 문자열 동작들을 편리한 방법으로 제공

#include <iostream>
#include <string>

int main() {
	std::string str1 = "Hello, World";
	std::string str2 = "Hello, Word";

	if (str1 == str2) std::cout << "Same!" << std::endl; // 문자열읩 ㅣ교
	else std::cout << "Different!" << std::endl;

	str1 = str1 + str2; // 문자열의 연결
	std::cout << str1 << std::endl;
	std::cout << str1.size() << ' ' << str2.length << std::endl; // 문자열의 크기, 길이

	return 0;
}
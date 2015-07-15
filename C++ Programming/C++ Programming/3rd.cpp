// Scoped enum
// C/C++���� ������ ����ϴ� ���������� ��� ������ �����ϴµ�, �� �������̶�
// 1. A ����ü���� ����� C��� �̸��� B ����ü������ ����Ҽ� ������,
// 2. ���� �ٸ� ����ü �������� ���ϰų� ���� �� �ִ�.(�⺻������ ����ü�� Ÿ���� int�� ����)

// C++ 11������ �̷� �������� ������ ���� ���� ����ü�� �����Ѵ�.
// enum ��� enum class�� ���, ��������� Ÿ���� �������� ������ ������ ����, (������ ��ȯ X)
// ���� �ٸ� ����ü �������� ������ �� ����.

#include <iostream>

using namespace std;
int main() {
	enum TrafficLight { Red, Yellow, Green };
	enum Job { Warrior, Ranger, Wizard, Green }; // ���� �߻�
	enum coffe : unsigned char { Latte = 10, Mocha = 25 };

	int jobNum = Warrior;
	int i = Green + Latte;

	if (Yellow == Ranger)
		cout << "Same!" << std::endl; // ���� ������ �νĵ�
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

	// int jobNum = Warrior; // �ٸ� ����ü���� ���� �� �� ������ ������ �̿��ؾ���!
	// int i = Green + Latte;

	// ->

	Job jobNum = Job::Warrior;
	int i = static_cast<int>(TrafficLight::Green) + static_cast<int>(Coffee::Latte);

	if (Yellow == Ranger) // ���� �߻�!
		cout << "Same!" << std::endl; // ���� ������ �νĵ�
	else
		cout << "Different!" << std::endl;

	return 0;
}


// Binary Literal, separator
// C/C++������ 10���� �ܿ� 8����, 16������ ǥ���� �� ����
// - �׷��� 2������ ǥ�� �ϴ� ����� ������
// C++ 14���� 2������ ǥ���� �� �ִ� ��� �߰�! : 0b~
// ���� ���� C/C++������ ū ���ڸ� �б� ����
// C++ 14������ �����ڰ� �߰��Ǿ� ū ���ڸ� �б� ������
// int INT_MAX = 21'4748'3647;

#include <iostream>

int main() {
	int decimal = 52;
	int octal = 064; // 8����
	int hexadecimal = 0x34; // 16����
	int bianry = 0b110100; // 2����, C++14

	int maxInt_Cpp98 = 2417483647;
	int maxInt_Cpp14 = 21'4748'3647;

	return 0;
}


// std::string
// c������ ���ڿ��� ��Ÿ���� ���� char[]�̳� char*�� ���
// �׷��� �� ���� ���� �� ���ڿ� ���� �Լ����� ����� �� ������
// C++������ std::string�� ����Ͽ� ���ڿ��� ��Ÿ��
// ��, ����, ���� ���� ���ڿ� ���۵��� ���� ������� ����

#include <iostream>
#include <string>

int main() {
	std::string str1 = "Hello, World";
	std::string str2 = "Hello, Word";

	if (str1 == str2) std::cout << "Same!" << std::endl; // ���ڿ��� �ӱ�
	else std::cout << "Different!" << std::endl;

	str1 = str1 + str2; // ���ڿ��� ����
	std::cout << str1 << std::endl;
	std::cout << str1.size() << ' ' << str2.length << std::endl; // ���ڿ��� ũ��, ����

	return 0;
}
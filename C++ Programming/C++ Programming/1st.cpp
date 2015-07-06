// printf, scanf -> cout, cin
// ��������� ��ȭ : stdio.h -> iostream (input/output stream)
// ����� �Լ��� ��ȭ
// ��� : printf -> std::cout ���� ������ <<�� ����� ���𰡸� �ܼ� ȭ�鿡 ���
// �Է� : scanf -> std::cin ���Կ����� >>�� ����� �ַܼ� ���� ���𰡸� ����
// << �� >>�� ȭ��ǥ �����̶�� �����ϸ� ���� ���� ����
// �Է��̳� ������� ���ʿ�(%d ��)

#include <iostream>

void main() {
	int a;

	std::cin >> a;
	std::cout << "a = " << a << std::endl;
}


// bool type
// C������ ���ǹ��� ���� ������ ǥ���ϱ� ���� int�� ���
// �� : 0�� ������ ��� �� 
// ���� : 0
// C++������ ���� ������ ��Ȯ�� ����� ���� boolŸ���� �߰���
// �� : true
// ���� : false


#include <iostream>

void main() {
	bool b = true;

	if (b) {
		std::cout << "b is " << b << std::endl;
		std::cout << "b is not " << !b << std::endl;
	}
}

// auto keyword
// ǥ������ Ÿ���� �����ϴ� ���� �������
// C++11�� �߰��� autoŸ���� ����� ��� �����Ͻÿ� Ÿ���� �߷��� � Ÿ������ ����
// �⺻ ���� Ÿ���� ������ �װ��� ������ �Ҷ� �߷� ������ ��� Ÿ�Կ��� ��� ����
// ���� �����Ͽ��� �߷��� �Ұ����� ��� ���� �߻�

#include <iostream>
#include <vector>

void main() {
	auto i = 10;
	auto i2 = 3.14;

	std::vector<std::tuple<std::string, int, double>> vStudents;

	for (auto iter = vStudents.begin() ;
			  iter != vStudents.end()  ;
		      ++iter) {

	}
}


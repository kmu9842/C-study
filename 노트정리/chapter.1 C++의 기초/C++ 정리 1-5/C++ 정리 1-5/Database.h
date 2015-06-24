#pragma once
#include <iostream>
#include <vector>
#include "Empolyee.h"

// DatabaseŬ������ std::vector�� �̿��� Empolyee��ü���� ��´�.
// �����ͺ��̽��� ���ο� �������� ����Ҷ� ���� �̸��� �����ϸ� �ȴ�. 
// ������ ��� �Լ��� ���ǻ� ��� �Ϸ��� ���� ������ Empolyee��ü�� �����Ѵ�.
// �ܺο����� getEmpolyee�Լ��� ������ ��ü�� ���� �� �ִµ� �� �޼���� �������� �ĺ��ϱ�����
// ��ȣ �Ǵ� �̸��� �Է� ������ �ֵ��� �ΰ����� �����.

namespace Records {
	const int kFirstEmpolyeeNumber = 1000;
	class Database {
	public : 
		Database();
		~Database();

		// ������ �Լ�
		Empolyee& addEmpolyee(std::string inFirstName, std::string inLastName);
		Empolyee& getEmpolyee(int inEmpolyNumber);
		Empolyee& getEmpolyee(std::string inFirstName, std::string inLastName);

		// ����� ���� �ִ� ������� ���� ������, ��ü �������� �����Ͽ� ���
		const void displayAll();
		const void displayCurrnet();
		const void displayFormer();

	protected :
		std::vector<Empolyee> mEmpolyees;
		int mNextEmpolyeeNumber; // ���ο� �������� ���Ǿ��� �� �Ҵ��� ������ȣ�� ���� 
	};
}
#pragma once
#include <string>

// Ư�� ������ �Ѹ��� ������ �������� �ϴ� Ŭ����

// ������ ������ ��ȸ�ϰ� ������ �� �հ� ��

namespace Records {
	const int kDefaultStartingSalary = 30000;

	class Empolyee {
	public:
		Empolyee();
		void poromote(int inRaiseAmount = 1000); // ����
		void demote(int inDemeritAmount = 1000); // ¡��, ����
		void hire(); // �������� ä�� �Ǵ� ����
		void fire(); // �������� ���� �Ǵ� �ذ�
		const void display(); // �ַܼ� ������ ���� ���
							  //�׼����� ����
							  //get/set���� �����ϴ� �ɹ� ������ ���� �޼������ ������, ���Ͷ�� �θ�
		void setFirstName(std::string inFirstName);
		const std::string getFirstName();
		void setLastName(std::string inLastName);
		const std::string getLastName();
		void setEmpoloyeeNumber(int inEmpolyeeNumber);
		const int getEmpolyeeNumber();
		void setSalary(int inNewSalary);
		const int getSalary();
		const bool getIsHired();

	protected:
		std::string mFirstName;
		std::string mLastName;
		int mEmpolyeeNumber;
		int mSalary;
		bool bHired;
	};
}
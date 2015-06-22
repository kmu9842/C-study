#include <iostream>
#include "Empolyee.h"
using namespace std;

//EmpolyeeŬ������ �޼���褩�� ���� ������(���Ǻ�)

namespace Records {
	// ������
	Empolyee::Empolyee() {
		mFirstName = "";
		mLastName = "";
		mEmpolyeeNumber = -1;
		mSalary = kDefaultStartingSalary;
		bHired = false;
	}

	void Empolyee::poromote(int inRaiseAmount) {
		setSalary(getSalary() + inRaiseAmount);
	}

	void Empolyee::demote(int inDemeritAmount) {
		setSalary(getSalary() - inDemeritAmount);
	}

	void Empolyee::hire()
	{
		bHired = true;
	}

	void Empolyee::fire()
	{
		bHired = false;
	}

	// Ŭ���� ���ο����� �׼��� �޼��尡
	// ������ ��� �� �޼��带 ����ϴ� ���� �ٶ����� �ڵ� �����̴�.
	const void Empolyee::display() {
		cout << "Employee : " << getLastName() << ", " << getFirstName() << endl;
		cout << "------------------------------" << endl;
		cout << (bHired ? "Current Empolyee " : "former Empolyee") << endl;
		cout << "Salary : $" << getSalary() << endl;
		cout << endl;
	}


	void Empolyee::setFirstName(std::string inFirstName)
	{
		mFirstName = inFirstName;
	}

	const std::string Empolyee::getFirstName()
	{
		return mFirstName;
	}

	void Empolyee::setLastName(std::string inLastName)
	{
		mLastName = inLastName;
	}

	const std::string Empolyee::getLastName()
	{
		return mLastName;
	}

	void Empolyee::setEmpoloyeeNumber(int inEmpolyeeNumber)
	{
		mEmpolyeeNumber = inEmpolyeeNumber;
	}

	const int Empolyee::getEmpolyeeNumber()
	{
		return mEmpolyeeNumber;
	}

	void Empolyee::setSalary(int inNewSalary)
	{
		mSalary = inNewSalary;
	}

	const int Empolyee::getSalary()
	{
		return mSalary;
	}

	const bool Empolyee::getIsHired()
	{
		return bHired;
	}


}

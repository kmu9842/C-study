#include <iostream>
#include "Empolyee.h"
using namespace std;

//Empolyee클래스의 메서드듣ㄹ에 대한 구현부(정의부)

namespace Records {
	// 생성자
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

	// 클래스 내부에서라도 액세서 메서드가
	// 존재할 경우 그 메서드를 사용하는 것이 바람직한 코딩 습관이다.
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

#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace Records {
	Database::Database() {
		mNextEmpolyeeNumber = kFirstEmpolyeeNumber; // ���� ��ȣ ���۰� ����
	}
	Database::~Database() {}

	Empolyee & Database::addEmpolyee(std::string inFirstName, std::string inLastName)
	{
		Empolyee theEmpolyee;
		theEmpolyee.setFirstName(inFirstName);
		theEmpolyee.setLastName(inLastName);
		theEmpolyee.setEmpoloyeeNumber(mNextEmpolyeeNumber++);
		theEmpolyee.hire();
		mEmpolyees.push_back(theEmpolyee);
		
		return mEmpolyees[mEmpolyees.size() - 1];
	}

	Empolyee & Database::getEmpolyee(int inEmpolyNumber)
	{
		for (auto i : mEmpolyees) {
			if (i.getEmpolyeeNumber() == inEmpolyNumber)
				return i;
		}

		// ã�� ���� ��ȣ�� ������� ���� throw
		cerr << "No employee with number " << inEmpolyNumber << endl;
		throw exception();
	}

	Empolyee & Database::getEmpolyee(std::string inFirstName, std::string inLastName)
	{
		for (auto& i : mEmpolyees) {
			if (i.getFirstName() == inFirstName && i.getLastName() == inLastName)
				return i;
		}

		// ã�� ���� �̸��� ������� ���� throw
		cerr << "No employee with name " << inLastName << ", " << inFirstName << endl;
		throw exception();
	}

	const void Database::displayAll()
	{
		for (auto& i : mEmpolyees) {
			i.display();
		}
	}
	const void Database::displayCurrnet()
	{
		for (auto& i : mEmpolyees) {
			if (i.getIsHired()) {
				i.display();
			}
		}
	}
	const void Database::displayFormer()
	{
		for (auto& i : mEmpolyees) {
			if (!i.getIsHired()) {
				i.display();
			}
		}
	}
}

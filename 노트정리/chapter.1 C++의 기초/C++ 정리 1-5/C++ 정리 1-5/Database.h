#pragma once
#include <iostream>
#include <vector>
#include "Empolyee.h"

// Database클래스는 std::vector를 이용해 Empolyee객체들을 담는다.
// 데이터베이스는 새로운 종업원을 등록할때 성과 이름만 기입하면 된다. 
// 종업원 등록 함수는 편의상 등록 완료후 새로 생성된 Empolyee객체를 리턴한다.
// 외부에서는 getEmpolyee함수로 종업원 객체를 얻을 수 있는데 이 메서드는 종업원을 식별하기위해
// 번호 또는 이름을 입력 받을수 있도록 두가지를 만든다.

namespace Records {
	const int kFirstEmpolyeeNumber = 1000;
	class Database {
	public : 
		Database();
		~Database();

		// 참조형 함수
		Empolyee& addEmpolyee(std::string inFirstName, std::string inLastName);
		Empolyee& getEmpolyee(int inEmpolyNumber);
		Empolyee& getEmpolyee(std::string inFirstName, std::string inLastName);

		// 출력은 현재 있는 종업언과 떠난 종업원, 전체 종업원을 구분하여 출력
		const void displayAll();
		const void displayCurrnet();
		const void displayFormer();

	protected :
		std::vector<Empolyee> mEmpolyees;
		int mNextEmpolyeeNumber; // 새로운 종업원이 고영되었을 때 할당할 고유번호를 지정 
	};
}
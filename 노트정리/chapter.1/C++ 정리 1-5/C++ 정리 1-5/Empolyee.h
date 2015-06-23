#pragma once
#include <string>

// 특정 종업원 한명의 정보를 유지보수 하는 클래스

// 종업원 정보를 조회하고 변경할 수 잇게 함

namespace Records {
	const int kDefaultStartingSalary = 30000;

	class Empolyee {
	public:
		Empolyee();
		void poromote(int inRaiseAmount = 1000); // 승진
		void demote(int inDemeritAmount = 1000); // 징계, 강등
		void hire(); // 종업원의 채용 또는 재고용
		void fire(); // 종업원의 퇴직 또는 해고
		const void display(); // 콘솔로 종업원 정보 출력
							  //액세서와 세터
							  //get/set으로 시작하는 맴버 데이터 접근 메서드들을 엑세서, 세터라고 부름
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
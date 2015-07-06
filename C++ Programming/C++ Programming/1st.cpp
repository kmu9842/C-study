// printf, scanf -> cout, cin
// 헤더파일의 변화 : stdio.h -> iostream (input/output stream)
// 입출력 함수의 변화
// 출력 : printf -> std::cout 삽입 연산자 <<를 사용해 무언가를 콘솔 화면에 출력
// 입력 : scanf -> std::cin 삽입연산자 >>를 사용해 콘솔로 부터 무언가를 저장
// << 나 >>를 화살표 방향이라고 생각하면 쉽게 이해 가능
// 입력이나 출력형식 불필요(%d 등)

#include <iostream>

void main() {
	int a;

	std::cin >> a;
	std::cout << "a = " << a << std::endl;
}


// bool type
// C에서는 조건문의 참과 거짓을 표현하기 위해 int를 사용
// 참 : 0을 제외한 모든 값 
// 거짓 : 0
// C++에서는 참과 거짓의 명확한 사용을 위해 bool타입이 추가됨
// 참 : true
// 거짓 : false


#include <iostream>

void main() {
	bool b = true;

	if (b) {
		std::cout << "b is " << b << std::endl;
		std::cout << "b is not " << !b << std::endl;
	}
}

// auto keyword
// 표현식의 타입을 결정하는 것은 어려운일
// C++11에 추가된 auto타입을 사용할 경우 컴파일시에 타입을 추론해 어떤 타입인지 결정
// 기본 내장 타입을 포함해 그것을 컴파일 할때 추론 가능한 모든 타입에서 사용 가능
// 만약 컴파일에서 추론이 불가능할 경우 오류 발생

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


// Reference
// 레퍼런스는 다른 변수를 가리키는 변수 (포인터 기능의 일부)
// 다른 변수와 동일한 메모리 위치를 서로 공유함
// 레퍼런스에 값을 대입할때 *나 &를 추가해야 하는 특별한 문법이 필요없음
// 포인터의 간소화 버전! (변수에 별명을 붙인다고 생각하면 됨)

// 레퍼런스는 언제나 유용한 메모리만을 가리켜야 함
// 반드시 초기화 해야함!

#include <iostream>

int main() {

	int i = 10;
	int& ref = i;

	ref += 10; // i에게 10이 더해진다
	
	return 0;
}

// Pass-by-reference

#include <iostream>

void swap(int& a,int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 10, b= 20;

	swap(a,b);

	return 0;
}


// Function overloading (함수 오버로딩)
// 오버로딩이란, 여러 함수에서 같은 이름을 사용할 수 잇따는 뜻
// 예시로 사각형의 넓이를 구하는 함수를 만들 때,
// 네 점으로 면적을 계산하는 방법의 함수와 너비와 높이로 계산하는 방법의 
// 함수의 이름을 똑같이 할경우 쓰일 수 있다.

// 단 오버로딩된 함수는 인수의 개수가 서로 달라야 함
// 인수의 개수가 같은 경우에는 인수의 타입이 달라야 함
// 리턴 타입만 다른 경우에는 사용 불가

int sum(int a, int b) {
	return a + b;
}

int sum(int a, int b, int c) {
	return a + b + c;
}

int main() {
	int a = sum(1, 2);
	int b = sum(a, 1, 3);

	return 0;
}


// Namespace
// 어떤 프로젝트를 진행할 때, 두 사람이 구현한 코드에서
// 변수명과 함숨여이 서로 똑같은 상황이 발생할 수 있다.
// 이럴 경우 충돌을 피하기 위해, 한사람의 코드를 몽땅 바꿔야 한다.

// 이를 위해 C++에서는 네임스페이스라는 것이 등장
// 네임스페이스를 통해 타입의 기본 이름을 확장 해줌으로써,
// 위의 상황과 같은 충돌을 피할수 있다

// 일일이 네임스페이스를 적기 귀찮을 경우 using을 사용할 수도 있다.

using namespace std;

namespace A {
	void print() { cout << "A";  };
}

namespace B {
	void print() { cout << "B"; };
}

int main() {
	A::print();
	B::print();

	return 0;
}



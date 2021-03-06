// 객체 지향 프로그래밍이란, 프로그램을 단순히 데이터와
// 처리 방법으로 나누지 않고, 수많은 '객체'라는 기본 단위로 나누어
// 이 객체들의 상호작용으로 서술하는 방식을 말함

// 예를 들면 절차지향은 시나리오를 중심으로 소설을 쓰는 경우, 객체지향은 캐릭터 중심으로 소설을 쓰는 경우

// 객체란?
// 데이터와 기능을 하나로 묶어서 다룰 수 있는 개념
// "누가 무엇을 어떻게"
// 누가 : 객체, 무엇을 : 멤버 변수, 어떻게 : 멤버 함수

// 객체는 멤버 변수와 이를 대상으로 처리하는 동작인 멤버 함수를 하나로 묶어 만든 요소

// 선언 방법
// class 클래스이름 { ... };
// class와 struct의 차이점 - 일반적으로 클래스는 밖에서 멤버변수나 멤버함수의 접근이 불가능, struct는 가능

// 클래스의 멤버 함수
// 함수의 본체 내용은 클래스 내부나 외부에서 구현
// 클래스 내부에서 함수의 본체가 구현된 함수들은 인라인 함수라 함
// - 인라인 함수는 매크로와 비슷하나 훨씬 쓰기 간편하며 효율적으로 동작
// 함수의 본체가 긴 경우 클래스의 외부에 정의하는것이 편리

// 데이터 -> 추상화 -> 멤버변수와 멤버함수로 나눔 -> 클래스화 -> 인스턴스화 : 객체를 생성

class Elephant {
public : 
	int FootNumber;
	double noseLength;
	double weight;

	void wash() {}
	void pick() {}
};

int main() {
	Elephant e = { 4,4.96,1.02 };

	e.wash();
	e.pick();
}

// C++에서는 접근 제한자를 사용해 멤버에 접근할 수 있는 번위를 정함
// private : 자신의 멤버 함수 외 접근 불가
// protected : 자식 클래스의 멤버 함수까지만 접근 허용
// public : 모든 곳으로부터의 접근 허용

// 정보 은닉
// 사용자는 프로그램의 내부동작이나 구조를 알 필요가 없음
// 사용자가 최소한의 정보만으로 프로그램을 쉽게 사용 할 수 있어야 함
// 사용을 위해 간접적 접근 경로를 제공해야 함
// -> 이것을 게터와 세터라고함 (Getter, Setter)

// 캡슐화 - 관련있는 데이터와 함수를 하나의 단위로 묶는 것
// 캡슐화와 정보은닉은 다름, 캡슐화는 되어잇지만 정보 은닉은 되있지 않은 코드가 있음



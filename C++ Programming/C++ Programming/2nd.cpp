// Range-based for
// 반복문 중 가장 많이 사용하는 지정된 휫수만큼 반복하는 작업에도 사용하지만
// 배열이나 각종 컨테이너에 있는 각 요소들에 무언가를 수행하기 위해 순회하는 목적으로도 많이 사용
// 하지만 조건문에 배열이나 컨테이너에 몇개의 요소가 들어있는지 명시해야한다!

// 요소들의 개수에 상관없이 반복문을 수행하기 위해 -> 범위 기반 for문의 등장

#include <iostream>
#include <vector>

int main() {

	int arr[] = { 1,2,3,4,5 };

	for (auto& i : arr) { // for (int i = 0; i < 5; i++)
		std::cout << i << std::endl;
	}

	return 0;
}

// malloc, free -> new, delete
// C에서는 동적 메모리 할당을 위해 mallloc, calloc등을 사용
// 또한 반환을 위해 free를 사용
// C++에서는 malloc, calloc 등을 대신해 new를 사용하고
// free를 대신해 delete를 사용 -> 쉬운 문법을 제공

// 주의 : new -> delete, new[] -> delete[]

#include <iostream>

int main(){
	int i;
	int** arr = (int**)malloc(sizeof(int*) * 5); 

	for (i = 0; i < 5; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 5);
	}

	for (i = 0; i < 5; i++) {
		free(arr[i]);
	}
	free(arr);
	arr = NULL;

	return 0;
}

// ->

int main() {
	int i;
	int** arr = new int*[5];

	for (i = 0; i < 5; i++) {
		arr[i] = new int[5];
	}

	for (i = 0; i < 5; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = NULL;

	return 0;
}


// NULL -> nullptr
// C에서는 널포인터를 나타내기 위해 NULL이나 상수 0을 사용
// 하지만 NULL은 진짜 널 포인터를 가리키지 않음 NULL = 0
// NULL이나 상수 0을 사용하여 함수에 인자로 넘길경우, int형 타입으로 추론되는 문제 발생!
// 이를 위해 nullptr이 등장
// 포인터 변수와 마찬가지로 4바이트, 그러 nullptr은 타입이 아니다. 실제타입은 std::nullptr_t

#include <iostream>

void f(int a) {
	std::cout << "f(int)" << std::endl;
}

void f(int* p) {
	std::cout << "f(int*)" << std::endl;
}

int main() {
	f(nullptr); // -> 출력은 f(int*), 포인터로 취급됨
	return 0;
}

int main() {
	int i;
	int** arr = new int*[5];

	for (i = 0; i < 5; i++) {
		arr[i] = new int[5];
	}

	for (i = 0; i < 5; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;

	return 0;
}


// C에서는 ()를 통해 명시적(Explicit) 캐스팅을 할 수 있음
// 그러나 개발자의 실수를 그대로 용납하는 오류 가능성을 포함
// C++에서는 좀 더 명시적인 캐스팅 방법을 통해 오류를 방지
// static_cast, dynamic_cast, const_cast, reinterpret_cast
// 캐스트-이름<타입>(표현식);

// static_cast		: const를 제외한 모든 명확한 타입 변환에 사용
// dynamic_cast		: 기본 타입에 대한 포인터나 참조자를 파생 타입에 대한 포인터나 참조자로 안전하게 변환
// const_cast		: const 객체를 const가 아닌 타입으로 변환
// reinterpret_cast : 비트 구성 형식을 저수준에서 재해석

#include <iostream>

int main() {
	char *str = "Hello World";

	int *pi = (int*)str;			// <- 캐릭터형 포인터와 int형 포인터는 맞지 않음
	char* pc = (char*)*pi;			// <- 마찬가지로 캐릭터형 포인터와 int형 포인터는 맞지 않음

	std::cout << pc << std::endl;

	return 0;
}

// 위의 코드는 실행할 때에 오류가 발생한다. 그러나 ->

#include <iostream>

int main() {
	char *str = "Hello World";

	int *pi = static_cast<int*>(str);
	char* pc = static_cast<char*>(pi);

	std::cout << pc << std::endl;

	return 0;
}

// static_cast를 이용하면 컴파일러에서 오류를 감지하여
// 실행 오류를 미연에 방지한다
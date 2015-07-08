// Range-based for
// �ݺ��� �� ���� ���� ����ϴ� ������ �ܼ���ŭ �ݺ��ϴ� �۾����� ���������
// �迭�̳� ���� �����̳ʿ� �ִ� �� ��ҵ鿡 ���𰡸� �����ϱ� ���� ��ȸ�ϴ� �������ε� ���� ���
// ������ ���ǹ��� �迭�̳� �����̳ʿ� ��� ��Ұ� ����ִ��� ����ؾ��Ѵ�!

// ��ҵ��� ������ ������� �ݺ����� �����ϱ� ���� -> ���� ��� for���� ����

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
// C������ ���� �޸� �Ҵ��� ���� mallloc, calloc���� ���
// ���� ��ȯ�� ���� free�� ���
// C++������ malloc, calloc ���� ����� new�� ����ϰ�
// free�� ����� delete�� ��� -> ���� ������ ����

// ���� : new -> delete, new[] -> delete[]

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
// C������ �������͸� ��Ÿ���� ���� NULL�̳� ��� 0�� ���
// ������ NULL�� ��¥ �� �����͸� ����Ű�� ���� NULL = 0
// NULL�̳� ��� 0�� ����Ͽ� �Լ��� ���ڷ� �ѱ���, int�� Ÿ������ �߷еǴ� ���� �߻�!
// �̸� ���� nullptr�� ����
// ������ ������ ���������� 4����Ʈ, �׷� nullptr�� Ÿ���� �ƴϴ�. ����Ÿ���� std::nullptr_t

#include <iostream>

void f(int a) {
	std::cout << "f(int)" << std::endl;
}

void f(int* p) {
	std::cout << "f(int*)" << std::endl;
}

int main() {
	f(nullptr); // -> ����� f(int*), �����ͷ� ��޵�
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


// C������ ()�� ���� �����(Explicit) ĳ������ �� �� ����
// �׷��� �������� �Ǽ��� �״�� �볳�ϴ� ���� ���ɼ��� ����
// C++������ �� �� ������� ĳ���� ����� ���� ������ ����
// static_cast, dynamic_cast, const_cast, reinterpret_cast
// ĳ��Ʈ-�̸�<Ÿ��>(ǥ����);

// static_cast		: const�� ������ ��� ��Ȯ�� Ÿ�� ��ȯ�� ���
// dynamic_cast		: �⺻ Ÿ�Կ� ���� �����ͳ� �����ڸ� �Ļ� Ÿ�Կ� ���� �����ͳ� �����ڷ� �����ϰ� ��ȯ
// const_cast		: const ��ü�� const�� �ƴ� Ÿ������ ��ȯ
// reinterpret_cast : ��Ʈ ���� ������ �����ؿ��� ���ؼ�

#include <iostream>

int main() {
	char *str = "Hello World";

	int *pi = (int*)str;			// <- ĳ������ �����Ϳ� int�� �����ʹ� ���� ����
	char* pc = (char*)*pi;			// <- ���������� ĳ������ �����Ϳ� int�� �����ʹ� ���� ����

	std::cout << pc << std::endl;

	return 0;
}

// ���� �ڵ�� ������ ���� ������ �߻��Ѵ�. �׷��� ->

#include <iostream>

int main() {
	char *str = "Hello World";

	int *pi = static_cast<int*>(str);
	char* pc = static_cast<char*>(pi);

	std::cout << pc << std::endl;

	return 0;
}

// static_cast�� �̿��ϸ� �����Ϸ����� ������ �����Ͽ�
// ���� ������ �̿��� �����Ѵ�
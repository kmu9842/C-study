//#include "MyArrayList.h"


/*
int pibonachi(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	else return pibonachi(n - 1) + pibonachi(n - 2);
}

void main() {
	int n,sum = 0;

	cin >> n;

	for (int i = 0;i<n;i++) {
		cout << pibonachi(i) << " ";
	}

	int a;
	cin >> a;
}

// 6 -> (5)+(4)
// 6 -> (((((1)+(((1)+(0))))+(1))+(((1)+(0))))+((1)+(((1)+(0))+(1))) + (((((1)+(((1)+(0))))+(1))+((1)+(((1)+(0))) */

/*

int BsearchRecur(int ar[], int first, int last, int target) {
	int mid;
	if (first > last) {
		return -1;
	}

	mid = (first + last)/2;
	if (ar[mid] == target) {
		return mid+1;
	}
	else if (ar[mid] > target){
		BsearchRecur(ar, first, mid-=1, target);
	}
	else if (ar[mid] < target) {
		BsearchRecur(ar, mid+=1, last, target);
	}
}

void main() {
	int n, sum = 0;
	int ar[1000];

	for (int i = 1; i <= 1000; i++) {
		ar[i - 1] = i;
	}

	for (int i = 1; i <= 1000; i++) {
		cout << BsearchRecur(ar, 0, 999, i) << "\n";
	}

	//cin >> n;


	int a;
	cin >> a;
}*/
/*
int isCompleteHanoi(int ar1[], int ar2[], int ar3[]) {
	int sw = 0;

	for (int i = 0;i<3;i++) {
		if (ar2[i-1] < ar2[i]){
			sw = 1;
		}
	}
	if (!sw)
}

int Hanoi(int ar1[], int ar2[], int ar3[], int count) {

}

int main() {

}

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define PI 3.141592

int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a*b;
}

int divs(int a, int b) {
	return a/b;
}
float divs(int a, float b) {
	return a / b;
}
float divs(float a, int b) {
	return a / b;
}
float divs(float a, float b) {
	return a / b;
}

int pow(int a, int b) {
	for (int i = 1;i<=b;i++) {
		a *= a;
	}
	return a;
}

int main(void) {
	std::string c; 

	cin >> c;

	float a, b;
	if (c == "add") {
		cin >> a;
		cin >> b;
		cout << add(a,b) << "\n";
	}
	else if (c == "sub") {
		cin >> a;
		cin >> b;
		cout << sub(a, b) << "\n";
	}
	else if (c == "mul") {
		cin >> a;
		cin >> b;
		cout << mul(a, b) << "\n";
	}
	else if (c == "div") {
		cin >> a;
		cin >> b;
		cout << divs(a, b) << "\n";
	}
	else if (c == "pow") {
		cin >> a;
		cin >> b;
		cout << pow(a, b) << "\n";
	}
	else if (c == "sin") {
		cin >> a;
		cout << sin(a * PI / 180.) << "\n";
	}
	else if (c == "cos") {
		cin >> a;
		a = cos(a * PI / 180.);
		a = ((int)(a*pow(10.0, 3)) / pow(10.0, 3));
		cout << a << "\n";
	}

	int d;
	cin >> d;
}*/
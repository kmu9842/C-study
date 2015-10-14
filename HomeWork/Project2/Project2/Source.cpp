/*#include <iostream>

using namespace std;

void main() {
	/*
	int ar[8] = { 0, };
	int money;

	cin >> money;

	for (int i = 1;i<=8;i++) {
		switch (i) {
		case 1: ar[i] = money / 50000; money = money % 50000; break;
		case 2: ar[i] = money / 10000; money = money % 10000; break;
		case 3: ar[i] = money / 5000; money = money % 5000; break;
		case 4: ar[i] = money / 1000; money = money % 1000; break;
		case 5: ar[i] = money / 500; money = money % 500; break;
		case 6: ar[i] = money / 100; money = money % 100; break;
		case 7: ar[i] = money / 50; money = money % 50; break;
		case 8: ar[i] = money / 10; money = money % 10; break;
		}
		
	}

	for (int i = 1; i <= 8; i++) {
		cout << ar[i] << " ";
	}
	int b = 1,tmp = 0,sum = 0;

	for (int i = 1; i <= 10; i++) {

		cout << b << " ";

		sum = tmp + b;
		tmp = b;
		b = sum;
	}
	
	int a;
	cin >> a;


	
	/*
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << i << "*" << j << "=" << i*j << "\t";
		}
		cout << "\n";
	}

	int a;
	cin >> a;
	/*
	int sw = 0;
	float sum = 0;

	for (float i = 1;;i+=2) {
		if (sw%2==0) {
			sum += (float)4 / i;
		}
		else {
			sum -= (float)4 / i;
			
		}
		
		sw++;
		if (sw >= 100000) break;
	}
	cout << sum << "\n";


	/*
	for (int i = (int)'A'; i <= (int)'Z'; i++) {
		cout << (char)i << "\t";
		if ((i - 64) % 5 == 0) {
			cout << "\n";
		}
	}

	

	/*
	int a, tmp,c = 1;

	cin >> a;
	tmp = a;

	while (tmp>=10)
	{
		tmp /= 10;
		c*=10;
	}
	
	while (a>=10) {
		cout << a/c << " ";
		a -= (a/c) * c;
		c /= 10;
	}

	cout << a << "\n";
	cin >> a;

	/*
	char a;
	cin >> a;

	a >= 'A' && a <= 'Z' ? a += 32 : a >= 'a' && a <= 'z' ? a -= 32 : a;;
	
	cout << a << "\n";
	cin >> a;

	/*
	int a[5] = {10,20,30,40,50};
	int b1, b2, b3, b4, b5;
	int i;

	cout << "원소의 값을 출력\n";
	for (i = 0;i<5;i++){
		cout << a[i] << " ";
	}
	cout << "\n";

	cout << "원소의 주소 값을 출력\n";
	for (i = 0; i < 5; i++) {
		cout << &a[i] << " ";
	}
	cout << "\n";

	cout << &b1 << " " << &b2 << " " << &b3 << " " << &b4 << " " << &b5 << " ";
	cout << "\n";

	cout << &b1 << " " << &b1+4 << " " << &b1+8 << " " << &b1+12 << " " << &b1+16 << " ";
	cout << "\n";

	cin >> a[0];
}*/
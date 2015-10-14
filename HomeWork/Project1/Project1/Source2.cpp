//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Student {
//private :
//	string num;
//	string name;
//	int sub1;
//	int sub2;
//	int sub3;
//
//public :
//	Student();
//	Student(string num, string name, int sub1, int sub2, int sub3) {
//		this->num = num;
//		this->name = name;
//		this->sub1 = sub1;
//		this->sub2 = sub2;
//		this->sub3 = sub3;
//	}
//	~Student();
//
//	void setNum(string s)  { num = s; }
//	void setName(string s) { name = s; }
//	void setSub1(int sub)  { sub1 = sub; }
//	void setSub2(int sub)  { sub2 = sub; }
//	void setSub3(int sub)  { sub3 = sub; }
//
//	string getNum()  { return num; }
//	string getName() { return name; }
//	int getSub1()	 { return sub1; }
//	int getSub2()	 { return sub2; }
//	int getSub3()	 { return sub3; }
//
//	int getAvg()	 { return sub1 + sub2 + sub3 / 3; }
//	int getSum()	 { return sub1 + sub2 + sub3; }
//
//	int getMaxSub()	 { return sub1 > sub2 ? sub1 > sub3 ? sub1 : sub3 : sub2 > sub3 ? sub2 : sub3; }
//	int getMinSub()	 { return sub1 < sub2 ? sub1 < sub3 ? sub1 : sub3 : sub2 < sub3 ? sub2 : sub3; }
//
//	void printStudent() {
//		cout << num << " " << name << " " << sub1 << " " << sub2 << " " << sub3 << " " << sub1 + sub2 + sub3 << " " << (sub1+sub2+sub3)/3 << "\n";
//	}
//};
//
//void main() {
//	vector<Student*> students;
//	students.push_back(new Student("GG151001", "��öȣ", 90, 75, 50));
//	students.push_back(new Student("GG151011", "��⼷", 40, 85, 60));
//	students.push_back(new Student("GG151007", "������", 50, 50, 40));
//	students.push_back(new Student("GG151021", "����ȣ", 60, 60, 50));
//	students.push_back(new Student("GG151051", "������", 80, 80, 70));
//
//	for (auto i : students) {
//		i->printStudent();
//	}
//
//	cout << "\n";
//	for (int i = 0; i < 3; i++) {
//		cout << "����" << i + 1 << " ���� = ";
//		int sumSub = 0;
//		int max = 0, min = 100;
//		for (auto j : students) {
//			switch (i) {
//			case 0: 
//				sumSub += j->getSub1(); 
//				if (j->getSub1() > max) max = j->getSub1();
//				if (j->getSub1() < min) min = j->getSub1();
//				break;
//			case 1: 
//				sumSub += j->getSub2(); 
//				if (j->getSub2() > max) max = j->getSub2();
//				if (j->getSub2() < min) min = j->getSub2();
//				break;
//			case 2: 
//				sumSub += j->getSub3(); 
//				if (j->getSub3() > max) max = j->getSub3();
//				if (j->getSub3() < min) min = j->getSub3();
//				break;
//			}
//		}
//		cout << sumSub << "\n";
//
//		cout << "����" << i + 1 << " ��� = " << sumSub/students.size() << "\n";
//		cout << "����" << i + 1 << " �ִ� ���� = " << max << "\n";
//		cout << "����" << i + 1 << " �ּ� ���� = " << min << "\n";
//		cout << "\n";
//	}
//
//	cout << "\n�� �л��� �ִ� ����\n";
//	for (auto i : students) {
//		cout << i->getMaxSub() << " ";
//	}
//	cout << "\n";
//
//	cout << "\n�� �л��� �ּ� ����\n";
//	for (auto i : students) {
//		cout << i->getMinSub() << " ";
//	}
//	cout << "\n";
//
//	cout << "\n�� �л��� ���\n";
//	for (auto i : students) {
//		int c = 1;
//		for (auto j : students) {
//			if (i->getAvg() < j->getAvg()) {
//				c++;
//			}
//		}
//		cout << c << " ";
//	}
//
//	int a;
//	cin >> a;
//}
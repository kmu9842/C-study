//#include <string>
//#include <iostream>
//
//class Person {
//protected :
//	std::string name;
//	int age;
//	bool gender;
//
//public :
//	Person() {};
//	Person(std::string name, int age, bool gender);
//
//	virtual void print();
//};
//
//Person::Person(std::string name, int age, bool gender) {
//	this->name = name;
//	this->age = age;
//	this->gender = gender;
//}
//
//void Person::print() {
//	std::cout << "이름\t: " << name << std::endl;
//	std::cout << "나이\t: " << age << std::endl;
//	std::cout << "성별\t: " << gender << std::endl;
//}
//
//class Employee : public Person{
//protected :
//	std::string no;
//	int salary;
//	std::string department;
//
//public :
//	Employee() {};
//	Employee(std::string name, int age, bool gender, std::string no, int salary, std::string department);
//
//	virtual void print();
//};
//
//Employee::Employee(std::string name, int age, bool gender, std::string no, int salary, std::string department) {
//	this->name = name;
//	this->age = age;
//	this->gender = gender;
//	this->no = no;
//	this->salary = salary;
//	this->department = department;
//}
//
//void Employee::print() {
//	std::cout << "이름\t: " << name << std::endl;
//	std::cout << "나이\t: " << age << std::endl;
//	std::cout << "성별\t: " << gender << std::endl;
//	std::cout << "사번\t: " << no << std::endl;
//	std::cout << "급여\t: " << salary << std::endl;
//	std::cout << "부서\t: " << department << std::endl;
//}
//
//
//class Manager : public Employee {
//protected:
//	int bonus;
//
//public :
//	Manager() {};
//	Manager(std::string name, int age, bool gender, std::string no, int salary, std::string department, int bonus);
//
//	virtual void print();
//};
//
//Manager::Manager(std::string name, int age, bool gender, std::string no, int salary, std::string department, int bonus) {
//	this->name = name;
//	this->age = age;
//	this->gender = gender;
//	this->no = no;
//	this->salary = salary;
//	this->department = department;
//	this->bonus = bonus;
//}
//
//void Manager::print() {
//	std::cout << "이름\t: " << name << std::endl;
//	std::cout << "나이\t: " << age << std::endl;
//	std::cout << "성별\t: " << (int)gender << std::endl;
//	std::cout << "사번\t: " << no << std::endl;
//	std::cout << "급여\t: " << salary << std::endl;
//	std::cout << "부서\t: " << department << std::endl;
//	std::cout << "보너스\t: " << bonus << std::endl;
//}
//
//void main() {
//	Manager manager("손동복",30,true,"101",5000,"인사과",2000);
//	manager.print();
//}
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
//	std::cout << "�̸�\t: " << name << std::endl;
//	std::cout << "����\t: " << age << std::endl;
//	std::cout << "����\t: " << gender << std::endl;
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
//	std::cout << "�̸�\t: " << name << std::endl;
//	std::cout << "����\t: " << age << std::endl;
//	std::cout << "����\t: " << gender << std::endl;
//	std::cout << "���\t: " << no << std::endl;
//	std::cout << "�޿�\t: " << salary << std::endl;
//	std::cout << "�μ�\t: " << department << std::endl;
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
//	std::cout << "�̸�\t: " << name << std::endl;
//	std::cout << "����\t: " << age << std::endl;
//	std::cout << "����\t: " << (int)gender << std::endl;
//	std::cout << "���\t: " << no << std::endl;
//	std::cout << "�޿�\t: " << salary << std::endl;
//	std::cout << "�μ�\t: " << department << std::endl;
//	std::cout << "���ʽ�\t: " << bonus << std::endl;
//}
//
//void main() {
//	Manager manager("�յ���",30,true,"101",5000,"�λ��",2000);
//	manager.print();
//}
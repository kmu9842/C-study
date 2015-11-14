//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Animal {
//private :
//	int age;
//	int weight;
//
//public :
//	//Animal();
//	//Animal(int age, int weight) { this->age = age; this->weight = weight; };
//	virtual ~Animal() {};
//
//	void setAge(int age) { this->age = age; };
//	void setWeight(int weight) { this->weight = weight; };
//
//	virtual int getAge() { return age; };
//	virtual int getWeight() { return weight; };
//
//	virtual void eat() = 0;
//	virtual void print() = 0;
//
//	virtual void sleep();
//};
//
//void Animal::sleep() {
//	cout << "µå¸£··\n";
//}
//
//class Dog : public Animal{
//private :
//	string breed;
//
//public :
//	Dog();
//	Dog(int age, int weight, string breed) { setAge(age);  setWeight(weight); this->breed = breed; };
//
//	void setBreed(string breed) { this->breed = breed; };
//	string getBreed() { return breed; };
//
//	void eat();
//	void speak();
//	void print();
//};
//
//void Dog::eat() {
//	cout << "ÂÁÂÁ\n";
//}
//
//void Dog::speak() {
//	cout << "¿Ð¿Ð\n";
//}
//
//void Dog::print() {
//	cout << "³ªÀÌ : " << Animal::getAge() << "\n¸ö¹«°Ô : " << Animal::getWeight() << "\nÇ°Á¾ : " << breed << endl;
//}
//
//class Bird : public Animal {
//
//public:
//	Bird();
//	Bird(int age, int weight) { setAge(age); setWeight(weight); };
//
//	void eat();
//	void speak();
//	void print();
//};
//
//void Bird::eat() {
//	cout << "± ± \n";
//}
//
//void Bird::speak() {
//	cout << "Â±Â±\n";
//}
//
//void Bird::print() {
//	cout << "³ªÀÌ : " << Animal::getAge() << "\n¸ö¹«°Ô : " << Animal::getWeight() << "\n";
//}
//
//void main() {
//	Dog dog(3,7,"¸»Æ¼Áî");
//
//	dog.print();
//	dog.sleep();
//	dog.speak();
//
//	cout << "--------------------------\n";
//
//	Bird bird(1,3);
//
//	bird.print();
//	bird.sleep();
//	bird.speak();
//}

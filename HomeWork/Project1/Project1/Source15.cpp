//#include <iostream>
//
//class calc {
//public :
//	template <typename t1, typename  t2> auto max(t1 a, t2 b)->decltype(a + b );
//};
//
//class add  : public calc{
//public :
//	template <typename t1, typename  t2> auto max(t1 a, t2 b)->decltype(a + b);
//};
//
//template <typename t1, typename  t2> auto calc::max(t1 a, t2 b)->decltype(a + b) {
//	std::cout << a + b << std::endl;
//	return (a + b ? a : b);
//}
//
//template <typename t1, typename  t2> auto add::max(t1 a, t2 b)->decltype(a + b) {
//	calc::max(a,b);
//	std::cout << a << " + " << b << " = " << a + b << std::endl;
//	return (a + b ? a : b);
//}
//
//void main() {
//	add* a = new add;
//	calc c;
//	//c.max(1, 3.5f);
//	a->max(1, 3.5f);
//}
//
////class ParentClass {
////public:
////	void func() { std::cout << "I am in ParentClass" << std::endl; }
////};
////
////class ChildClass : public ParentClass {
////public:
////	void func() { std::cout << "I am in ChildClass" << std::endl; }
////};
////
////int main() {
////	ChildClass* c = new ChildClass;
////	c->func();
////
////	ParentClass* p = new ParentClass;
////	p->func();
////
////	ParentClass* pc = new ChildClass;
////	pc->func();
////
////	delete c;
////	delete p;
////	delete pc;
////}
//
//

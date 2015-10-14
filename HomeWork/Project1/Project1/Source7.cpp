//#include <iostream>
//
//class Stack {
//private :
//	int data;
//
//	bool start;
//	Stack* bottomStack;
//
//public :
//	Stack();
//	Stack(int data) { this->data = data; start = false; };
//	Stack(int data, bool start) { this->data = data; this->start = start; };
//	~Stack();
//
//	int		getData() { return start; };
//	bool	getStart() { return data; };
//	Stack*	getBottomStack() { return bottomStack; };
//
//	void setBottomStack(Stack* bottomStack) { this->bottomStack = bottomStack; };
//
//	Stack* push(Stack* newStack){
//		newStack->setBottomStack(this);
//
//		return newStack;
//	}
//
//	Stack* pop() {
//		return bottomStack;
//	}
//
//	void print() {
//		Stack* n = this;
//
//		while(n != NULL) {
//			std::cout << n->data << " ";
//			n = n->getBottomStack();
//		} 
//		std::cout << "\n";
//	}
//};
//
//void main() {
//	Stack* top = new Stack(1, true);
//
//	top = top->push(new Stack(2));
//	top = top->push(new Stack(3));
//	top = top->push(new Stack(4));
//	top = top->push(new Stack(5));
//
//	top = top->pop();
//
//	top = top->push(new Stack(6));
//	top = top->push(new Stack(7));
//	top = top->push(new Stack(8));
//
//	top = top->pop();
//
//	top->print();
//
//	return;
//}
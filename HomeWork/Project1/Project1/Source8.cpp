//#include <iostream>
//#include <string>
//
//class Stack {
//private :
//	char data;
//
//	bool start;
//	Stack* bottomStack;
//
//public :
//	Stack();
//	Stack(char data) { this->data = data; start = false; };
//	Stack(char data, bool start) { this->data = data; this->start = start; };
//	~Stack();
//
//	char	getData() { return start; };
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
//	char s[100];
//	Stack* chars = new Stack(0,true);
//	Stack* integers = new Stack(0, true);
//
//	std::cin >> s;
//
//	for (int i = 0; i < strlen(s); i++) {
//		if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*'){
//			chars = chars->push(new Stack(s[i]));
//		}
//		else {
//			integers = integers->push(new Stack(s[i]));
//		}
//	}
//
//	integers->print();
//	chars->print();
//
//	for (int i = 0; i < strlen(s); i++) {
//		
//	}
//
//	return;
//}
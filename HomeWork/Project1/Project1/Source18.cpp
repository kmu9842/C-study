//#include <iostream>
//#include <memory>
//
//#include "Header1.h"
//#include "Header2.h"
//
//using namespace std;
//
//typedef char nodeData;
//
//namespace Tree{
//	class Node {
//	private:
//		bool startNode = false;
//		nodeData data;
//
//		shared_ptr<Node> right;
//		shared_ptr<Node> left;
//
//	public:
//		Node() {};
//		Node(int data) { this->data = data; };
//		Node(int data, bool startNode) { this->data = data; this->startNode = startNode; };
//		~Node() {};
//
//		void setData(nodeData data) { this->data = data; };
//
//		void setRight(shared_ptr<Node> newNdoe) { right = newNdoe; };
//		void setLeft(shared_ptr<Node> newNdoe) { left = newNdoe; };
//
//		bool getIsStartNode() { return startNode; };
//		nodeData getData() { return data; };
//
//		shared_ptr<Node> getRight() { return right; };
//		shared_ptr<Node> getLeft() { return left; };
//	};
//
//	shared_ptr<Node> InputTree(string s, shared_ptr<Node>* node, int* len)
//	{
//		char token = static_cast<char>(s[*len]);        // 마지막 문자 추출
//
//		if (!isdigit(token)) {
//			// 재귀함수를 이용하여 자손 노드를 계속 생성한다.
//			if (*len == s.length() - 1) {
//				(*node) = make_shared<Node>(token, true);
//			}
//			else {
//				(*node) = make_shared<Node>(token);
//			}
//
//			*len -= 1;
//			(*node)->setLeft(InputTree(s, &(*node)->getLeft(), len));
//			(*node)->setRight(InputTree(s, &(*node)->getRight(), len));
//		}
//
//		// 피연산자인경우
//		else {
//			(*node) = make_shared<Node>(token);
//			*len -= 1;
//		}
//
//		return *node;
//	}
//
//	double calcTree(shared_ptr<Node> node)
//	{
//		char temp[2];
//
//		double left = 0;
//		double right = 0;
//		double result = 0;
//
//		if (node == NULL) {
//			return 0;
//		}
//
//		if (!isdigit(node->getData())) {
//			left = calcTree(node->getLeft());
//			right = calcTree(node->getRight());
//
//			if (node->getData() == '+') {
//				result = right + left;
//			}
//			else if (node->getData() == '-') {
//				result = right - left;
//			}
//			else if (node->getData() == '*') {
//				result = right * left;
//			}
//			else if (node->getData() == '/') {
//				result = right / left;
//			}
//		}
//
//		else {
//			memset(temp, 0, sizeof(temp));
//			temp[0] = node->getData();
//			result = atof(temp);
//		}
//
//		return result;
//	}
//
//};
//
//using namespace Tree;
//
//void main() {
//	
//	string inputString;// = "12+7*";
//	string resultString;
//	shared_ptr<Node> Start, a, b;
//
//
//	if (!FileRead(&inputString)) {
//		cout << "File Error!" << endl;
//	}
//	resultString = inputString;
//	Stack::PostExp(&inputString,&resultString);
//
//
//	int num = resultString.length()-1;
//	InputTree(resultString, &Start, &num);
//
//	double result = calcTree(Start);
//	FileWrite(&result);
//}
//
//
//

//#include <iostream>
//#include <memory>
//
//using namespace std;
//
//typedef int nodeData;
//
//class Node {
//private :
//	bool startNode = false;
//	nodeData data;
//
//	shared_ptr<Node> right;
//	shared_ptr<Node> left;
//
//public :
//	Node();
//	Node(int data) { this->data = data; };
//	Node(int data, bool startNode) { this->data = data; this->startNode = startNode; };
//	~Node() {};
//
//	void setData(nodeData data) { this->data = data; };
//
//	void setRight(shared_ptr<Node> newNdoe) { right = newNdoe; };
//	void setLeft(shared_ptr<Node> newNdoe) { left = newNdoe; };
//
//	bool getIsStartNode() { return startNode; };
//	nodeData getData() { return data; };
//
//	shared_ptr<Node> getRight() { return right; };
//	shared_ptr<Node> getLeft() { return left; };
//
//	void printNodeDFS(shared_ptr<Node> node = nullptr);
//	void printNodeBFS(shared_ptr<Node> node = nullptr);
//};
//
//
//void Node::printNodeDFS(shared_ptr<Node> node)
//{
//	if (node == nullptr) {
//		node = static_cast<shared_ptr<Node>>(this);
//	}
//	
//	cout << node->getData() << " ";
//
//	if (node->getRight() != NULL) {
//		printNodeDFS(node->getRight());
//
//		if (node->getLeft() != NULL) {
//			printNodeDFS(node->getLeft());
//		}
//	}
//}
//
//
//void Node::printNodeBFS(shared_ptr<Node> node)
//{
//	if (node == nullptr) {
//		node = static_cast<shared_ptr<Node>>(this);
//	}
//
//	if (node->getIsStartNode()) {
//		cout << node->getData() << " ";
//	}
//	if (node->getRight() != NULL) {
//		cout << node->getRight()->getData() << " ";
//	}
//	if (node->getLeft() != NULL) {
//		cout << node->getLeft()->getData() << " ";
//	}
//
//	if (node->getRight() != NULL) {
//		printNodeBFS(node->getRight());
//		if (node->getLeft() != NULL) {
//			printNodeBFS(node->getLeft());
//		}
//	}
//}
//
//
//void main() {
//	
//	auto Start = make_shared<Node>(1,true);
//
//	Start->setRight(make_shared<Node>(2));
//	Start->setLeft(make_shared<Node>(3));
//	Start->getRight()->setRight(make_shared<Node>(4));
//	Start->getRight()->setLeft(make_shared<Node>(5));
//	Start->getLeft()->setRight(make_shared<Node>(6));
//	Start->getLeft()->setLeft(make_shared<Node>(7));
//	
//	cout << "DFS식 출력 : ";
//	Start->printNodeDFS(Start);
//	cout << endl;
//	cout << "BFS식 출력 : ";
//	Start->printNodeBFS(Start);
//	cout << endl;
//}
//

//#include <memory>
//#include <iostream>
//
//using namespace std;
//
//typedef int nodeData;
//
//class Node {
//private:
//	bool startNode = false;
//	nodeData data;
//
//	//shared_ptr<Node> Parents;
//	shared_ptr<Node> right;
//	shared_ptr<Node> left;
//
//public:
//	Node() { right = nullptr; left = nullptr; };
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
//};
//
//void InsertionHeap(shared_ptr<Node>* Tree,shared_ptr<Node>* newHeap) {
//
//	nodeData tmp;
//
//	if ((*Tree)->getRight() == nullptr) {
//		// 추가 && 비교
//		(*Tree)->setRight(*newHeap);
//
//		if ((*Tree)->getRight()->getData() < (*Tree)->getData()) {
//			tmp = (*Tree)->getRight()->getData();
//			(*Tree)->getRight()->setData((*Tree)->getData());
//			(*Tree)->setData(tmp);
//		}
//
//		return;
//	}
//
//	
//	
//	if ((*Tree)->getLeft() == nullptr) {
//		// 추가 && 비교
//		(*Tree)->setLeft(*newHeap);
//
//		if ((*Tree)->getLeft()->getData() < (*Tree)->getData()) {
//			tmp = (*Tree)->getLeft()->getData();
//			(*Tree)->getLeft()->setData((*Tree)->getData());
//			(*Tree)->setData(tmp);
//		}
//
//		return;
//	}
//
//	
//	if ((*Tree)->getRight() != nullptr && (*Tree)->getLeft() != nullptr) {
//
//		if ((*Tree)->getRight()->getRight() == nullptr || (*Tree)->getRight()->getLeft() == nullptr) {
//			InsertionHeap(&(*Tree)->getRight(), newHeap);
//
//			if ((*Tree)->getRight()->getData() < (*Tree)->getData()) {
//				tmp = (*Tree)->getRight()->getData();
//				(*Tree)->getRight()->setData((*Tree)->getData());
//				(*Tree)->setData(tmp);
//			}
//		}
//
//		else {
//			InsertionHeap(&(*Tree)->getLeft(), newHeap);
//
//			if ((*Tree)->getLeft()->getData() < (*Tree)->getData()) {
//				tmp = (*Tree)->getLeft()->getData();
//				(*Tree)->getLeft()->setData((*Tree)->getData());
//				(*Tree)->setData(tmp);
//			}
//		}
//		
//	}
//}
//
//void printNodeBFS(shared_ptr<Node>* node)
//{
//	if ((*node)->getIsStartNode()) {
//		cout << (*node)->getData() << " ";
//	}
//	if ((*node)->getRight() != nullptr) {
//		cout << (*node)->getRight()->getData() << " ";
//	}
//	if ((*node)->getLeft() != nullptr) {
//		cout << (*node)->getLeft()->getData() << " ";
//	}
//
//	if ((*node)->getRight() != nullptr) {
//		printNodeBFS(&(*node)->getRight());
//		if ((*node)->getLeft() != nullptr) {
//			printNodeBFS(&(*node)->getLeft());
//		}
//	}
//
//	return;
//}
//
//void main() {
//
//	shared_ptr<Node> Start = make_shared<Node>(11,true);
//	
//	InsertionHeap(&Start, &make_shared<Node>(8));
//	InsertionHeap(&Start, &make_shared<Node>(9));
//	InsertionHeap(&Start, &make_shared<Node>(10));
//	InsertionHeap(&Start, &make_shared<Node>(2));
//	InsertionHeap(&Start, &make_shared<Node>(13));
//
//	printNodeBFS(&Start);
//	cout << endl;
//	
//}
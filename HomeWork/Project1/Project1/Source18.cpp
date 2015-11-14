#include <iostream>
#include <memory>

using namespace std;

typedef char nodeData;

class Node {
private :
	bool startNode = false;
	nodeData data;

	shared_ptr<Node> right;
	shared_ptr<Node> left;

public :
	Node() {};
	Node(int data) { this->data = data; };
	Node(int data, bool startNode) { this->data = data; this->startNode = startNode; };
	~Node() {};

	void setData(nodeData data) { this->data = data; };

	void setRight(shared_ptr<Node> newNdoe) { right = newNdoe; };
	void setLeft(shared_ptr<Node> newNdoe) { left = newNdoe; };

	bool getIsStartNode() { return startNode; };
	nodeData getData() { return data; };

	shared_ptr<Node> getRight() { return right; };
	shared_ptr<Node> getLeft() { return left; };

	void printNodeCenter(shared_ptr<Node> node = nullptr);
	void printNodeBack(shared_ptr<Node> node = nullptr);
	void printNodeDFS(shared_ptr<Node> node = nullptr);
	void printNodeBFS(shared_ptr<Node> node = nullptr);

	void calcTree(shared_ptr<Node> node = nullptr);
};

void Node::printNodeCenter(shared_ptr<Node> node)
{
	if (node == nullptr) {
		node = static_cast<shared_ptr<Node>>(this);
	}

	if (node->getRight() != nullptr) {
		printNodeCenter(node->getRight());
		cout << node->getData() << " ";

		if (node->getLeft() != nullptr) {
			printNodeCenter(node->getLeft());
		}

		else {
		}
	}

	else {
		cout << node->getData() << " ";
	}
}

void Node::printNodeBack(shared_ptr<Node> node)
{
	if (node == nullptr) {
		node = static_cast<shared_ptr<Node>>(this);
	}

	if (node->getRight() != nullptr) {
		printNodeBack(node->getRight());

		if (node->getLeft() != nullptr) {
			printNodeBack(node->getLeft());
			cout << node->getData() << " ";
		}

		else {
			cout << node->getData() << " ";
		}
	}

	else {
		cout << node->getData() << " ";
	}
}

void Node::printNodeDFS(shared_ptr<Node> node)
{
	if (node == nullptr) {
		node = static_cast<shared_ptr<Node>>(this);
	}
	
	cout << node->getData() << " ";

	if (node->getRight() != nullptr) {
		printNodeDFS(node->getRight());

		if (node->getLeft() != nullptr) {
			printNodeDFS(node->getLeft());
		}
	}
}

void Node::printNodeBFS(shared_ptr<Node> node)
{
	if (node == nullptr) {
		node = static_cast<shared_ptr<Node>>(this);
	}

	if (node->getIsStartNode()) {
		cout << node->getData() << " ";
	}
	if (node->getRight() != nullptr) {
		cout << node->getRight()->getData() << " ";
	}
	if (node->getLeft() != nullptr) {
		cout << node->getLeft()->getData() << " ";
	}

	if (node->getRight() != nullptr) {
		printNodeBFS(node->getRight());
		if (node->getLeft() != nullptr) {
			printNodeBFS(node->getLeft());
		}
	}
}

void Node::calcTree(shared_ptr<Node> node) {
	if (node == nullptr) {
		node = static_cast<shared_ptr<Node>>(this);
	}
}

void InputTree(string s, shared_ptr<Node>* node, int* stringNum) {

	if (*stringNum == 0) {
		*node = make_shared<Node>(s[*stringNum],true);
	}

	(*stringNum)++;

	if (!isdigit((*node)->getData())) {
		(*node)->setRight(make_shared<Node>(s[*stringNum]));
		InputTree(s, &(*node)->getRight(), stringNum);

		if (!isdigit((*node)->getData())) {
			(*node)->setLeft(make_shared<Node>(s[*stringNum]));
			InputTree(s, &(*node)->getLeft(), stringNum);
		}
	}
	
}

void main() {
	
	string inputString = "-+17*42";

	shared_ptr<Node> Start;
	int num = 0;

	InputTree(inputString,&Start,&num);

	/*
	Start->setRight(make_shared<Node>('+'));
	Start->setLeft(make_shared<Node>('1'));
	Start->getRight()->setRight(make_shared<Node>('7'));
	Start->getRight()->setLeft(make_shared<Node>('*'));
	Start->getRight()->getLeft()->setRight(make_shared<Node>('4'));
	Start->getRight()->getLeft()->setLeft(make_shared<Node>('2'));*/

	// cout << "DFS식 출력 : ";
	// Start->printNodeDFS(Start);
	// cout << endl;
	cout << "전위식 출력 : ";
	Start->printNodeBFS(Start);
	cout << endl;
	cout << "중위식 출력 : ";
	Start->printNodeCenter(Start);
	cout << endl;
	cout << "후위식 출력 : ";
	Start->printNodeBack(Start);
	cout << endl;
}


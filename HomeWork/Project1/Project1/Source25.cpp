#include <iostream>
#include <string>

typedef int nodeData;

class Node {
private :
	nodeData data;
	Node* nextNode = nullptr;

public :
	Node() {};
	Node(int data) { this->data = data; };
	~Node() {};

	void setNextNode(Node* nextNode) { this->nextNode = nextNode; };
	void setData(nodeData data) { this->data = data; };

	Node* getNextNode() { return nextNode; };
	nodeData getData() { return data; };

	void insertNode(Node* newNode, Node* startnode = nullptr);
	void deleteNode(nodeData removeNode, Node* startnode = nullptr);
	//void deleteNode() { delete this; };

	void print(Node* node = nullptr);

	Node* end();
	int tailNodeCount();
};
void Node::insertNode(Node* newNode, Node* startnode)
{
	if (startnode == nullptr) {
		startnode = this;
	}

	if (startnode->getNextNode() != nullptr){
		insertNode(newNode, startnode->getNextNode());
	}
	else {
		startnode->setNextNode(newNode);
	}
}
void Node::deleteNode(nodeData removeNode, Node* startnode)
{
	if (startnode == nullptr) {
		startnode = this;
	}

	if (removeNode == startnode->nextNode->getData()) {
		startnode->setNextNode(nullptr);
	}
	else {
		deleteNode(removeNode, startnode->getNextNode());
	}
}
void Node::print(Node* node)
{
	if (node == nullptr) {
		node = this;
	}

	if (node->getNextNode() != nullptr) {
		std::cout << node->getData() << " ";
		print(node->getNextNode());
	}
	else {
		std::cout << node->getData() << " ";
		return;
	}
}

Node * Node::end()
{
	Node* node = this;

	while (node->getNextNode() != nullptr) {
		node = node->getNextNode();
	} 

	return node;
}

int Node::tailNodeCount()
{
	int cnt = 1;
	Node* node = this;

	while (node->getNextNode() != nullptr) {
		node = node->getNextNode();
		cnt++;
	}

	return cnt;
}

Node* sort_partion(Node* start, Node* pivot, Node* big, Node* small);
Node* sort_quick(Node* start) {

	Node *left, *right;

	left = new Node();
	right = new Node();

	return sort_partion(start, start->end(), left, right);
}

Node* sort_partion(Node* start, Node* pivot, Node* big, Node* small) {

	Node* node = new Node();

	node = start;

	while (node != pivot) {
		if (node->getData() >= pivot->getData()) {
			Node* newNode = node;
			big->end()->setNextNode(newNode);
			node = node->getNextNode();
			newNode->setNextNode(nullptr);
		}
		else {
			Node* newNode = node;
			small->end()->setNextNode(newNode);
			node = node->getNextNode();
			newNode->setNextNode(nullptr);
		}
	}

	small = small->getNextNode();
	big = big->getNextNode();

	if (small != nullptr) {
		if (small->tailNodeCount() >= 3) {
			small = sort_quick(small);
		}

		else if (small->tailNodeCount() == 2) {
			if (small->getData() > small->getNextNode()->getData()) {
				int tmp;

				tmp = small->getData();
				small->setData(small->getNextNode()->getData());
				small->getNextNode()->setData(tmp);
			}

		}
	}

	if (big != nullptr) {
		if (big->tailNodeCount() >= 3) {
			big = sort_quick(big);
		}

		else if (big->tailNodeCount() == 2) {
			if (big->getData() > big->getNextNode()->getData()) {
				int tmp;

				tmp = big->getData();
				big->setData(big->getNextNode()->getData());
				big->getNextNode()->setData(tmp);
			}
		}
	}

	// �ڸ� ����Ʈ ��ġ��
	if (small == nullptr) {
		pivot->setNextNode(big);
		small = pivot;
	}
	else if (big == nullptr) {
		small->end()->setNextNode(pivot);
	}
	else {
		small->end()->setNextNode(pivot);
		pivot->setNextNode(big);
	}

	return small;
}

void main() {
	Node* start = new Node(3);

	start->insertNode(new Node(1));
	start->insertNode(new Node(6));
	start->insertNode(new Node(2));
	start->insertNode(new Node(5));
	start->insertNode(new Node(4));

	start = sort_quick(start);

	start->print();
	std::cout << std::endl;

	return;
}

//3 1 6 5 2 4
//
//�ǹ� 4
//->ŭ�� 	6 5
//- �迭�� ���̰� 2����.�迭�� ���̰� 2�� ��� ���� ��ġ�� �˻��Ͽ� �ٲ��� �� ����.
//
//->������	3 1 2
//�ǹ� 2
//->ŭ��	  3
//->������ 1
//->���� �迭�� ���̰� 2����.����.
//
//sort_partition�� �ǹ��� ������ ���� �迭�� �޾� ū����Ʈ�� ���� ����Ʈ�� ����.
//->�Ϸ���� �ٽ� sort_quick�� �ߵ����� ū ����Ʈ�� ���� ����Ʈ�� �ѹ��� ����.
//->�ش� �Լ�ó���� ������� ����Ʈ���� ����.
//
//sort_quick�� �������� �޾� sort_partion�� ����.

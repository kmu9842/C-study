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

	// 자른 리스트 합치기
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
//피벗 4
//->큼에 	6 5
//- 배열의 길이가 2이하.배열의 길이가 2일 경우 둘의 위치를 검사하여 바꿔준 후 리턴.
//
//->작음에	3 1 2
//피벗 2
//->큼에	  3
//->작음에 1
//->둘의 배열의 길이가 2이하.종료.
//
//sort_partition은 피벗과 오른쪽 왼쪽 배열을 받아 큰리스트와 작은 리스트로 나눔.
//->완료된후 다시 sort_quick을 발동시켜 큰 리스트와 작은 리스트를 한번씩 넣음.
//->해당 함수처리가 끝날경우 리스트들을 연결.
//
//sort_quick은 시작점을 받아 sort_partion을 실행.

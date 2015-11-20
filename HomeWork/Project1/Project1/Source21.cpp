//#include <iostream>
//#include <memory>
//
//using namespace std;
//
//typedef char nodeData;
//
//class Node {
//private:
//	bool startNode = false;
//	nodeData data;
//
//	shared_ptr<Node> right;
//	shared_ptr<Node> left;
//
//public:
//	Node() {};
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
//	void printNodeCenter(shared_ptr<Node> node = nullptr);
//	void printNodeBack(shared_ptr<Node> node = nullptr);
//	void printNodeDFS(shared_ptr<Node> node = nullptr);
//	void printNodeBFS(shared_ptr<Node> node = nullptr);
//};
//
//void Node::printNodeCenter(shared_ptr<Node> node)
//{
//	if (node == nullptr) {
//		node = static_cast<shared_ptr<Node>>(this);
//	}
//
//	if (node->getRight() != nullptr) {
//		printNodeCenter(node->getRight());
//		cout << node->getData() << " ";
//
//		if (node->getLeft() != nullptr) {
//			printNodeCenter(node->getLeft());
//		}
//
//		else {
//		}
//	}
//
//	else {
//		cout << node->getData() << " ";
//	}
//}
//
//void Node::printNodeBack(shared_ptr<Node> node)
//{
//	if (node == nullptr) {
//		node = static_cast<shared_ptr<Node>>(this);
//	}
//
//	if (node->getRight() != nullptr) {
//		printNodeBack(node->getRight());
//
//		if (node->getLeft() != nullptr) {
//			printNodeBack(node->getLeft());
//			cout << node->getData() << " ";
//		}
//
//		else {
//			cout << node->getData() << " ";
//		}
//	}
//
//	else {
//		cout << node->getData() << " ";
//	}
//}
//
//void Node::printNodeDFS(shared_ptr<Node> node)
//{
//	if (node == nullptr) {
//		node = static_cast<shared_ptr<Node>>(this);
//	}
//
//	cout << node->getData() << " ";
//
//	if (node->getRight() != nullptr) {
//		printNodeDFS(node->getRight());
//
//		if (node->getLeft() != nullptr) {
//			printNodeDFS(node->getLeft());
//		}
//	}
//}
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
//	if (node->getRight() != nullptr) {
//		cout << node->getRight()->getData() << " ";
//	}
//	if (node->getLeft() != nullptr) {
//		cout << node->getLeft()->getData() << " ";
//	}
//
//	if (node->getRight() != nullptr) {
//		printNodeBFS(node->getRight());
//		if (node->getLeft() != nullptr) {
//			printNodeBFS(node->getLeft());
//		}
//	}
//}
//
//shared_ptr<Node> InputTree(string s, shared_ptr<Node>* node, int* len)
//{
//	char token = static_cast<char>(s[*len]);        // ������ ���� ����
//
//	switch (token)
//	{
//		// �������� ���
//	case '+':
//	case '-':
//	case '*':
//	case '/':
//		// ����Լ��� �̿��Ͽ� �ڼ� ��带 ��� �����Ѵ�.
//		if (*len == s.length() - 1) {
//			(*node) = make_shared<Node>(token, true);
//		}
//		else {
//			(*node) = make_shared<Node>(token);
//		}
//
//		*len -= 1;
//		(*node)->setLeft(InputTree(s, &(*node)->getLeft(), len));
//		(*node)->setRight(InputTree(s, &(*node)->getRight(), len));
//		break;
//
//		// �ǿ������ΰ��
//	default:
//		(*node) = make_shared<Node>(token);
//		*len -= 1;
//		break;
//	}
//
//	return *node;
//}
//
//double calcTree(shared_ptr<Node> node)
//{
//
//	char temp[2];
//
//	double left = 0;
//	double right = 0;
//	double result = 0;
//
//	if (node == NULL)
//		return 0;
//
//	switch (node->getData())
//	{
//		// �������� ���
//	case '+':
//	case '-':
//	case '*':
//	case '/':
//		left = calcTree(node->getLeft());
//		right = calcTree(node->getRight());
//
//		if (node->getData() == '+')
//			result = right + left;
//		else if (node->getData() == '-')
//			result = right - left;
//		else if (node->getData() == '*')
//			result = right * left;
//		else if (node->getData() == '/')
//			result = right / left;
//
//		break;
//
//		// �ǿ������� ���
//	default:
//		memset(temp, 0, sizeof(temp));
//		temp[0] = node->getData();
//		// ���ڿ��� �Ǽ��� ��ȯ
//		result = atof(temp);
//		break;
//	}
//
//	return result;
//}
//
//void main() {
//
//	string inputString = "12+7*";
//
//	shared_ptr<Node> Start, a, b;
//	int num = inputString.length() - 1;
//
//	InputTree(inputString, &Start, &num);
//
//	cout << "������ ��� : ";
//	Start->printNodeBFS(Start);
//	cout << endl;
//	cout << "������ ��� : ";
//	Start->printNodeCenter(Start);
//	cout << endl;
//	cout << "������ ��� : ";
//	Start->printNodeBack(Start);
//	cout << endl;
//	cout << calcTree(Start) << endl;
//}
//
//
//

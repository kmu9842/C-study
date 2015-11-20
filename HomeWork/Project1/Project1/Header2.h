#pragma once

#include <string>

#define MAX_SIZE_STACK 100
#define FALSE 0
#define TRUE 0

namespace Stack {

	// ���� ǥ����� ���� ǥ������� ��ȯ�Ѵ�
	// �ǿ����ڴ� ������ ����Ѵ�
	// �������� ��쿡�� �켱������ ���� �����Ѵ�

	typedef int nodeData;
	typedef struct {
		nodeData stack[MAX_SIZE_STACK];
		int top;
	}Node;

	void init(Node *s) {
		s->top = -1;
	}

	int is_empty(Node *s) {
		return s->top == -1;
	}

	int is_full(Node *s) {
		return s->top == MAX_SIZE_STACK - 1;
	}

	void push(Node *s, nodeData item) {
		if (is_full(s))
			exit(1);
		s->stack[++(s->top)] = item;
	}

	nodeData pop(Node *s) {
		if (is_empty(s))
			exit(1);
		return s->stack[(s->top)--];
	}

	nodeData peek(Node *s) {
		if (is_empty(s))
			exit(1);
		return s->stack[s->top];
	}

	// �켱���� ��ȯ �޼���
	int prec(char op) {
		switch (op) {
		case '(': case ')': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		}
		return -1;
	}



	void PostExp(std::string* exp, std::string* exp2) {
		int i, j = 0, count = 0;
		//char exp3[100] = { 0, };
		char ch, top_op;
		int len = (*exp).length();

		Node s;
		init(&s);

		for (i = 0; i < len; i++) {
			ch = (int)(*exp)[i];

			switch (ch) {
			case '+': case '-': case '*': case '/': // �������� ���

													// �ڽź��� �켱 ������ ���� ����
													// Stack�� ���� ��� � ���ش�
				while (!is_empty(&s) && prec(peek(&s)) >= prec(ch)) {
					top_op = pop(&s);
					(*exp2)[count] = top_op;
					count++;
				}
				push(&s, ch);
				break;

				// ��ȣ�� ���
			case '(':
				push(&s, ch);
				break;

			case ')':
				top_op = pop(&s);
				while (top_op != '(') {
					(*exp2)[count] = top_op;
					count++;
					top_op = pop(&s);
				}
				break;

				// �ǿ������� ���
			default:
				(*exp2)[count] = ch;
				count++;
				break;
			}
		}

		while (!is_empty(&s)) {
			(*exp2)[count] = pop(&s);
			count++;
		}

		int c = 0;
		for (i = 0; i < len; i++) {
			if ((*exp)[i] == '(' || (*exp)[i] == ')') {
				c++;
			}
		}

		

		for (i = len-1; i >= len - c; i--) {
			(*exp2).pop_back();
		}
			
		
	}

}

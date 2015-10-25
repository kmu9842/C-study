#pragma once


typedef struct _node
{
	int data;
	struct _node * next;
} Node;

typedef struct Stack
{
	char str[100];
	Node *head;
};

int SPop(Stack * pstack)
{
	int rdata;
	Node * rnode;

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

void SPush(Stack * pstack, int data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

void ResultfromData(char** exp2, int* Res)
{
	int i = 0, j = 0;
	bool icheck;
	int strl;
	Stack stack;
	char op1, op2;

	while (exp2[i] != '\0')
	{
		strl = strlen(exp2[i]);
		for (j = 0; j < strl; j++)
		{
			icheck = isdigit(exp2[i][j]);
			if (icheck)
			{
				SPush(&stack, exp2[i][j] - '0');
			}
			else
			{
				op2 = SPop(&stack);
				op1 = SPop(&stack);
				switch (exp2[0][j])
				{
				case '+':
					SPush(&stack, op1 + op2);
					break;
				case '-':
					SPush(&stack, op1 - op2);
					break;
				case '*':
					SPush(&stack, op1*op2);
					break;
				case '/':
					SPush(&stack, op1 / op2);
					break;
				}
			}
		}
		Res[i] = SPop(&stack);
		i++;
	}

	Res[i] = { 0, };
}

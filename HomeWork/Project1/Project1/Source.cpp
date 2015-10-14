/*
#include <stdio.h>
#include <stdlib.h> // malloc 함수를 사용하기 위해
#include <string.h> // strcpy 함수를 사용하기 위해

typedef struct _node
{
	int key;
	struct _node *next;
} node;

node *head, *tail;

void init_list(void)
{
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->next = tail;
	tail->next = tail;
}

int delete_next(node *t) {
	node *s;
	if (t->next == tail) {
		return 0;
	}

	s = t->next;
	t->next = t->next->next;
	free(s);
	return 1;
}

node *insert_after(int k, node* t)
{
	node *s;
	s = (node*)malloc(sizeof(node));
	s->key = k;
	s->next = t->next;
	t->next = s;
	return s;
}

node *find_node(int k) 
{
	node *s;
	s = head->next;
	while (s->key != k && s != tail) {
		s = s->next;
	}
	return s;
}

int delete_node(int k)
{
	node *s;
	node *p;
	p = head;
	s = p->next;

	bool sw;

	while (s != tail) {
		if (s->key == k) /* if find  {
			p->next = s->next;
			free(s);
			sw = true;
		}
		p = p->next;
		s = p->next;
		
		
	}
	
	if (sw) {
		return 1;
	}
	else {
		return 0;
	}
}

node *insert_node(int t, int k) 
{
	node *s;
	node *p;
	node *r;
	p = head;
	s = p->next;
	while (s->key != k && s != tail) {
		p = p->next;
		s = p->next;
	}
	if (s != tail) {
		r = (node*)malloc(sizeof(node));
		r->key = t;
		p->next = r;
		r->next = s;
	}

	return p->next;
}

node *ordered_insert(int k)
{
	node *s;
	node *p;
	node *r;
	p = head;
	s = p->next;
	while (s->key <= k && s != tail) {
		p = p->next;
		s = p->next;
	}
	r = (node*)malloc(sizeof(node));
	r->key = k;
	p->next = r;
	r->next = s;
	return r;
}

void print_list(node* t)
{
	printf("\n");
	while (t != tail) {
		printf("%-8d",t->key);
		t = t->next;
	}
}

node *delete_all(void) 
{
	node *s;
	node *t;

	t = head->next;

	while (t != tail) {
		s = t;
		t = t->next;
		free(s);
	}

	head->next = tail;
	return head;
}

void main() {
	node *t;

	init_list();
	ordered_insert(10);
	ordered_insert(5);
	ordered_insert(8);
	ordered_insert(3);
	ordered_insert(1);
	ordered_insert(7);
	ordered_insert(8);

	printf("\nInitial Linked list is ");
	print_list(head->next);

	printf("\nFinding 4 is %ssuccessful", find_node(4) == tail ? "un" : "");

	t = find_node(5);
	printf("\nFinding 5 is %ssuccessful", t == tail ? "un" : "");

	printf("\nInserting 9 after 5");
	insert_after(9, t);
	print_list(head->next);

	t = find_node(10);
	printf("\nDeleting next last node");
	delete_next(t);
	print_list(head->next);

	t = find_node(3);
	printf("\nDeleting next 3");
	delete_next(t);
	print_list(head->next);

	printf("\nInsert node 2 before 3");
	insert_node(2, 3);
	print_list(head->next);

	printf("\nDeleting node 8");
	if (!delete_node(8))
		printf("\n deleting 8 is unsuccessful");
	print_list(head->next);

	printf("\nDeleting node 1");
	delete_node(1);
	print_list(head->next);

	printf("\nDeleting all node");
	delete_all();
	print_list(head->next);

	
	int a = 1;
	int &&b = 2;
	b = a;
	std::cout << &b << "\n";
	
	int e;
	scanf_s("%d",&e);
}
/*
typedef struct STUDENT {
	int num;
	char name[100];

	STUDENT* next;
} Lstudent;

Lstudent *head = NULL;

void istudent(Lstudent *in) {
	in->next = head;
	head = in;
}

void pstudent() {
	Lstudent* temp = head;
	while (temp != NULL) {
		printf("num : %d  name : %s\n",temp->num,temp->name);
		temp = temp->next;
	}
}

void dstudent() {
	while (head != NULL) {
		printf("%d의 자료를 삭제합니다\n", head->num);
		head = head->next;
	}
}

void main() {
	char StringTemp[100];
	Lstudent* temp;
	////////////////////////////////////////////////////////
	// 빠른 테스트를 위해 작성한 소스 코드 
	for (int i = 0; i< 10; i++) {
		temp = (Lstudent*)malloc(sizeof(Lstudent));
		temp->num = i + 1;
		sprintf_s(StringTemp, "Person%2d", i + 1);
		strcpy_s(temp->name, strlen(StringTemp) + 1, StringTemp);
		istudent(temp);
	}
	/////////////////////////////
	/*
	// 원래 요구하는 프로그램 소스 코드
	int i = 0;
	while (i < 10) {
	i++;
	printf("이름 : ");
	scanf_s("%s", StringTemp,100);
	(       D       )
	temp->num = i;
	strcpy_s(temp->name, strlen(StringTemp) + 1, StringTemp);
	istudent(temp);
	}
	
	pstudent();
	dstudent();

	int a;
	scanf_s("%d",&a);
}*/
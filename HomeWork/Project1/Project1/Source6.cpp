//#include <stdio.h> 
//#include <stdlib.h> 
//
//typedef struct NODE
//{
//	int data;
//	NODE *link;
//}NODE;
//
//NODE* Create_Node(int data)
//{
//	NODE *New_Node = (NODE*)malloc(sizeof(NODE));
//	if (New_Node == NULL)
//	{
//		puts("�޸� �Ҵ� ����");
//		exit(1);
//	}
//
//	New_Node->data = data;
//	New_Node->link = NULL;
//
//	return New_Node;
//}
//
//void Insert_First(NODE **pHead, NODE *New_Node) // ����Ʈ ó���� �����ϴ� �Լ� 
//{
//	if (*pHead == NULL)
//	{
//		*pHead = New_Node;
//		New_Node->link = New_Node;
//	}
//	else
//	{
//		New_Node->link = (*pHead)->link;
//		(*pHead)->link = New_Node;
//	}
//}
//
//void Insert_Last(NODE **pHead, NODE *New_Node) // ����Ʈ �������� �����ϴ� �Լ� 
//{
//	if (*pHead == NULL)
//	{
//		*pHead = New_Node;
//		New_Node->link = New_Node;
//	}
//	else
//	{
//		New_Node->link = (*pHead)->link;
//		(*pHead)->link = New_Node;
//		*pHead = New_Node;
//		// ���ο� ���� pHead�� ������ �ִ� link�� ����Ű�� �ϰ� 
//		// pHead�� ���ο� ��带 ����Ű�� �Ѵ�. 
//		// pHead�� ���ο� ���� �����Ѵ�. �ᱹ ������ �ȴ�. 
//	}
//}
//
//void Display_Node(NODE *list)
//{
//	NODE *p = list;
//
//	if (list == NULL) return;
//
//	do
//	{
//		printf("%d-> ", p->data);
//		p = p->link; // p == list �� ���� ������ do~while�� �ݺ��Ͽ��� ��
//	} while (p != list);
//
//	printf("\n");
//}
//
//int main()
//{
//	NODE *list = NULL;
//	NODE *p = NULL;
//	NODE *recv_list = NULL;
//
//	Insert_First(&list, Create_Node(10)); 
//	Insert_Last(&list, Create_Node(20));  
//	Insert_Last(&list, Create_Node(30));  
//	Insert_First(&list, Create_Node(5));  // ����� ������ ����
//
//	Display_Node(list); // 30->5->10->20  
//
//	return 0;
//}
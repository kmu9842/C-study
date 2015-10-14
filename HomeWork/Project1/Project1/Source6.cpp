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
//		puts("메모리 할당 에러");
//		exit(1);
//	}
//
//	New_Node->data = data;
//	New_Node->link = NULL;
//
//	return New_Node;
//}
//
//void Insert_First(NODE **pHead, NODE *New_Node) // 리스트 처음에 삽입하는 함수 
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
//void Insert_Last(NODE **pHead, NODE *New_Node) // 리스트 마지막에 삽입하는 함수 
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
//		// 새로운 노드는 pHead가 가지고 있던 link를 가리키게 하고 
//		// pHead는 새로운 노드를 가리키게 한다. 
//		// pHead를 새로운 노드로 변경한다. 결국 원형이 된다. 
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
//		p = p->link; // p == list 는 같기 때문에 do~while로 반복하여야 함
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
//	Insert_First(&list, Create_Node(5));  // 출력은 헤드부터 시작
//
//	Display_Node(list); // 30->5->10->20  
//
//	return 0;
//}
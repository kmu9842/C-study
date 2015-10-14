#include "MyArrayList.h"

void InitSub(CLASS* sub) {
	sub->count = 0;
	/*
	for (int i = 0;i<sub->count;i++) {
	STUDENT a;
	sub->sub[i] = a;
	}*/
}

void AddStudent(CLASS* cl, int num) {
	cl->sub[cl->count].num = num;
	cl->count++;
}

void DelStudent(CLASS* cl, int num) {
	int i;
	for (i = 0; i < cl->count; i++) {
		if (cl->sub[i].num == num) {
			break;
		}
	}

	for (; i < cl->count; i++) {
		cl->sub[i] = cl->sub[i + 1];

	}
}

void PrintStudent(CLASS* cl) {
	for (int i = 0; i < cl->count; i++) {
		printf("cl : subject[%d].num : %d\n", i, cl->sub[i].num);
	}
}
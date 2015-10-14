#ifndef __MYARRYLIST__
#define __MYARRYLIST__

#include <stdio.h>

typedef struct _Student {
	int num;
	int tel;
} STUDENT;

typedef struct _Class {
	int count;
	STUDENT sub[100];
} CLASS;

void InitSub(CLASS* sub);
void AddStudent(CLASS* cl, int num);
void DelStudent(CLASS* cl, int num);
void PrintStudent(CLASS* cl);

#endif 
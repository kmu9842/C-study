
#pragma once

#include "Header1.h"
#include "Header.h"
#include "Header2.h"

void main() {
	char *exp1[100];
	char *exp2[100] = {0,};
	int Result[100];
	int Totalline = 0;

	Totalline = FileRead(exp1);
	for (int i = 0; i < Totalline; i++)
		printf("%s\n", exp1[i]);

	PostExp(exp1, exp2);
	for (int i = 0; i < Totalline; i++)
		printf("%s\n", exp2[i]);

	ResultfromData(exp2, Result);
	for (int i = 0; i < Totalline; i++)
		printf("%d\n", Result[i]);

	FileWrite(Result);

	return;
}
#pragma once

#include <iostream>
#include <stdio.h>

int FileRead(char** exp) {
	int i, line;
	char a[100];
	FILE* fp;
	fopen_s(&fp, "in.txt", "r");
	fscanf_s(fp, "%d", &line);
	
	for (i = 0;i<line; i++) {
		exp[i] = (char*)malloc(sizeof(char));
		fgets(a, 100, fp);
		fgets(exp[i], 100, fp);
	}
	exp[i] = (char*)malloc(sizeof(char));
	exp[i] = { 0, };

	fclose(fp);

	return line;
}

void FileWrite(int *res) {
	FILE* fp;
	fopen_s(&fp, "out.txt", "w");
	int i = 0;
	while (res[i] != NULL) {
		fprintf(fp,"%d",res[0]);
		i++;
	}

	fclose(fp);
}
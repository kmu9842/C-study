//#pragma once
//
//#include <fstream>
//#include <iostream>
//
//int FileRead(char** exp) {
//	int i;
//	std::ifstream in("in.txt");
//
//	for (i = 0;; i++) {
//		exp[i] = (char*)malloc(sizeof(char));
//		in >> exp[i];
//
//		if (*exp[i] == NULL) {
//			break;
//		}
//	}
//
//	in.close();
//
//	return i;
//}
//
//void FileWrite(int * res) {
//	std::ofstream out("out.txt");
//
//	out << *res;
//}
//
//void main() {
//	char* exp[100] = {0,};
//
//	int totalline = 0;
//
//	totalline = FileRead(exp);
//	FileWrite(&totalline);
//}
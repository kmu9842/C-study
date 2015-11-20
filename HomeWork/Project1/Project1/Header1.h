#pragma once

#include <fstream>
#include <string>

int FileRead(std::string* s) {

	std::ifstream in("in.txt");

	in >> *s;

	in.close();

	return true;
}

void FileWrite(double *res) {
	std::ofstream out("out.txt");

	out << *res;

	out.close();
}
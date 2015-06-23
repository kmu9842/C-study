#include <iostream>
#include "Database.h"

using namespace std;
using namespace Records;
int main() {
	
	Database db;
	Empolyee& emp1 = db.addEmpolyee("Gerg", "Wallis");
	emp1.fire();
	Empolyee& emp2 = db.addEmpolyee("Scott", "Kleper");
	emp2.setSalary(100000);
	Empolyee& emp3 = db.addEmpolyee("Nick", "Soolter");
	emp3.setSalary(10000);

	emp3.poromote();

	cout << "all employees : " << endl;
	cout << endl;
	db.displayAll();

	cout << "current employees : " << endl;
	cout << endl;
	db.displayCurrnet();

	cout << "former employees : " << endl;
	cout << endl;
	db.displayFormer();

	return 0;
}
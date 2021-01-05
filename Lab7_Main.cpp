#include <iostream>
#include <string>
#include "Lab7_Class.h"

int main(){
	cout << "PART ONE: " << endl << endl;
	// Create a person/student/intern and initialize
	person_c Person("Arioch", "Boston", 25, 9, 1911);
	Person.print();
//	cout << Person.getName() << endl;

	cout << endl;

	student_c Student("notArioch","notFromBoston",4,5,2000,"WIT", "BELM",1,4,2024);
	Student.print();
//	cout << Student.getMajor() << endl;
//	cout << Student.getName() << endl;

	cout << endl;

	intern_c Intern("definitelyNotArioch","definitelyNotFromBoston", 6,10,1996,"WIT","BSEE",1,4,2022,"Raytheon","Radar Analyst");
	Intern.print();
//	cout << Intern.getName() << endl;
//	cout << Intern.getPlace() << endl;
//	cout << Intern.getYearOB() << endl;

	cout << endl << " ------------ " << endl;
	cout << "PART TWO:" << endl;
	// Create an array of person pointers (6 of them) - use new to create 2 of each object type - make sure to call constructor with inputs (just hard-coded)
	person_c *peopleArray[6] = {
                new person_c("Arioch", "Boston", 25, 9, 1911),
                new person_c("Wentworth", "Dover", 13, 6, 1813), // This man is a dedicated vampire
		new student_c("notArioch","notInBoston",4,5,2000,"WIT", "BELM",1,4,2024),
                new student_c("notWentworth","notFromDover",4,5,2000,"WIT", "BSEE",1,4,2022),
		new intern_c("definitelyNotArioch","definitelyNotInBoston", 6,10,1996,"WIT","BSEE",1,4,2018,"Raytheon","Radar Analyst"),
                new intern_c("definitelyWenworth","definitelyNotFromDover", 10,4,1993,"WIT","BSME",1,4,2015,"Raytheon","Radar Analyst")
	};

	cout << endl;
	// Print each element
	for(int i = 0; i < 6; i++) {peopleArray[i]->print();}

//	cout << peopleArray[0]->getName() << endl;
	cout << endl;

	// delete all array elements that we used "new"
	for(int i=0; i < 6; i++){delete peopleArray[i];}
	//return 0; // Works ok without
}

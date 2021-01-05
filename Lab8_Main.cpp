#include<iostream>
#include<string>
#include<cstdlib>
#include<list>
#include<algorithm>
#include "Lab8_Class.h"

using namespace std;

int menu(){
	cout << "Would you like to: \n";
	cout << "1 - Print current list\n";
	cout << "2 - Add a name\n";
	cout << "3 - Remove a name\n";
	cout << "4 - Search for a name\n";
	cout << "5 - Exit\n";

	int choice = 0;
	cin >> choice;
	return choice;
}

void printList(list<thePerson_c>&);
void addToList(list<thePerson_c>&);
void removeFromList(list<thePerson_c>&);
void searchList(list<thePerson_c>&);

int main(){

	int choice;
        list<thePerson_c> personList;

	do{
		choice = menu();
		if(choice == 1) {printList(personList);}
		if(choice == 2) {addToList(personList);}
		if(choice == 3) {removeFromList(personList);}
		if(choice == 4) {searchList(personList);}
		if(choice == 5) {break;}


	} while(choice != 5);
	return 0;
}
// Inspired by programminghelporg (YouTube)
void printList(list<thePerson_c>& personsList) {
	list<thePerson_c>::iterator it;
	for(it = personsList.begin(); it != personsList.end(); it++) {
		cout << "Name: " << (it)->getName() << " " << (it)->getLName() << endl;
		cout << "Location: " << (it)->getPlace() << endl;
		cout << "DOB: " << (it)->getDayOB() << "/" << (it)->getMonOB() << "/"
			<< (it)->getYearOB() << endl;
		cout << "Age: " << (it)->calculateAge() << " years" << endl;
		cout << "Title: " << (it)->getTitle() << endl;
		cout << "Division: " << (it)->getDivision() << endl;
		cout << endl;
	}
	return;
}
// Inspired by programminghelporg (YouTube)
void addToList(list<thePerson_c>& personsList) {
	string c;
	int d;
	int m;
	int y;
	string n;
	string ln;
	string title;
	string division;
	string blank;

	cout << "Please enter the first name: "; cin >> n;
	cout << "Please enter the last name: "; cin >> ln;
	cout << "Please enter job title: "; cin >> title;
	cout << "Please enter division: "; cin >> division;
	cout << "Please enter day of birth: "; cin >> d;
	cout << "month: "; cin >> m;
	cout << "year: "; cin >> y;
	cout << "Please enter the city: "; cin >> c;
	cout << endl;

	thePerson_c newPerson(c, d, m, y, n, ln, title, division);
	personsList.push_back(newPerson);

	return;
}

void removeFromList(list<thePerson_c>& personsList) {
	string deleteName;
	string deleteLast;
	cout << "Enter first name to delete: "; cin >> deleteName;
	cout << "Enter last name: "; cin >> deleteLast;

	list<thePerson_c>::iterator it;
	for(it = personsList.begin(); it != personsList.end(); it++) {
		if((it)->getName() == deleteName && (it)->getLName() == deleteLast) {personsList.erase(it); break;}
	}
	return;
}

void searchList(list<thePerson_c>& personsList) {
	string leName;
	string lsName;
	bool found = 0;
	cout << "Enter the first name: " << endl; cin >> leName;
	cout << "Etner the last name: " << endl; cin >> lsName;
	list<thePerson_c>::iterator it;
	for(it = personsList.begin(); it != personsList.end(); it++) {
		if(it->getName() == leName && it->getLName() == lsName) {
			cout << "Yep! " << leName << " " << lsName << " is in here!" << endl;
			cout << "Name: " << (it)->getName() << " " << (it)->getLName() << endl;
                	cout << "Location: " << (it)->getPlace() << endl;
                	cout << "DOB: " << (it)->getDayOB() << "/" << (it)->getMonOB() << "/"
                        	<< (it)->getYearOB() << endl;
               		cout << "Age: " << (it)->calculateAge() << endl;
        	        cout << "Title: " << (it)->getTitle() << endl;
        	        cout << "Division: " << (it)->getDivision() << endl;
	                cout << endl;
			found = 1;
			break;
		}
	}
	if(!found) {
		cout << "Nah man, " << leName << " isn't in the list." << endl;
		cout << endl;
	}
	return;
}

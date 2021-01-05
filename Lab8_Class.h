#ifndef CLASSLIST_H
#define CLASSLIST_H

#include<iostream>
#include<string>

using namespace std;

const int YEAR = 2020;
const int MONTH = 4;

struct date_s {
	int day;
	int month;
	int year;

};

class thePerson_c {
	private:
                string city;
                date_s DOB;
		string personName;
		string personLName;
		string personTitle;
		string personDivision;

        public:
                // Constructs a Person
                thePerson_c(string c, int d, int m, int y, string n, string ln, string title, string division)
			:personName(n), personLName(ln), city(c), personTitle(title), personDivision(division) {
                        DOB.day = d; DOB.month = m; DOB.year = y;
                        cout << "Conceived: " << n << " " << ln << endl;
                };

                // Destructor for person
                ~thePerson_c() {cout << personName << " was here." << endl;}

                // Need set functions
                void setPersonName(string personsName) {personName = personsName;return;}
		void setPersonsName(string personsName) {personLName = personsName;return;}
                void setPersonCity(string personCity) {city = personCity;return;}
                void setPersonDOB(int setDay, int setMon, int setYear) {
                        DOB.day = setDay;
                        DOB.month = setMon;
                        DOB.year = setYear;
                        return;
                }
                // Get functions
                string getName() {return personName;}
		string getLName() {return personLName;}
                string getPlace() {return city;}
                int getDayOB() {return DOB.day;}
                int getMonOB() {return DOB.month;}
                int getYearOB() {return DOB.year;}
		string getTitle() {return personTitle;}
		string getDivision() {return personDivision;}

                float calculateAge() { // 109 yrs
                        float age = YEAR - (DOB.year);
			float ageMon = MONTH - (DOB.month);
                        return (age+(ageMon / 12)); // Returns the years and decimal month
                }
/*
                // print the persons name, city, age, title, division
                virtual void print() {
                        cout << getName() << " from " << getPlace() << " is " << calculateAge() << " years old\n";
			cout << endl << "and is a " << getTitle() << " in division " << getDivision() << endl;
                }*/
};

#endif

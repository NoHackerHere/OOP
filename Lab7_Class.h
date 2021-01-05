#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>

using namespace std;

// Date definition
#define DAY 3
#define MONTH 4
#define YEAR 2020

//struct with day, month, and year for graduation date and date of birth
struct date_s {
	int day; // Thank you for this format...
	int month;
	int year;
};

class person_c {
	protected:
		string name;
		string city;
		date_s DOB;

	public:
		// Constructs a Person
		person_c(string n, string c, int d, int m, int y):name(n), city(c) {
			DOB.day = d; DOB.month = m; DOB.year = y;
			cout << "Created: " << n << endl;
		};

		// Destructor for person
		~person_c() { cout << "Deleted: " << name << endl;}

		// Need set functions
		void setPersonName(string personName) {name = personName;return;}
		void setPersonCity(string personCity) {city = personCity;return;}
		void setPersonDOB(int setDay, int setMon, int setYear) {
			DOB.day = setDay;
			DOB.month = setMon;
			DOB.year = setYear;
			return;
		}
		// Get functions
		string getName() {return name;}
		string getPlace() {return city;}
		int getDayOB() {return DOB.day;}
		int getMonOB() {return DOB.month;}
		int getYearOB() {return DOB.year;}

		float calculateAge() { // 109 yrs
			float age = YEAR - (DOB.year);
			// cout << age << " Years of Age" << endl;
			return age;
		}

		// print the persons name, city, age
		virtual void print() {
			cout << name << " from " << city << " is " << calculateAge() << " years old\n";
		}
};

class student_c : public person_c {
	protected:
		string school;
		string major;
		date_s gradDate;
	public:
		student_c(); // Empty constructor
		//student constructor that also calls person constructor
		student_c(string name, string city, int d, int m, int y,
			string edu, string study, int gradDay, int gradMon, int gradYear)
			:school(edu),major(study),person_c(name,city,d,m,y) {
			gradDate.day = gradDay; gradDate.month = gradMon; gradDate.year = gradYear;
		}

		// set functions for student
		void setStudentEdu(string studentEdu) {school = studentEdu;}
		void setStudentMajor(string studentMajor) {major = studentMajor;}
		void setStudentDate(int gradDay, int gradMon, int gradYear) {
			gradDate.day = gradDay; gradDate.month = gradMon; gradDate.year = gradYear;
		}

		// get functions for person
		string getSchool() {return school;}
		string getMajor() {return major;}
		int dayGrad() {return gradDate.day;}
		int monGrad() {return gradDate.month;}
		int yearGrad() {return gradDate.year;}

		// ignoring days, but calculating difference in time between graduation date and current date - presented in years
		float calculateTime() {
			float year_toGrad = gradDate.year - YEAR;
			return year_toGrad;
		}

		// print student attributes and call previous prints (should still have the same name as the person print)
		virtual void print() {
			//person_c::print(); // Not need as virtual function is previously called
			cout << "School: " << school << endl;
			cout << "Major: " << major << endl;
			return;
		}
};

class intern_c : public student_c {
	protected:
		string company;
		string jobTitle;
	public:
		intern_c(); // Empty constructor
		//intern constructor that also calls student constructor
		intern_c(string name,string city,int d,int m,int y,string edu,string study,
			int gradDay,int gradMon,int gradYear,string firm,string title)
			:company(firm),jobTitle(title),/*person_c(name,city,d,m,y),*/
			student_c(name,city,d,m,y,edu,study,gradDay,gradMon,gradYear) {
		}
		// set and get functions
		void setInternCompany(string internComp) {company = internComp;return;}
		void setInternTitle(string internTitle) {jobTitle = internTitle; return;}
		string getInternCompany() {return company;}
		string getInternTitle() {return jobTitle;}
		// print intern attributes and call previous prints (should still have the same name as the person and student print)
		void print() {
			person_c::print();
			student_c::print();
			cout << "Company: " << company << endl;
			cout << "Title: " << jobTitle << endl;
			return;
		}
};

#endif

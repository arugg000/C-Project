#include<iostream>
#include<iomanip>
#include "student.h"
using namespace std;

Student::Student() 
{
    this->sID = "";
    this->fName = "";
    this->lName = "";
    this->emailaddress = "";
    this->sAge = "";
    this->days = new int[daysArraySize];
    for (int i = 0; i<daysArraySize; i++) this->days[i] = 0;
}

Student::Student(string ID, string fName, string lName, string email, string sAge, int days[], DegreeType type) 
{
    this->sID = ID;
    this->fName = fName;
    this->lName = lName;
    this->emailaddress = email;
    this->sAge = sAge;
    this->days = new int[daysArraySize];
        
    for (int i = 0; i<3; i++) this->days[i] = days[i];
}

string Student::getID() 
{
    return sID;
}

string Student::getfName()
{
    return fName;
}

string Student::getlName() 
{
    return lName;
}

string Student::getemailaddress() 
{
    return emailaddress;
}

string Student::getsAge() 
{
    return sAge;
}

DegreeType Student::getDegreeType() 
{
    return type;
}

int * Student::getDays() 
{
    return days;
}

void Student::setID(string ID) 
{
    sID = ID;
}

void Student::setfName(string fName)
{
    this->fName = fName;
}

void Student::setlName(string lName) 
{
    this->lName = lName;
}

void Student::setEmail(string email) 
{
    this->emailaddress = email;
}

void Student::setsAge(string sAge) 
{
    this->sAge = sAge;
}

void Student::setDegreeType(DegreeType type) 
{
    this->type = type;
}

void Student::setDays(int days[]) 
{
    if (this->days != nullptr) {
            delete[] this->days;
            this->days = nullptr;
	}
    
    this->days = new int[daysArraySize];
    for (int i = 0; i<3; i++)
    this->days[i] = days[i];
}


void Student::print()
{
    cout << left << "Student ID: " << sID << '\t';
    cout << left << "First name: " << fName << '\t';
    cout << left << "Last name: "  << lName << '\t';
    cout << left << "Email address: "  << emailaddress << '\t';
    cout << left << "Student age: " << setw(5) << sAge;
    cout << left << "Days spent in each courses: (";
    cout << left << setw(3) << days[0] <<",";
    cout << left << setw(3) << days[1] << ",";
    cout << left << days[2] << ")" << setw(3) << " Degree program: ";
}

Student::~Student() 
{
    if (days != nullptr) 
    {
	delete[] days;
	days = nullptr;
	}
}

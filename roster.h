#pragma once
#include <string>
#include <iostream>
#include "student.h"

using std::string;

int numStudents = 5;

string studentData[5] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Anthony,Ruggeri,Arugge1@wgu.edu,45,85,31,41,SOFTWARE" //Personal information in last item.
};

class Roster {
public:
    int lastIndex;
    int capacity;

    /*Pointer arrays created to hold the data in the studentData table.*/
    Student** studentRosterArray;
    
    Roster();
    Roster(int capacity);
    
    void add(string datarow);
    void printAll();
    bool remove(string sID);
    void printAversAgeDaysInCourse(string sID);
    void printInvalidEmails();
    void printByDegreeType(DegreeType d);
    
    ~Roster();
};

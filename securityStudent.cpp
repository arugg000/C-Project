#include <iostream>
#include "securityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent()
{
    setDegreeType(SECURITY);
}

SecurityStudent::SecurityStudent(string sID, string fName, string lName, string email, string sAge, int * days, DegreeType degreetype) 
{
    setDegreeType(SECURITY);
}

DegreeType SecurityStudent::getDegreeType() 
{
    return SECURITY;
}

void SecurityStudent::setDegreeType(DegreeType d) 
{
    this->type = SECURITY;
}

void SecurityStudent::print()
{
    this->Student::print();
    cout << "SECURIT\n";
}

SecurityStudent::~SecurityStudent() 
{
    Student::~Student();
}

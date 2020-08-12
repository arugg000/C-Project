#include <iostream>
#include "networkStudent.h"
using std::cout;

NetworkStudent::NetworkStudent() 
{
    setDegreeType(NETWORK);
}

NetworkStudent::NetworkStudent(string sID, string fName, string lName, string email, string sAge, int * days, DegreeType degreetype) 
{
    setDegreeType(NETWORK);
}

DegreeType NetworkStudent::getDegreeType() 
{
    return NETWORK;
}

void NetworkStudent::setDegreeType(DegreeType d) 
{
    this->type = NETWORK;
}

void NetworkStudent::print() 
{
    this->Student::print();
    cout << "NETWORK\n";
}

NetworkStudent::~NetworkStudent() 
{
    Student::~Student();
}

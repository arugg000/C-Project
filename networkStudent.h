//Rubric D3: Subclass overridding getDegreeType() function.
#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student 
{
public:
    NetworkStudent();
    NetworkStudent(string sID, string fName, string lName, string emailAddress, string studentsAge, int* daysInCourse, DegreeType degreetype);
    

    DegreeType getDegreeType();
    void setDegreeType(DegreeType d);
    void print();

    ~NetworkStudent();
};

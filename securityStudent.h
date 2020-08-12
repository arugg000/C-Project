#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class SecurityStudent : public Student 
{

public:
    SecurityStudent();
    SecurityStudent(string sID, string fName, string lName, string emailAddress, string studentsAge, int* daysInCourse, DegreeType degreetype);
        
    //This subclass overrides the getDegreeType() function.
    DegreeType getDegreeType();
    void setDegreeType(DegreeType d);
    void print();

    ~SecurityStudent();
};


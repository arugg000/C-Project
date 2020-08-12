#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class SoftwareStudent : public Student 
{

public:
    SoftwareStudent();
    SoftwareStudent(string sID, string fName, string lName, string emailAddress, string studentsAge, int* daysInCourse, DegreeType degreetype);
        

    DegreeType getDegreeType();
    void setDegreeType(DegreeType d);
    void print();

    ~SoftwareStudent();
};

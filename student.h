#pragma once
#include <string>
#include "degree.h"
using std::string;

/*Bleow is the base Student class  */
class Student 
{
protected:
    string sID;
    string fName;
    string lName;
    string emailaddress;
    string sAge;
    int* days;
    DegreeType type;

public:
    const static int daysArraySize = 3;
    
    /*Constructor - A method that is automatically called when an object of a class is created*/
    Student();
    Student(string ID, string fName, string lName, string email, string sAge, int days[], DegreeType type);//full constructor
    
    /*Accessors (getters)*/
    string getID();
    string getfName();
    string getlName();
    string getemailaddress();
    string getsAge();
    int* getDays();
    
    virtual DegreeType getDegreeType() = 0;

    /*Mutators (setters)*/
    void setID(string ID);
    void setfName(string fName);
    void setlName(string lName);
    void setEmail(string email);
    void setsAge(string sAge);
    void setDays(int days[]);
    virtual void setDegreeType(DegreeType d) = 0;
    
    virtual void print() = 0;

    /*Destructor - function which destructs or deletes an object*/
    ~Student();
};

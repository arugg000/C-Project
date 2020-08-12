#include "roster.h"
#include "degree.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
using std::cout;
using std::cerr;

int main() {

    /*F1: Screen Print Out*/
    cout << "C867-Scripting & Programming: Applications\n";
    cout << "Scripts and progam written in C++ by Anthony Ruggeri\n";
    cout << "Student ID: 001096973\n";
    cout << "\n";

    /*F2: Roster Class*/
    Roster * classRoster = new Roster(numStudents);
    cout << "Students added from the data table:";

    /*F3: Adding students*/
    for (int i = 0; i < numStudents; i++) 
    {
            classRoster->add(studentData[i]);
	}
    cout << " Complete.\n";
    cout << "\n";

    cout << "All students displayed:\n";
    cout << "\n";

    /*F4: Convert pseudo code*/
    classRoster->printAll();
    cout << "\n";

    classRoster->printAversAgeDaysInCourse("A5");
    cout << "\n";

    classRoster->printInvalidEmails();
    cout << "\n";

    classRoster->printByDegreeType(SOFTWARE);
    cout << "\n";

    cout << "Removing A3:\n";
    cout << "\n";

    if (classRoster->remove("A3")) 
    {
        classRoster->printAll();
        cout << "\n";
        }
    else cout << "No matching student found!\n";

    cout << "Removing A3:\n";
    cout << "\n";

    if (classRoster->remove("A3")) 
    {
        classRoster->printAll();
        }
        else cout << "Student not found!\n";

	return 0;
}

Roster::Roster() 
{
    this->capacity = 5;
    this->lastIndex = -1;
    this->studentRosterArray = nullptr;
}

Roster::Roster(int capacity) 
{
    this->capacity = capacity;
    this->lastIndex = -1;
    this->studentRosterArray = new Student*[capacity];
}

/*The following section contains E3A(Add function),E2 (Student object),E2A(Parsed data), and E2B(Add student objects to array)*/
void Roster::add(string row) 
{
	if (lastIndex < capacity) 
    {
            lastIndex++;
            int darray[Student::daysArraySize];

            if (row[4] == 'o') 
            {
                this->studentRosterArray[lastIndex] = new SecurityStudent();
                studentRosterArray[lastIndex]->setDegreeType(SECURITY);
            }

                else if (row[4] == 'r') 
            {
                    this->studentRosterArray[lastIndex] = new SecurityStudent();
                    studentRosterArray[lastIndex]->setDegreeType(SECURITY);
                }

                else if (row[4] == 'u') 
            {
                    this->studentRosterArray[lastIndex] = new NetworkStudent();
                    studentRosterArray[lastIndex]->setDegreeType(NETWORK);
                }

                else 
            {
                    this->studentRosterArray[lastIndex] = new SoftwareStudent();
                    studentRosterArray[lastIndex]->setDegreeType(SOFTWARE);
                }


            int rhs = studentData[lastIndex].find(",");
            studentRosterArray[lastIndex]->setID(studentData[lastIndex].substr(0, rhs));

            int lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            studentRosterArray[lastIndex]->setfName(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            studentRosterArray[lastIndex]->setlName(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            studentRosterArray[lastIndex]->setEmail(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            studentRosterArray[lastIndex]->setsAge(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            darray[0] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            darray[1] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            darray[2] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

            studentRosterArray[lastIndex]->setDays(darray);
	}
}


/*E3C: printAll function*/
void Roster::printAll()
{
    for (int i = 0; i <= this->lastIndex; i++) 
        (this->studentRosterArray)[i]->print();
}

/*E3B: Remove function.*/
bool Roster::remove(string sID) 
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
            if (this->studentRosterArray[i]->getID() == sID) 
            {
                found = true;
                Student* stu = studentRosterArray[i];
                this->studentRosterArray[i] = this->studentRosterArray[lastIndex];
                (studentRosterArray[lastIndex]) = stu;
		            lastIndex--;
            }
    }
    return found;
}

/*E3D: Print average function.*/
void Roster::printAversAgeDaysInCourse(string sID) 
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) 
    {
        if (this->studentRosterArray[i]->getID() == sID) 
        {
            found = true;
            int* d = studentRosterArray[i]->getDays();
            cout << "Student ID: " << sID << ", aversAges " << (d[0] + d[1] + d[2]) / 3 << " days to complete courses.\n";
	      }
    }
    if (!found) cout << "No matching student found!\n";


}

/*E3E: Print invalid email address function*/
void Roster::printInvalidEmails() 
{
    cout << "Invalid emails:\n";
    cout << "\n";
    for (int i = 0; i < 5; i++) 
    {
	bool foundAt = false;
	bool foundPeriod = false;
	bool foundSpace = false;
        string email = "";
        email = (*studentRosterArray[i]).getemailaddress();
		for (char &c : email) {
                    if (c == '@') 
                    {
                        foundAt = true;
                    }
                    if (c == '.') 
                    {
                        foundPeriod = true;
                    }
                    if (c == ' ') 
                    {
                        foundSpace = true;
                    }
		}
                if (foundAt == false) 
                {
                    cout << (*studentRosterArray[i]).getemailaddress() << " - Invalid email: missing the @ symbol.\n";
                }
                if (foundPeriod == false) 
                {
                    cout << (*studentRosterArray[i]).getemailaddress() << " - Invalid email: missing a period before com.\n";
                }
                if (foundSpace == true) 
                {
                    cout << (*studentRosterArray[i]).getemailaddress() << " - no spaces allowed.\n";
		}
    }
}

/*E3F: Print Degree function*/
void Roster::printByDegreeType(DegreeType d) 
{
    cout << "Showing students in degree program: " << degreeTypeStrings[d] << "\n";
    cout << "\n";

    for (int i = 0; i <= lastIndex; i++) 
    {
            if (this->studentRosterArray[i]->getDegreeType() == d) this->studentRosterArray[i]->print();
	}
}

/*/F5: Call the destructor*/
Roster::~Roster() 
{
    for (int i = 0; i < numStudents; i++) 
    {
            delete this->studentRosterArray[i];
    }
    delete this;
}

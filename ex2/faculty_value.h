#pragma once
#include <iostream>

enum Faculty { ComputerScience, Literature, Medicine };

/*
this class represents the faculty the student is attending
the user inputs a number and the faculty matches accordingly. 
ostream operator is needed for template class 
*/
class FacultyValue
{
public:
	FacultyValue(); // c-tor
	~FacultyValue(); // d-tor
	void displayFaculty(std::ostream &os) const; //display name faculty
	void setFaculty(std::istream& is); //cin to faculty value
	int getFacultyVal()const& { return m_faculty; } // get number of faculty

private:
	int m_faculty;//the user input, number of faculty

};

//operators
std::istream& operator >>(std::istream& is,  FacultyValue& f);
std::ostream& operator <<(std::ostream& os, const FacultyValue& f);
bool operator <(const FacultyValue&, const int&);
bool operator >(const FacultyValue&, const int&);
bool operator==(const FacultyValue& f1, const FacultyValue& f2);

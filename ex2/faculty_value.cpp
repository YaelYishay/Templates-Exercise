#include "stdafx.h"
#include "faculty_value.h"

FacultyValue::FacultyValue()
{
}

FacultyValue::~FacultyValue()
{
}

//print the faculty name
void FacultyValue::displayFaculty(std::ostream & os) const{

	switch (m_faculty)
	{
	case 1:
		os << "Computer Science";
		break;
	case 2:
		os << "Medicine";
		break;
	case 3:
		os << "Literature";
		break;
	default:
		os << m_faculty;
		break;
	}
}

//recievs the faculty name and sets the faculty 
void FacultyValue::setFaculty(std::istream & is){
	is >> m_faculty;
}

// >> operator so we can recieve the faculty 
std::istream & operator>>(std::istream & is, FacultyValue & f)
{
	f.setFaculty(is);
	return is;
}
// << operator prints the faculty
std::ostream & operator<<(std::ostream & os, const FacultyValue & f)
{
	f.displayFaculty(os);
	return os;
}

// operator < makes sure the faculty value is in range - for templatee
bool operator<(const FacultyValue &f, const int &other)
{
	if (f.getFacultyVal() < other)
		return true;
	return false;
}

// operator < makes sure the faculty value is in range - for template
bool operator>(const FacultyValue &f, const int &other)
{
	if (f.getFacultyVal() > other)
		return true;
	return false;
}

// operator == faculty value is same - for template
bool operator==(const FacultyValue & f1, const FacultyValue & f2)
{
	if (f1.getFacultyVal() == f2.getFacultyVal())
		return true;
	return false;
}






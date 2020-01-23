#pragma once
#include "complexValidator.h"
#include "faculty_value.h"

/*
template class that recieves two fields that represen the year the student is
attending, the faculty, and validates
*/
template <class T1, class T2>
class Faculty2YearValidator : public complexValidator
{
public:
	Faculty2YearValidator(T1 *f, T2 *y) :m_faculty(f), m_year(y) { ; } //c-tor
	~Faculty2YearValidator(); // d-tor
	virtual bool isValid(); //check faculty field and year field
	virtual void displayErrorMsg(ostream &) const; //display error msg
	virtual void fillAgain(ostream&)const; //askes for input again

protected:
	T1 *m_faculty; // faculty field
	T2 *m_year; // year field
};

//d-tor
template<class T1, class T2>
inline Faculty2YearValidator<T1, T2>::~Faculty2YearValidator()
{
}

//checks if the user enterd a year thats not in the course range
template<class T1, class T2>
inline bool Faculty2YearValidator<T1, T2>::isValid(){

	switch(m_faculty->get().getFacultyVal())
	{
	case ComputerScience:
		if (m_year->get() > 4)
			return false;
		break;
	case Literature:
		if (m_year->get() > 3)
			return false;
		break;
	case Medicine:
		if (m_year->get() > 7)
			return false;
		break;
	default:
		break;
	}

	return true;
}

//displays the error  msg
template<class T1, class T2>
inline void Faculty2YearValidator<T1, T2>::displayErrorMsg(ostream &os) const{
	m_faculty->displayInput(os);
	os << ",";
	m_year->displayInput(os);
	os << " -> The year number does not match faculty" << endl;
}

//refills the field, prompts to fill field
template<class T1, class T2>
inline void Faculty2YearValidator<T1, T2>::fillAgain(ostream &) const
{
	//display faculty field and askes input again
	m_faculty->displayField(std::cout);
	m_faculty->fillField();
	cout << endl;

	//display year field and askes input again
	m_year->displayField(std::cout);
	m_year->fillField();
}

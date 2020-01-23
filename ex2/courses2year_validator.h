#pragma once
#include "complexValidator.h"

/*
template class that recieves two fields that represen the year the student is 
attending and the amount of courses he is taking, and validates 
*/
template <class T1, class T2>
class Courses2YearValidator : public complexValidator
{
public:
	Courses2YearValidator(T1* c, T2* y) : m_course(c), m_year(y) { ; } //c-tor
	~Courses2YearValidator(); // d-tor
	virtual bool isValid(); //check course field and year field
	virtual void displayErrorMsg(ostream &) const; // displays the error msg
	virtual void fillAgain(ostream&)const; //askes for input again

protected:
	T1 *m_course; // course field
	T2 *m_year; // year field
};

//d-tor
template<class T1, class T2>
inline Courses2YearValidator<T1, T2>::~Courses2YearValidator(){
}

//checks if the amount of courses taken matches the year
template<class T1, class T2>
inline bool Courses2YearValidator<T1, T2>::isValid(){

	int courses = m_course->get(),
		year = m_year->get();

	if ((year == 1 || year == 2) && courses <= 6)
		return true;

	if ((year == 4 || year == 3) && courses <= 10)
		return true;

	if ((year > 5) && courses <= 8)
		return true;

	return false;
}

//displays the error msg and the wrong input
template<class T1, class T2>
inline void Courses2YearValidator<T1, T2>::displayErrorMsg(ostream &os) const{

	os << " -> ";
	m_course->displayInput(os);
	os << " courses does not match year ";
	m_year->displayInput(os);
	os << endl;
}

//refill the field, displays the prompt and askes for input
template<class T1, class T2>
inline void Courses2YearValidator<T1, T2>::fillAgain(ostream &os) const
{
	//display course field and fill again
	m_course->displayField(std::cout);
	m_course->fillField();

	cout << endl;
	
	//display year field and fill again
	m_year->displayField(std::cout);
	m_year->fillField();
}

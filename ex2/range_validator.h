#pragma once
#include "simpleValidator.h"

/*
this template class makes sure a certain value is in a certain range
values can be of different types
*/
template <class T>
class RangeValidator : public simpleValidator<T>
{
public:
	RangeValidator(int, int); // c-tor
	~RangeValidator(); // d-tor
	virtual bool isValid(T); // check field
	virtual void displayErrorMsg(ostream &) const; // print error msg


	
protected:
	T m_val; // user input
	int m_max; // maximum value
	int m_min; // minimum value
};

//c-tor
template<class T>
inline RangeValidator<T>::RangeValidator(int min, int max)
	:m_max(max), m_min(min)
{
}

//d-tor
template<class T>
inline RangeValidator<T>::~RangeValidator()
{
}

//checks if a value is within a range
template<class T>
inline bool RangeValidator<T>::isValid(T val)
{
	m_val = val;
	if (m_val > m_max || m_val < m_min)
		return false;
	return true;
}

//print error msg
template<class T>
inline void RangeValidator<T>::displayErrorMsg(ostream &os) const{
	os << " -> Out of range" << endl;
}


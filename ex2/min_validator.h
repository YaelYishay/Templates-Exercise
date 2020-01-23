#pragma once
#include "simpleValidator.h"

/*
this class makes sure a certain value is not any less than a certain minimal value
*/
template <class T>
class MinValidator: public simpleValidator<T>{
public:
	MinValidator(int minVal) :m_minVal(minVal) { ; } //c-tor
	~MinValidator();//d-tor
	virtual bool isValid(T); // check field
	virtual void displayErrorMsg(ostream &) const; // print error msg

protected:
	T m_val; // input user
	int m_minVal; // minimum value
};

//d-tor
template<class T>
inline MinValidator<T>::~MinValidator()
{
}

//check a range of a value, can be different types of values 
template<class T>
inline bool MinValidator<T>::isValid(T val)
{
	m_val = val;
	if (m_val < m_minVal)
		return false;
	return true;
}

//print error msg
template<class T>
inline void MinValidator<T>::displayErrorMsg(ostream &os) const{
	os << " -> Not enough courses per year" << endl;
}

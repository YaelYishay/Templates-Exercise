#pragma once
#include "validator.h"

/*
this template abstract class recives a field and validates it
with simple validators 
*/
template <class T>
class simpleValidator :
	public Validator
{
public:
	simpleValidator(){; }// c-tor
	~simpleValidator() {; }//d-tor
	virtual bool isValid(T) = 0; // check field

};



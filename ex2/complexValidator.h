#pragma once
#include "validator.h"

/*
this abstract class will  handle validators that check two or more fields and match the 
input between them so as to validate a field
*/
class complexValidator :
	public Validator
{
public:
	complexValidator(); // c-tor
	~complexValidator(); //d-tor
	virtual bool isValid() = 0;// check form
	virtual void fillAgain(ostream&)const = 0;//askes for input again 

};


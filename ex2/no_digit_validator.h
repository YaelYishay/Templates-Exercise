#pragma once
#include "simpleValidator.h"
#include <string>

/*
this class makes sure no digits where enterd in the 'name' field
*/
class NoDigitValidator:
	public simpleValidator<std::string>
{
public:
	NoDigitValidator(); // c-tor
	~NoDigitValidator(); //d-tor
	virtual bool isValid(std::string); //check field
	virtual void displayErrorMsg(ostream &) const; // print error msg

};


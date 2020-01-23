#pragma once
#include "simpleValidator.h"
#include <vector>
#include <memory>

/*
this validates the id the user has enterd and makes sure it is valid
*/
class IDValidator :
	public simpleValidator<uint32_t>
{
public:
	IDValidator(); // c-tor
	~IDValidator(); // d-tor
	virtual bool isValid(uint32_t); // check field
	virtual void displayErrorMsg(ostream &) const; //print error msg
	void toDigits(); //turn the id number to an array of digits
	void calcLastDigit(); //calculate what the last digit should be

protected:
	int m_digitArr[9]; // id array
	uint32_t m_idNum; // input user
	int m_lastDigit;

};



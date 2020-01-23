#include "stdafx.h"
#include "no_digit_validator.h"
#include <algorithm>
#include <cctype>

NoDigitValidator::NoDigitValidator()
{
}

NoDigitValidator::~NoDigitValidator()
{
}

//makes sure no digit was enterd in name
bool NoDigitValidator::isValid(std::string s)
{
	if (s == "")	//if name is empty return false
		return false;
	return !(std::any_of(s.begin(), s.end(), ::isdigit));
}

void NoDigitValidator::displayErrorMsg(ostream &os) const{
	os << " -> Can't contain digits" << std::endl;
}

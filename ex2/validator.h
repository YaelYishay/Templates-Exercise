#pragma once
#include <iostream>
using std::ostream;

/*
this abstract class validates the different fields
*/
class Validator
{
public:
	Validator(); // c-tor
	~Validator(); //d-tor
	virtual void displayErrorMsg(ostream &) const = 0; //print error msg

};


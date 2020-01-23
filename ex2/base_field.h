#pragma once
#include <iostream>
using std::ostream;

/*
this is an abstract base class  for fields, template and non-template
each field will display the field, validate it, recieve the input, if 
necesary will display error msg 
*/
class BaseField
{
public:
	BaseField();//c-tor
	~BaseField(); //d-tor
	virtual void displayField(ostream &) const = 0; //display field msg
	virtual bool isValid()const = 0; // check field
	virtual void fillField() = 0; //askes for input again
	virtual void displayErrorMsg(ostream &) const = 0; // display error field msg
	virtual void displayInput(ostream &) const = 0; // display user input

};

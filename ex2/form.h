#pragma once
#include <vector>
#include "complexValidator.h"
#include "field.h"
#include <iostream>

using std::vector;
using std::ostream;
using std::endl;
using std::cout;
using std::cin;

/*
this field represents form with fields for user to fill and validates that the form 
has been filled correctly
first the class will add fields for the user to fill
then add validator to check the fields
it will also hold the loop that prints out the fields needed to be filled or re-filled
*/
class Form
{
public:
	Form(); // c-tor
	~Form(); //d-tor
	void addField(BaseField* f) { m_fields.push_back(f); } // add field 
	void addValidator(complexValidator* v) { m_validator.push_back(v); } // add validator
	bool validateForm()const; // check form
	void fillForm(); // askes for input
	void displayFormFields(ostream&) const; // display form fields

private:
	vector<BaseField*> m_fields; // form fields
	vector<complexValidator*> m_validator; // form validators
};

//operator cout
ostream& operator<<(std::ostream&, const Form&);
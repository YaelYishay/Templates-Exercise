#include "stdafx.h"
#include "form.h"

Form::Form()
{

}

Form::~Form()
{
}

//to validate the for check each field
//also check the complex fields that need to validate two different fields
bool Form::validateForm()const {

	//validate fields
	for (size_t i = 0; i < m_fields.size(); i++)
		if (!m_fields[i]->isValid())
			return false;

	//validate form
	for (size_t i = 0; i < m_validator.size(); i++)
		if (!m_validator[i]->isValid())
			return false;
		
	return true;
}
// fill the form
void Form::fillForm()
{
	//if a field is not filled or not correct, display the field, re-fill the field
	for (size_t i = 0; i < m_fields.size(); i++) {

		//if is not valid
		if (!m_fields[i]->isValid()) {

			m_fields[i]->displayField(std::cout);	//display field
			m_fields[i]->fillField();	//askes for input again 
			cout << endl;
		}
	}	
}

//display the different fields
void Form::displayFormFields(ostream &os) const
{
	//display the filds
	for (size_t i = 0; i < m_fields.size(); i++) {
		m_fields[i]->displayField(os);

		//if field is incorrect , display field with error msg
		if (!m_fields[i]->isValid()) {
			os << endl;
			m_fields[i]->displayInput(os);
			m_fields[i]->displayErrorMsg(os);
		}
		//if field is correct display input with smily face
		else {
			os << " = ";
			m_fields[i]->displayInput(os);
			os << " :) " << endl;
		}
		os << endl;
	}
	//if form is incorrect display error msg and askes for input
	for (size_t i = 0; i < m_validator.size(); i++)
		if (!m_validator[i]->isValid()) {
			m_validator[i]->displayErrorMsg(os);
			m_validator[i]->fillAgain(std::cout);
		}

}
//operator cout
std::ostream& operator<<(std::ostream& os, const Form& f) {

	f.displayFormFields(os);
	return os;
}



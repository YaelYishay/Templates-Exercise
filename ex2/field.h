#pragma once
#include <string>
#include <vector>
#include "base_field.h"
#include "simpleValidator.h"

using std::string;
using std::vector;


/*
this is a template class that recievs different validator types to validate the field
this class also recieves the input from the user and prints the prompt and error msg.
*/
template<class T>
class Field : public BaseField
{
public:
	Field(const string& s) : m_msg(s) { } //c-tor
	~Field(); //d- tor
	void addValidator(simpleValidator<T>* v) { m_validator.push_back(v); } 	//add validator for validators vector
	virtual void displayField(ostream &) const; // display msg field
	virtual void displayErrorMsg(ostream &) const; // display error msg
	virtual void displayInput(ostream &) const; // display user input
	virtual bool isValid()const;	 // check field
	virtual void fillField(); // askes for input again
	T get()const { return m_input; } // get func, return user input

private:
	T m_input; //user input
	string m_msg; // msg field
	vector<simpleValidator<T>*> m_validator; // validators field

};

//d-tor
template<class T>
inline Field<T>::~Field()
{
}

//prints the prompt
template<class T>
inline void Field<T>::displayField(ostream & os) const {
	os << m_msg << " ";
}

//prints the error msg
template<class T>
inline void Field<T>::displayErrorMsg(ostream & os) const{

	for (size_t i = 0; i < m_validator.size(); i++) {
		m_validator[i]->displayErrorMsg(os);
		os << endl;
	}
}

//prints the input from the user
template<class T>
inline void Field<T>::displayInput(ostream &os) const{
	os << m_input;
}

//goes over the validate vector and checks if all the validations are true
template<class T>
inline bool Field<T>::isValid() const
{
	for (size_t i = 0; i < m_validator.size(); i++)
		if (!m_validator[i]->isValid(m_input))
			return false;
	return true;
}

//recieve input
template<class T>
inline void Field<T>::fillField(){
	cin >> m_input;
}


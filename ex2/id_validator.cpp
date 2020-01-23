#include "stdafx.h"
#include "id_validator.h"

IDValidator::IDValidator()
{
}

IDValidator::~IDValidator()
{
}
// checks if id number is valid
bool IDValidator::isValid(uint32_t number)
{
	//id number
	m_idNum = number;

	int idDigit,
		sumDigit = 0;

	toDigits();				//make number into digit array
	calcLastDigit();		//calculate the last digit

	for (size_t i = 0; i < 9; i += 2)
		sumDigit += m_digitArr[i];
	idDigit = (sumDigit % 10);

	if (idDigit == m_lastDigit)	//if the last digit is correct return true
		return true;
	return false;
}

//turn the id number to an array of digits
void IDValidator::toDigits()
{
	int i = 0;
	while (m_idNum > 0) {
		m_digitArr[i++] = m_idNum % 10;
		m_idNum /= 10;
	}
	m_lastDigit = m_digitArr[0];
}

//calculate what the last digit should be
void IDValidator::calcLastDigit()
{
	for (size_t i = 8; i <= 0; i -= 2) {
		m_digitArr[i] = m_digitArr[i] * 2;

		if (m_digitArr[i] > 9) {
			int digit1 = m_digitArr[i] % 10;
			m_digitArr[i] /= 10;
			m_digitArr[i] += digit1;
		}
	}
}

void IDValidator::displayErrorMsg(ostream & os) const{
	os << " -> Wrong control digits" << std::endl;
}

/*====================================================================
* Workshop 6: Part 2
* Version: 1.0
* Due Date: 2021/11/07
* Name: Sophia Huynh
* Student Number: 118448208
* Student Email: shuynh9@myseneca.ca
* Professor: Mufleh Al-Shatnawi
* Section: NCC
* I have done all the coding by myself and only copied the code
* that my professor provided to complete my workshops and assignments.
====================================================================*/
#include <sstream>
#include "Racecar.h"

namespace sdds {
	Racecar::Racecar(std::istream& in)
		: Car{ in } {
		std::string str;
		std::getline(in, str);
		std::stringstream sstr(str);

		std::string booster;
		std::getline(sstr, booster);
		booster = trim(booster);
		m_booster = std::stod(booster);
	}

	void Racecar::display(std::ostream& out)const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}
}
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
#include <iostream>
#include <iomanip>
#include "Car.h"

namespace sdds {
	Car::Car(std::istream& istr) {
		std::getline(istr, m_maker, ',');
		m_maker = trim(m_maker);
		std::getline(istr, m_condition, ',');
		m_condition = trim(m_condition);
		if (m_condition == "n" || m_condition == "N" || m_condition == "" || m_condition == " ") {
			m_condition = "new";
		}
		else if (m_condition == "b" || m_condition == "B") {
			m_condition = "broken";
		}
		else if (m_condition == "u" || m_condition == "U") {
			m_condition = "used";
		}
		else {
			throw std::string("Invalid record!");
		}
		
		std::string speed;
		std::getline(istr, speed, ',');
		speed = trim(speed);
		try {
			m_topSpeed = std::stod(speed);
		}
		catch(...){
			throw std::string("Invalid record!");
		}
	}

	std::string Car::condition() const {
		return m_condition;
	}

	double Car::topSpeed() const {
		return m_topSpeed;
	}

	void Car::display(std::ostream& ostr) const {
		ostr << "| ";
		ostr << std::setw(10) << std::right << m_maker << " | ";
		ostr << std::setw(6) << std::left << m_condition << " | ";
		ostr << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
	}

	std::string Car::trim(std::string str, const std::string& chars) {
		str.erase(0, str.find_first_not_of(chars));
		str.erase(str.find_last_not_of(chars) + 1);
		return str;
	}
}
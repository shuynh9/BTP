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
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"

namespace sdds {
	class Car: public Vehicle { // Holds information about a single car
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed;
	public:
		Car(std::istream& istr);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& ostr) const;
		std::string trim(std::string str, const std::string& chars = "\t\n\v\f\r ");
	};
}

#endif // !SDDS_CAR_H

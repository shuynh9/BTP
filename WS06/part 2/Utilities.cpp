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
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		std::string str;
		std::getline(in, str);
		std::stringstream sstr(str);

		std::string type;
		std::getline(sstr, type, ',');

		type.erase(0, type.find_first_not_of("\n\t\r\v\f "));
		type.erase(type.find_last_not_of("\n\t\r\v\f ") + 1);

		if (type == "c" || type == "C") {
			return new Car(sstr);
		}
		else if (type == "r" || type == "R") {
			return new Racecar(sstr);
		}
		else if (type == "") {
			return nullptr;
		}
		else {
			std::string msg = "Unrecognized record type: [" + type + "]";
			throw msg;
		}
	}
}
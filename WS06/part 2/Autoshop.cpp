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
#include "Autoshop.h"

namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* aVehicle) {
		m_vehicles.push_back(aVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out)const {
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		for (auto& v : m_vehicles) {
			v->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}

	Autoshop::~Autoshop() {
		for (auto& v: m_vehicles) {
			delete v;
		}
	}
}
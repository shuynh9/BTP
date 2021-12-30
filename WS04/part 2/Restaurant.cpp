/*====================================================================
* Workshop 4: Part 2
* Version: 1.0
* Due Date: 2021/10/10
* Name: Sophia Huynh
* Student Number: 118448208
* Student Email: shuynh9@myseneca.ca
* Professor: Mufleh Al-Shatnawi
* Section: NCC
* I have done all the coding by myself and only copied the code
* that my professor provided to complete my workshops and assignments.
====================================================================*/
#include <iostream>
#include "Restaurant.h"
#include "Reservation.h"

namespace sdds {
	Restaurant::Restaurant() {
		m_reso = nullptr;
		m_num = 0;
	}

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
		:m_num{ cnt } {
		if (reservations != nullptr && cnt > 0) {
			m_reso = new Reservation[cnt];

			for (size_t i{ 0 }; i < cnt; i++) {
				m_reso[i] = *reservations[i];
			}
		}
	}

	Restaurant::~Restaurant() {
		delete[] m_reso;
		m_reso = nullptr;
	}

	Restaurant::Restaurant(const Restaurant& src) {
		m_reso = nullptr;
		*this = src;
	}

	Restaurant& Restaurant::operator=(const Restaurant& rhs) {
		if (this != &rhs) {
			delete[] m_reso;
			m_num = rhs.m_num;
			m_reso = new Reservation[m_num];
			for (size_t i{ 0 }; i < m_num; i++)
				m_reso[i] = rhs.m_reso[i];
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& src){
		m_reso = nullptr;
		m_num = 0;
		*this = std::move(src);
	}

	Restaurant& Restaurant::operator=(Restaurant&& rhs) {
		if (this != &rhs) {
			m_num = rhs.m_num;

			delete[] m_reso;
			m_reso = rhs.m_reso;
			
			// sets new objects to null
			rhs.m_num = 0; 
			rhs.m_reso = nullptr;
		}
		return *this;
	}

	size_t Restaurant::size() const {
		return m_num;
	}

	int count{ 1 };
	std::ostream& operator<<(std::ostream& ostr, const Restaurant& reso) {
		ostr << "--------------------------" << std::endl;
		ostr << "Fancy Restaurant (" << count << ")" << std::endl;
		count++;
		ostr << "--------------------------" << std::endl;

		if (reso.m_reso == nullptr) {
			ostr << "This restaurant is empty!" << std::endl;
			ostr << "--------------------------" << std::endl;
		}
		else {
			for (size_t i{ 0 }; i < reso.m_num; i++) {
				ostr << reso.m_reso[i];
			}
			ostr << "--------------------------" << std::endl;
		}
		return ostr;
	}
}
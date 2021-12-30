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
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include "Reservation.h"

namespace sdds {
	class Restaurant {
		Reservation* m_reso; // allocated array of reservations
		size_t m_num; // number of reservations made
	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		~Restaurant();
		Restaurant(const Restaurant& src); // copy constructor
		Restaurant& operator=(const Restaurant& rhs); // copy assignment
		Restaurant(Restaurant&& src); // move constructor
		Restaurant& operator=(Restaurant&& rhs); // move assignment
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& ostr, const Restaurant& reso);
	};
}

#endif

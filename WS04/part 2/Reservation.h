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
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <string>

namespace sdds {
	class Reservation {
		std::string m_id; // reso id
		std::string m_name; // reso name
		std::string m_email; // reso email
		size_t m_size; // number of people in party
		size_t m_day; // when party expects to come (between 1 and 28)
		size_t m_time; // when party expects to come (between 1 and 24)
	public:
		Reservation();
		Reservation(const std::string& res);
		std::string Remove(std::string str);
		void update(int day, int time);
		friend std::ostream& operator<<(std::ostream& ostr, const Reservation& reso);
	};

}

#endif
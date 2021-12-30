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
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include <iostream>
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		const Reservation** c_reso;
		size_t c_size;
		size_t c_index;
	public:
		ConfirmationSender();
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender& operator=(const ConfirmationSender& rhs);
		ConfirmationSender(ConfirmationSender&& src);
		ConfirmationSender& operator=(ConfirmationSender&& rhs);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		bool Check(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& cs);
	};

}

#endif // !SDDS_CONFIRMATIONSENDER_H

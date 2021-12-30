/*============================================================
*Workshop 4: Part 2
* Version : 1.0
* Due Date : 2021 / 10 / 10
* Name : Sophia Huynh
* Student Number : 118448208
* Student Email : shuynh9@myseneca.ca
* Professor: Mufleh Al - Shatnawi
* Section : NCC
* I have done all the coding by myself and only copiesd the code
* that my professor provided to complete my workshops and assignments.
====================================================================*/
#include <iostream>
#include "ConfirmationSender.h"

namespace sdds {
	ConfirmationSender::ConfirmationSender() {
		c_reso = nullptr;
		c_size = 0;
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] c_reso;
		c_reso = nullptr;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
		c_reso = nullptr;
		*this = src;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& rhs) {
		if (this != &rhs) {
			c_size = rhs.c_size;
			delete[] c_reso;
			c_reso = new const Reservation *[c_size];

			for (size_t i{ 0 }; i < c_size; i++) {
				c_reso[i] = rhs.c_reso[i];
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) {
		c_reso = nullptr;
		*this = std::move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& rhs) {
		if (this != &rhs) {
			c_size = rhs.c_size;
			delete[] c_reso;
			c_reso = rhs.c_reso;

			rhs.c_size = 0;
			rhs.c_reso = nullptr;
		}
		return *this;
	}

	bool ConfirmationSender::Check(const Reservation& res) {
		bool flag{ false };
		for (size_t i{ 0 }; i < c_size; i++) {
			if (c_reso[i] == &res) {
				c_index = i;
				flag = true;
			}
		}
		return flag;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool flag{ true };
		for (size_t i{ 0 }; i < c_size; i++) {
			if (c_reso[i] == &res) {
				flag = false; //if the address of `res` is already in the array, this operator does nothing
			}
		}

		if (flag) {
			const Reservation** temp = new const Reservation * [c_size + 1];

			for (size_t i{ 0 }; i < c_size; i++) {
				temp[i] = c_reso[i]; //stores the **address** of `res` in temp array
			}
			delete[] c_reso;
			temp[c_size] = &res; //adds the reservation `res` to the array by adding its address.
			c_size++;
			c_reso = temp; // assign member array of pointer to temporary array 
			temp = nullptr;
		}
		return *this;
	}
	
	int index{ 0 };
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		if (Check(res)) {
			c_reso[c_index] = nullptr;
			bool flag{ true };
			const Reservation** temp = new const Reservation * [c_size-1];
			for (size_t j{ 0 }; j < c_size; j++) {
				if (flag) {
					if (j != c_index) {
						temp[j] = c_reso[j];
					}
					else {
						flag = false;
					}
				}
				else {
					temp[j - 1] = c_reso[j];
				}
			}
			delete[] c_reso;
			c_size--;
			c_reso = new const Reservation*[c_size];
			for (size_t i{ 0 }; i < c_size; i++) {
				c_reso[i] = temp[i];
			}
			delete[] temp;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& cs) {
		ostr << "--------------------------" << std::endl;
		ostr << "Confirmations to Send" << std::endl;
		ostr << "--------------------------" << std::endl;
		if (cs.c_reso == nullptr) {
			ostr << "There are no confirmations to send!" << std::endl;
			ostr << "--------------------------" << std::endl;
		}
		else {
			for (size_t i{ 0 }; i < cs.c_size; i++) {
				ostr << *cs.c_reso[i];
			}
			ostr << "--------------------------" << std::endl;
		}
		return ostr;
	}
}
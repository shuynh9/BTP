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
#include <string>
#include <sstream>
#include <iomanip>
#include "Reservation.h"

namespace sdds {
	Reservation::Reservation() {
		m_id = "";
		m_name = "";
		m_email = "";
		m_size = 0;
		m_day = 0;
		m_time = 0;
	}

	Reservation::Reservation(const std::string& res) {
		std::string str = res;

		m_id = Remove(str.substr(0, str.find(":")));
		str.erase(0, str.find(":") + 1);

		m_name = Remove(str.substr(0, str.find(",")));
		str.erase(0, str.find(",") + 1);

		m_email = Remove(str.substr(0, str.find(",")));
		str.erase(0, str.find(",") + 1);

		m_size = stoi(Remove(str.substr(0, str.find(","))));
		str.erase(0, str.find(",") + 1);

		m_day = stoi(Remove(str.substr(0, str.find(","))));
		str.erase(0, str.find(",") + 1);

		m_time = stoi(Remove(str));
	}

	std::string Reservation::Remove(std::string str) {
		if (str.find_first_of(' ') != std::string::npos) {
			str.erase(str.find_first_of(' '), str.find_first_not_of(' '));
		}
		if (str.find_last_of(' ') != std::string::npos) {
			str.erase(str.find_last_not_of(' ') + 1, str.find_last_of(' '));
		}
		return str;
	}

	void Reservation::update(int day, int time) {
		m_day = day;
		m_time = time;
	}

	std::ostream& operator<<(std::ostream& ostr, const Reservation& reso) {
		std::string email = "<" + reso.m_email + ">";

		ostr << "Reservation ";
		if (reso.m_time >= 6 && reso.m_time <= 9) {

			ostr << std::setw(10) << std::right << reso.m_id << ": "
				<< std::setw(20) << std::right << reso.m_name << "  "
				<< std::setw(20) << std::left << email
				<< "    Breakfast on day " << reso.m_day << " @ " << reso.m_time << ":00 for ";

			if (reso.m_size > 1) { // if more than one person, change to people
				ostr << reso.m_size << " people.\n";
			}
			else { // else if one person, change to people
				ostr << reso.m_size << " person.\n";
			}
		}
		else if (reso.m_time >= 11 && reso.m_time <= 15) {
			ostr << std::setw(10) << std::right << reso.m_id << ": "
				<< std::setw(20) << std::right << reso.m_name << "  "
				<< std::setw(20) << std::left << email
				<< "    Lunch on day " << reso.m_day << " @ " << reso.m_time << ":00 for ";

			if (reso.m_size > 1) { // if more than one person, change to people
				ostr << reso.m_size << " people.\n";
			}
			else { // else if one person, change to people
				ostr << reso.m_size << " person.\n";
			}
		}
		else if (reso.m_time >= 17 && reso.m_time <= 21) {
			ostr << std::setw(10) << std::right << reso.m_id << ": "
				<< std::setw(20) << std::right << reso.m_name << "  "
				<< std::setw(20) << std::left << email
				<< "    Dinner on day " << reso.m_day << " @ " << reso.m_time << ":00 for ";

			if (reso.m_size > 1) { // if more than one person, change to people
				ostr << reso.m_size << " people.\n";
			}
			else { // else if one person, change to people
				ostr << reso.m_size << " person.\n";
			}
		}
		else {
			ostr << std::setw(10) << std::right << reso.m_id << ": "
				<< std::setw(20) << std::right << reso.m_name << "  "
				<< std::setw(20) << std::left << email
				<< "    Drinks on day " << reso.m_day << " @ " << reso.m_time << ":00 for ";

			if (reso.m_size > 1) { // if more than one person, change to people
				ostr << reso.m_size << " people.\n";
			}
			else { // else if one person, change to people
				ostr << reso.m_size << " person.\n";
			}
		}
		return ostr;
	}
}
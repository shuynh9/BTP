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
		str.erase(remove(str.begin(), str.end(), ' '), str.end()); // removes all white space in string

		m_id = str.substr(0, str.find(":")); // finds id (find string up until ":") and save into member
		str.erase(0, str.find(":") + 1); // erase string up until ":"

		m_name = str.substr(0, str.find(",")); // finds name (find string up until ",") and save into member variable
		str.erase(0, str.find(",") + 1); // erase string up until "," 

		m_email = str.substr(0, str.find(",")); // finds email (find string up until ",") and save into member variable
		str.erase(0, str.find(",") + 1); // erase string up until ","

		m_size = std::stoi(str); // converts int to string
		str.erase(0, str.find(",") + 1); // erase string up until ","

		m_day = std::stoi(str);
		str.erase(0, str.find(",") + 1);

		m_time = std::stoi(str);
		str.erase(0, str.find(",") + 1);
	}

	void Reservation::update(int day, int time) {
		m_day = day;
		m_time = time;
	}

	std::ostream& operator<<(std::ostream& ostr, Reservation& reso) {
		ostr << "Reservation ";
		if (reso.m_time >= 6 && reso.m_time <= 9) {
			ostr.setf(std::ios::right);
			ostr.width(10);
			ostr << reso.m_id;
			ostr << ": ";
			ostr.width(20);
			ostr << reso.m_name;
			ostr << "  ";
			ostr.setf(std::ios::left);
			ostr.width(20);
			ostr << reso.m_email;
			ostr << "  Breakfast on day " << reso.m_day << " @ " << reso.m_time << ":00 for ";
			if (reso.m_size > 1) { // if more than one person, change to people
				ostr << reso.m_size << " people.\n";
			}
			else { // else if one person, change to people
				ostr << reso.m_size << " person.\n";
			}
		}
		else if (reso.m_time >= 11 && reso.m_time <= 15) {
			ostr.setf(std::ios::right);
			ostr.width(10);
			ostr << reso.m_id;
			ostr << ": ";
			ostr.width(20);
			ostr << reso.m_name;
			ostr << "  ";
			ostr.setf(std::ios::left);
			ostr.width(20);
			ostr << reso.m_email;
			ostr << "  Lunch on day " << reso.m_day << " @ " << reso.m_time << ":00 for ";
			if (reso.m_size > 1) { // if more than one person, change to people
				ostr << reso.m_size << " people.\n";
			}
			else { // else if one person, change to people
				ostr << reso.m_size << " person.\n";
			}
		}
		else if (reso.m_time >= 17 && reso.m_time <= 21) {
			ostr.setf(std::ios::right);
			ostr.width(10);
			ostr << reso.m_id;
			ostr << ": ";
			ostr.width(20);
			ostr << reso.m_name;
			ostr << "  ";
			ostr.setf(std::ios::left);
			ostr.width(20);
			ostr << reso.m_email;
			ostr << "  Dinner on day " << reso.m_day << " @ " << reso.m_time << ":00 for ";
			if (reso.m_size > 1) { // if more than one person, change to people
				ostr << reso.m_size << " people.\n";
			}
			else { // else if one person, change to people
				ostr << reso.m_size << " person.\n";
			}
		}
		else {
			ostr.setf(std::ios::right);
			ostr.width(10);
			ostr << reso.m_id;
			ostr << ": ";
			ostr.width(20);
			ostr << reso.m_name;
			ostr << "  ";
			ostr.setf(std::ios::left);
			ostr.width(20);
			ostr << reso.m_email;
			ostr << "  Drinks on day " << reso.m_day << " @ " << reso.m_time << ":00 for ";
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
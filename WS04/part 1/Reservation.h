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
		void update(int day, int time);
		friend std::ostream& operator<<(std::ostream& ostr, Reservation& reso);
	};

}

#endif
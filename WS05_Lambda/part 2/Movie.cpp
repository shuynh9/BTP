/*====================================================================
* Workshop 5: Part 2
* Version: 1.0
* Due Date: 2021/10/17
* Name: Sophia Huynh
* Student Number: 118448208
* Student Email: shuynh9@myseneca.ca
* Professor: Mufleh Al-Shatnawi
* Section: NCC
* I have done all the coding by myself and only copied the code
* that my professor provided to complete my workshops and assignments.
====================================================================*/
#include <iomanip>
#include "Movie.h"

namespace sdds {
	Movie::Movie() {
		m_title = "";
		m_year = 0;
		m_description = "";
	};

	Movie::Movie(const std::string& strMovie) {
		/*
			This constructor extracts the information about the movie from the string and stores the tokens in the attributes. The received string always has the following format:
			```
			TITLE,YEAR,DESCRIPTION
			```
			This constructor removes all spaces from the **beginning and end** of any token in the string.

			When implementing this constructor, consider the following functions:
		  - [std::string::substr()](https://en.cppreference.com/w/cpp/string/basic_string/substr)
		  - [std::string::find()](https://en.cppreference.com/w/cpp/string/basic_string/find)
		  - [std::string::erase()](https://en.cppreference.com/w/cpp/string/basic_string/erase)
		  - [std::stoi()](https://en.cppreference.com/w/cpp/string/basic_string/stol)
		*/
		std::string str = strMovie;

		m_title = Remove(str.substr(0, str.find(',')));
		str.erase(0, str.find_first_of(',') + 1);

		m_year = stoi(Remove(str.substr(0, str.find(','))));
		str.erase(0, str.find_first_of(',') + 1);

		m_description = Remove(str);
	};

	std::string Movie::Remove(std::string str) {
		while (str.front() == ' ') {
			str = str.substr(1, str.length() - 1);
		}
		while (str.back() == ' ') {
			str = str.substr(0, str.length() - 1);
		}
		return str;
	}

	const std::string& Movie::title() const {
		return m_title;
	};

	std::ostream& operator<<(std::ostream& ostr,const Movie& movies) {
		ostr << std::setw(40) << std::right << movies.m_title << " | " << std::setw(4) << movies.m_year << " | " << movies.m_description << std::endl;
		return ostr;
	}
}
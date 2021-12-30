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
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
#include <iostream>

namespace sdds {
	class Movie {
		std::string m_title;
		size_t m_year;
		std::string m_description;
	public:
		Movie();
		Movie(const std::string& strMovie);
		std::string Remove(std::string);
		const std::string& title() const;
		friend std::ostream& operator<<(std::ostream& ostr,const Movie& movies);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}
	};
}

#endif // !SDDS_MOVIE_H

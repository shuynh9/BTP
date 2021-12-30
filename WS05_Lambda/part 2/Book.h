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
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>

namespace sdds {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_description;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		std::string Remove(std::string str);
		friend std::ostream& operator<<(std::ostream& ostr, const Book& book);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_description); // calls overloaded operator() on instance spellChecker, passing it book description
		}
	};
}

#endif // !SDDS_BOOK_H

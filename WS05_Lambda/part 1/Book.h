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
		Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		std::string Remove(std::string str);
		friend std::ostream& operator<<(std::ostream& ostr, const Book& book);
	};
}

#endif // !SDDS_BOOK_H

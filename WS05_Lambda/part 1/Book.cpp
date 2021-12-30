#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"

namespace sdds {
    Book::Book() {
        m_author = "";
        m_title = "";
        m_country = "";
        m_description = "";
        m_year = 0;
        m_price = 0.00;
    }

    const std::string& Book::title() const {
        return m_title;
    }

    const std::string& Book::country() const {
        return m_country;
    }

    const size_t& Book::year() const {
        return m_year;
    }

    double& Book::price() {
        return m_price;
    }

    Book::Book(const std::string& strBook) {
        std::string str = strBook;

        m_author = Remove(str.substr(0, str.find(",")));
        str.erase(0, str.find(",") + 1);

        m_title = Remove(str.substr(0, str.find(",")));
        str.erase(0, str.find(",") + 1);

        m_country = Remove(str.substr(0, str.find(",")));
        str.erase(0, str.find(",") + 1);

        m_price = stod(Remove(str.substr(0, str.find(","))));
        str.erase(0, str.find(",") + 1);

        m_year = stoi(Remove(str.substr(0, str.find(","))));
        str.erase(0, str.find(",") + 1);

        m_description = Remove(str);

    }

    std::string Book::Remove(std::string str) {
        if (str.find_first_of(' ') != std::string::npos) {
            str.erase(str.find_first_of(' '), str.find_first_not_of(' '));
        }
        if (str.find_last_of(' ') != std::string::npos) {
            str.erase(str.find_last_not_of(' ') + 1, str.find_last_of(' '));
        }
        return str;
    }

    std::ostream& operator<<(std::ostream& ostr, const Book& book) {
        ostr << std::setw(20) << book.m_author << " | "
            << std::setw(22) << std::right << book.title() << " | "
            << std::setw(5) << std::right << book.country() << " | "
            << std::setw(4) << book.year() << " | "
            << std::setw(6) << std::setprecision(2) << std::fixed << book.m_price << " | "
            << book.m_description << std::endl;

        return ostr;
    }
}
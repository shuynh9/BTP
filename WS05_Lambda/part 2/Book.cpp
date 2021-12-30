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

        std::string remove = strBook;

        m_author = Remove(remove.substr(0, remove.find(',')));
        remove.erase(0, remove.find_first_of(',') + 1);
   
        m_title = Remove(remove.substr(0, remove.find(',')));
        remove.erase(0, remove.find_first_of(',') + 1);

        m_country = Remove(remove.substr(0, remove.find(',')));
        remove.erase(0, remove.find_first_of(',') + 1);

        m_price = stod(Remove(remove.substr(0, remove.find(','))));
        remove.erase(0, remove.find_first_of(',') + 1);

        m_year = stoi(Remove(remove.substr(0, remove.find(','))));
        remove.erase(0, remove.find_first_of(',') + 1);

        m_description = Remove(remove);
    }
    
    std::string Book::Remove(std::string str) {
        while (str.front() == ' ') {
            str = str.substr(1, str.length() - 1);
        }
        while (str.back() == ' ') {
            str = str.substr(0, str.length() - 1);
        }
        return str;
    }

    std::ostream& operator<<(std::ostream& ostr, const Book& book) {
        ostr << std::setw(20) << std::right << book.m_author << " | " 
            << std::setw(22) << book.m_title << " | " 
            << std::setw(5) << book.m_country << " | " 
            << std::setw(4) << book.m_year << " | " 
            << std::setw(6) << std::setprecision(2) << std::fixed << book.m_price 
            << " | " << book.m_description << std::endl;
        return ostr;
    }
}
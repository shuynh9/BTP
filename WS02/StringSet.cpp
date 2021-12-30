/*====================================================================
* Workshop 2: Part 2
* Version: 1.0
* Date: 2021/09/26
* Name: Sophia Huynh
* Student Number: 118448208
* Student Email: shuynh9@myseneca.ca
* I have done all the coding by myself and only copied the code
* that my professor provided to complete my workshops and assignments.
====================================================================*/
#include <fstream>
#include <string>
#include <cstring>
#include "StringSet.h"

namespace sdds {
	StringSet::StringSet() {
		m_string = nullptr;
		m_size = 0;
	}

	StringSet::StringSet(const char* file) {
		size_t i{ 0 };
		std::ifstream fin(file);
		std::string line; // store extracted characters
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, line, ' ');
				m_size++;
			}
			m_string = new std::string[m_size];
			fin.clear();
			fin.seekg(0);
			while (std::getline(fin, line, ' ')) {
				if (m_size >= i) {
					m_string[i] = line;
				}
				i++;
			}
			fin.close();
		}
	}

	StringSet::~StringSet() {
		delete[] m_string;
		m_string = nullptr;
	}

	StringSet::StringSet(const StringSet& src) {
		m_string = nullptr;
		*this = src;
	}

	StringSet& StringSet::operator=(const StringSet& rhs) {
		if (this != &rhs) {
			delete[] m_string;
			m_size = rhs.m_size;
			m_string = new std::string[m_size];
			for (size_t i{ 0 }; i < m_size; i++) {
				m_string[i] = rhs.m_string[i];
			}
		}
		return *this;
	}

	StringSet::StringSet(StringSet&& src) {
		m_size = 0;
		m_string = nullptr;
		*this = std::move(src);
	}

	StringSet& StringSet::operator=(StringSet&& rhs) {
		if (this != &rhs) {
				delete[] m_string;
				m_string = rhs.m_string;
				m_size = rhs.m_size;
				rhs.m_size = 0; // sets new objects to null
				rhs.m_string = nullptr;
		}
		return *this;
	}

	size_t StringSet::size() const{
		return m_size;
	}

	std::string StringSet::operator[](size_t i) const{
		if (i >= m_size || m_string == nullptr) {
			return "";
		}
		else {
			return m_string[i];
		}
	
	}
}
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
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "SpellChecker.h"

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream fin(filename);
		std::string str;

		if (!fin) {
			throw "Bad file name!";
		}
		for (size_t i{ 0 }; i < MAX; i++) {
			std::getline(fin, str);
			m_badWords[i] = str.substr(0, str.find(' '));
			m_goodWords[i] = str.substr(str.find_last_of(' ') + 1, str.length());
		}
		fin.close();
	}

	void SpellChecker::operator()(std::string& text) {
		for (size_t i{ 0 }; i < MAX; i++) {
			 while(text.find(m_badWords[i]) != std::string::npos) { // if the index position does not equal to the end of the string
					 text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]); // replace bad words with good words
					 ++m_replaced[i]; // keep track of how many times bad words are replaced
				 
			 } 
		}
	}

	void SpellChecker::showStatistics(std::ostream& out)const {
		out << "Spellchecker Statistics\n";

		for (size_t i{ 0 }; i < MAX; i++) {
			out << std::setw(15) << std::right << m_badWords[i] << ": " << m_replaced[i] << " replacements\n";
		}
	}
}


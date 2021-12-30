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
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <string>
constexpr auto MAX = 6;

namespace sdds {
	class SpellChecker {
		std::string m_badWords[MAX];
		std::string m_goodWords[MAX];
		size_t m_replaced[MAX]{};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out)const;
	};

}

#endif // !SDDS_SPELLCHECKER_H

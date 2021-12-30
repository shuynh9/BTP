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
#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H
#include <string>

namespace sdds {
	class StringSet {
		std::string* m_string;
		size_t m_size = 0;
	public:
		StringSet();
		StringSet(const char* m_file);
		~StringSet();
		StringSet(const StringSet& src); // copy constructor
		StringSet& operator=(const StringSet& rhs); // copy assignment
		StringSet(StringSet&& src); // move constructor
		StringSet& operator=(StringSet&& rhs); // move assignment
		size_t size() const;
		std::string operator[](size_t i)const;
	};

}

#endif 
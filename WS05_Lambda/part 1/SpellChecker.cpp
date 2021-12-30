#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "SpellChecker.h"

namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {
		/*
			receives the address of a C-style null-terminated string that holds the name of the file that contains the misspelled words. 
			If the file exists, this constructor loads its contents. 
			If the file is missing, this constructor throws an exception of type `const char*`, with the message `Bad file name!`. 
			Each line in the file has the format `BAD_WORD  GOOD_WORD`; the two fields can be separated by any number of spaces.
		*/

		std::ifstream fin(filename);
		std::string str;

		try {
			if (!filename) {
				throw "Bad file name!";
			}
		}
		catch(const char* str){
			std::cout << str;
		}
		if (filename) {
			std::getline(fin, str);
			for (size_t i{ 0 }; i < 6; i++) {
				m_badWords[i] = str.substr(0, str.find(" "));
				m_goodWords[i] = str.substr(str.find_last_of(" ") + 1, str.length());
			}
			fin.close();
		}
	}

	void SpellChecker::operator()(std::string& text) {
		/*
			this operator searches `text` and replaces any misspelled word with the correct version. 
			It should also count how many times **each** misspelled word has been replaced.

		  When implementing this operator, consider the following functions:
		  - [std::string::find()](https://en.cppreference.com/w/cpp/string/basic_string/find)
		  - [std::string::replace()](https://en.cppreference.com/w/cpp/string/basic_string/replace)
		*/
		for (size_t i{ 0 }; i < 6; i++) {
			while (text.find(m_badWords[i]) != std::string::npos) { // while bad words does not equal to the end of the string
				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]); // replace bad words with good words
				m_replaced++; // keep track of how many times bad words are replaced
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		/*
		  inserts into the parameter how many times each misspelled word has been replaced by the correct word using the current instance. 
		  The format of the output is:
		  ```
		  BAD_WORD: CNT replacements<endl>
		  ```
		  where `BAD_WORD` is to be printed on a field of size 15, aligned to the right.
		*/
		out << std::setw(15) << std::right << "BAD_WORD: " << m_replaced << std::endl;
	}
}


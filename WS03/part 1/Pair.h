/*====================================================================
* Workshop 3: Part 2
* Version: 1.0
* Due Date: 2021/10/03
* Name: Sophia Huynh
* Student Number: 118448208
* Student Email: shuynh9@myseneca.ca
* Professor: Mufleh Al-Shatnawi
* Section: NCC
* I have done all the coding by myself and only copied the code
* that my professor provided to complete my workshops and assignments.
====================================================================*/
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>

namespace sdds {
	template<typename V, typename K>
	class Pair {
		V m_value;
		K m_key;
	public:
		Pair()
			: m_value{}, m_key{} {
		};

		Pair(const K& key, const V& value)
			: m_value{ value }, m_key{ key }{
		};

		const V& value() const {
			return m_value;
		};

		const K& key() const {
			return m_key;
		};

		virtual void display(std::ostream& os) const {
			os << m_key << " : " << m_value << std::endl;
		};
	};
	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	};

}
#endif // !SDDS_PAIR_H

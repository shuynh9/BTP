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
#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include "Pair.h"

namespace sdds {
	template<typename V, typename K>
	class PairSummable : public Pair<V, K> {
		static V m_initialValue;
		static size_t m_minWidth;
	public:
		PairSummable() {
		};

		PairSummable(const K& key, const V& value = m_initialValue)
			: Pair<V, K>{ key, value } {
			if (m_minWidth < key.size()) {
				m_minWidth = key.size();
			}
		};

		bool isCompatibleWith(const PairSummable<V, K>& b)const {
			return this->key() == b.key();
		};

		PairSummable<V, K>& operator+=(const PairSummable& obj) {
			if (this != &obj && this->key() == obj.key()) {
				*this = PairSummable(this->key(), this->value() + obj.value());
			}
			return *this;
		}

		virtual void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(m_minWidth);
			this->Pair<V, K>::display(os);
			os.unsetf(std::ios::left);
		};
	};
	// Specializations
	template<typename V, typename K>
	size_t PairSummable<V, K>::m_minWidth{ 0 };

	// hold initial value for summation
	template<typename V, typename K>
	V PairSummable<V, K>::m_initialValue{};

	// Concatenate V = string and K = string
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& src) {
		if (this != &src && src.key() == this->key()) {
			if (this->value() != "") {
				*this = PairSummable(this->key(), this->value() + ", " + src.value());
			}
			else {
				*this = PairSummable(this->key(), this->value() + src.value());
			}
		}
		return *this;
	};
}
#endif // !SDDS_PAIRSUMMABLE_H

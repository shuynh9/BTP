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
#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <cstddef>
namespace sdds {
	template<unsigned int N, typename T>
	class Set {
		T m_array[N];
		size_t m_size = 0;
	public:
		size_t size() const {
			return m_size;
		};

		const T& get(size_t idx) const {
			return m_array[idx];
		};

		void operator+=(const T& item) {
			if (size() < N) {
				m_array[size()] = item;
				m_size++;
			}
		};
	};
}

#endif // !SDDS_SET_H

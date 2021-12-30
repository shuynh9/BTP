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
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>
#include <iostream>

namespace sdds {
	template<typename T> 
	class Collection {
		std::string m_name;
		T* m_array;
		size_t m_size;
		void (*m_observe)(const Collection<T>&, const T&);
	public:

		Collection(const std::string& name) 
			: m_name{ name } {
			m_array = nullptr;
			m_size = 0;
			m_observe = nullptr;
		};

		~Collection() {
			if (m_array != nullptr) {
				delete[] m_array;
				m_array = nullptr;
			}
		};
		const std::string& name()const {
			return m_name;
		};

		size_t size() const {
			return m_size;
		};

		Collection(const Collection<T>&) = delete;
		Collection<T>& operator=(const Collection<T>&) = delete;
		Collection<T>& operator+=(const T& item) {
			bool flag{ false };
			for (size_t i{ 0 }; i < m_size && !flag; i++) {
				flag = (m_array[i].title() == item.title());
			}
			if (!flag) {
				T* new_size = new T[m_size + 1];
				for (size_t j{ 0 }; j < m_size; j++) {
					new_size[j] = m_array[j];
				}
				delete[] m_array;
				new_size[m_size] = item;
				m_array = new_size;
				m_size++;
				if (m_observe) {
					m_observe(*this, item);
				}
			}
			return *this;
		};

		T& operator[](size_t idx) const {
			std::string err_msg = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";

			if (idx >= m_size || idx < 0) {
				throw std::out_of_range(err_msg);
			}
			else {
				return m_array[idx];
			}
		};

		T* operator[](const std::string& title)const {
			for (size_t i{ 0 }; i < m_size; i++) {
				if (m_array[i].title() == title) {
					return &m_array[i];
				}
			}
			return nullptr;
		};

		void setObserver(void (*observer)(const Collection<T>&, const T&)){
			m_observe = observer;
		}; // stores address of callback function
	};

	// Helper Function
	template<typename T>
	std::ostream& operator<<(std::ostream& ostr, const Collection<T>& collections) {
		for (size_t i{ 0 }; i < collections.size(); i++) {
			ostr << collections[i];
		}
		return ostr;
	};
}
#endif // !SDDS_COLLECTION_H

#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds {
	template<size_t N, class T>
	class Set {
		T m_array[N];
		size_t m_size=0;
	public:
		size_t size() const {
			return m_size;
		};

		const T& get(size_t idx) const {
			return m_array[idx];
		};

		void operator+=(const T& item) {
			if (m_size < N) {
				m_array[m_size] = item;
				m_size++;
			}
		};
	};
}

#endif // !SDDS_SET_H

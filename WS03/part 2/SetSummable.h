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
#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include <string>
#include "Set.h"
namespace sdds {
    template<size_t N, typename T>
    class SetSummable : public Set<N, T> {
    public:
        T accumulate(const std::string& filter) const {
            T m_accumulate(filter);
            for (size_t i{ 0 }; i < this->size(); i++) {
                if (m_accumulate.isCompatibleWith(this->get(i))){
                    m_accumulate += this->get(i);
                }
            }
            return m_accumulate;
        };
    };
}

#endif // !SDDS_SETSUMMABLE_H

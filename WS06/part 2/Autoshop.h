/*====================================================================
* Workshop 6: Part 2
* Version: 1.0
* Due Date: 2021/11/07
* Name: Sophia Huynh
* Student Number: 118448208
* Student Email: shuynh9@myseneca.ca
* Professor: Mufleh Al-Shatnawi
* Section: NCC
* I have done all the coding by myself and only copied the code
* that my professor provided to complete my workshops and assignments.
====================================================================*/
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"
namespace sdds {
	class Autoshop {
		std::vector<Vehicle*>m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* aVehicle);
		void display(std::ostream& out)const;
		~Autoshop();
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto testCar = m_vehicles.begin(); testCar != m_vehicles.end(); testCar++) {
				if (test((*testCar))) {
					vehicles.push_back((*testCar));
				}
			}
		}
	};
}

#endif // !SDDS_AUTOSHOP_H

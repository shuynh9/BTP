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
#include <iostream>
#include "TimedEvents.h"

namespace sdds {

	TimedEvents::TimedEvents() {
		m_event[0].m_eventName = "";
		m_event[0].m_unitOfTime = "";
	}

	void TimedEvents::startClock() { // start timer for event
		time_start = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() { // stop timer for event
		time_end = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* eventName) {
		m_event[m_noOfRecords].m_eventName = eventName; // sets name to given event name
		m_event[m_noOfRecords].m_unitOfTime = "nanoseconds"; // utilize nanoseconds
		m_event[m_noOfRecords].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(time_end - time_start); // to find duration 
		m_noOfRecords++;
	}

	std::ostream& operator<<(std::ostream& ostr, TimedEvents& event) {
		ostr << "--------------------------" << std::endl;
		ostr << "Execution Times:" << std::endl;
		ostr << "--------------------------" << std::endl;

		for (int i{ 0 }; i < event.m_noOfRecords; i++) {
			ostr.setf(std::ios::left);
			ostr.width(20);
			ostr << event.m_event[i].m_eventName << " ";
			ostr.setf(std::ios::right);
			ostr.width(12);
			ostr << event.m_event[i].m_duration.count() << " " << event.m_event[i].m_unitOfTime << std::endl;
			ostr.unsetf(std::ios::right);
		}
		ostr << "--------------------------" << std::endl;
		return ostr;
	}

}
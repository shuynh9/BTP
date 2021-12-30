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
#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include <chrono>
#include <string>

namespace sdds {
	class TimedEvents {
		int m_noOfRecords{ 0 };
		std::chrono::steady_clock::time_point time_start; // start time for current event
		std::chrono::steady_clock::time_point time_end; // end time for current event
		struct Event {
			std::string m_eventName;
			std::string m_unitOfTime;
			std::chrono::steady_clock::duration m_duration; // duration of recorded event
		};
		Event m_event[10];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* eventName);
		friend std::ostream& operator<<(std::ostream& ostr,TimedEvents& event);
	};
}
#endif // !SDDS_TIMEDEVENTS_H

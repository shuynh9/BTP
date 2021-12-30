/*====================================================================
* Workshop 1: Part 2
* Version: 1.0
* Date: 2021/09/17
* Name: Sophia Huynh
* Student Number: 118448208
* Student Email: shuynh9@myseneca.ca
* I have done all the coding by myself and only copied the code
* that my professor provided to complete my workshops and assignments.
====================================================================*/
#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

namespace sdds {
	class Event {
	private:
		char *m_description;
		unsigned int m_time; // in seconds
	public:
		Event();
		~Event();
		Event(const Event& src);
		Event& operator=(const Event& rhs);
		void display();
		void set(char* address = nullptr);
	};

}
#endif // !SDDS_EVENT_H

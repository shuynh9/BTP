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
#include <iostream>
#include <cstring>
#include "event.h"

unsigned int g_sysClock = 0;

namespace sdds {
    Event::Event() {
        m_description = nullptr;
        m_time = 0;
    }

    Event::~Event() {
        delete[] m_description;
        m_description = nullptr;
    }

    Event::Event(const Event& src){
        *this = src;
    }

    Event& Event::operator=(const Event& rhs) {
        if (this != &rhs) {
            if (rhs.m_description) {
                m_description = new char[strlen(rhs.m_description) + 1];
                strcpy(m_description, rhs.m_description);
            }
            else {
                m_description = nullptr;
            }
            m_time = rhs.m_time;
        }
      
        return *this;
    }

	void Event::display() {
        static int counter{ 1 }; // static counter that last lifetime of program
        int hours = m_time / 3600;
        int minutes = (m_time - (hours * 3600))/60;
        int seconds = (m_time - (hours * 3600) - (minutes * 60));
        std::cout.width(2);
        std::cout.fill(' ');
        std::cout << counter << ". ";
        
        if (m_description != nullptr) {
            std::cout.width(2);
            std::cout.fill('0');
            std::cout << hours << ":";
            std::cout.width(2);
            std::cout.fill('0');
            std::cout << minutes << ":";
            std::cout.width(2);
            std::cout.fill('0'); 
            std::cout << seconds;
            std::cout << " => " << m_description << std::endl;
        }
        else {
            std::cout << "| No Event |" << std::endl;
        }
        counter++;
	}

	void Event::set(char* address) {
        if (address != nullptr && address[0] != '\0') {
            m_time = g_sysClock;
            if (address) {
                delete[] m_description;
                m_description = new char[strlen(address) + 1];
                strcpy(m_description, address);
            }
        }
        else {
            delete[] m_description;
            m_description = nullptr; 
            m_time = 0;
        }
     }
}
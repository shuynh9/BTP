/*====================================================================
* Workshop 7: Part 2
* Due Date: 2021/11/14
* Name: Sophia Huynh
* Student Number: 118448208
* Student Email: shuynh9@myseneca.ca
* Professor: Mufleh Al-Shatnawi
* Section: NCC
* I have done all the coding by myself and only copied the code
* that my professor provided to complete my workshops and assignments.
====================================================================*/
#ifndef  SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <string>
#include <vector>
#include <list>
#include <iostream>

namespace sdds {
	struct Song {
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		std::string m_release;
		size_t m_length;
	};

	class SongCollection {
		std::vector<Song> m_collection;
	public:
		SongCollection(const char* song);
		void display(std::ostream& out)const;
		void sort(std::string str);
		void cleanAlbum();
		bool inCollection(std::string artist) const;
		std::list<Song>getSongsForArtist(std::string artist)const;
	};
	// Helper Function
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // ! SDDS_SONGCOLLECTION_H

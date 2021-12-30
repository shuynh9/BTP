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
#include <algorithm>
#include <fstream>
#include <numeric>
#include <iomanip>
#include "SongCollection.h"

namespace sdds {
	SongCollection::SongCollection(const char* song) {
		auto cut = [](std::string trim) {
			if ((!trim.empty() && !all_of(trim.begin(), trim.end(), isspace))) { // if not empty and no space at beginning and end
				while (trim.at(0) == ' ') { // if first index is space, trim it
					trim = trim.substr(1, trim.length() - 1);
				}
				while (trim.at(trim.length() - 1) == ' ') { // if last index is space, trim it
					trim = trim.substr(0, trim.length() - 1);
				}
			}
			return trim;
		};

		std::string str = "";
		std::fstream song_str; // create instance of file
		song_str.open(song); // open song file

		if (!song_str) { // if file is invalid, throw error msg
			throw "File Cannot Be Opened!";
		}
		else {
			while (std::getline(song_str, str)) {
				if (!str.empty()) {
					Song temp; // temp Song object
					size_t len{ 0 };
					// Trim file
					temp.m_title = cut(str.substr(0, 24)); // trim title of song
					temp.m_artist = cut(str.substr(24, 25)); // trim artist of song
					temp.m_album = cut(str.substr(50, 25)); // trim album of song
					temp.m_release = cut(str.substr(75, 5)); // trim song release
					len = std::stoi(cut(str.substr(80, 5))); // get length of song
					temp.m_length = len;
					temp.m_price = std::stod(cut(str.substr(85, 5))); // trim price of song
					m_collection.push_back(temp); // add song to vector
				}
			}
		}
	}

	void SongCollection::display(std::ostream& out)const {

		// lambda to display songs
		auto displaySongs = [&](const Song& music) {
			out << music << std::endl;
		};

		// lambda working with time
		auto time = [](int total, const Song& songs) {
			total += songs.m_length;
			return total;
		};

		size_t total_time = std::accumulate(m_collection.begin(), m_collection.end(), 0, time); // total song time
		for_each(m_collection.begin(), m_collection.end(), displaySongs); // iterate vector

		// time conversions
		size_t hours = total_time / 3600; // hours

		total_time = total_time % 3600; // minutes
		size_t minutes = total_time / 60;

		total_time = total_time % 60; // seconds
		size_t seconds = total_time;

		out << "----------------------------------------------------------------------------------------\n";
		out << "|                                                        ";
		out << "Total Listening Time: " << hours << ":" << minutes << ":" << seconds << " |" << std::endl;

	}

	void SongCollection::sort(std::string str) {
		if (str == "title") {
			std::sort(m_collection.begin(), m_collection.end(), [](const Song& first, const Song& second) {
				return first.m_title < second.m_title; // compare first and second song, return in alphabetical order
			});
		}
		else if (str == "album") {
			std::sort(m_collection.begin(), m_collection.end(), [](const Song& first, const Song& second) {
				return first.m_album < second.m_album; // compare album of songs, return in ascending order
			});
		}
		else { // else it will be sorted by length
			std::sort(m_collection.begin(), m_collection.end(), [](const Song& first, const Song& second) {
				return first.m_length < second.m_length; // compare length of songs, return in ascending order
			});
		}
	}

	void SongCollection::cleanAlbum() {
		auto clean = [](Song& cleanup) {
			if (cleanup.m_album == "[None]") { // if album has "[None]", remove it
				cleanup.m_album.clear();
			}
		};
		std::for_each(m_collection.begin(), m_collection.end(), clean); // iterate through vector to clean up album
	}

	bool SongCollection::inCollection(std::string artist) const {
		size_t i{ 0 };
		auto artist_check = [&](const Song& collection) {
			if (artist == collection.m_artist) { // if parameter is same as artist of song
				i++;
			}
		};
		std::for_each(m_collection.begin(), m_collection.end(), artist_check); // iterate through vector to check for matching artists
		return i;
	}

	std::list<Song> SongCollection::getSongsForArtist(std::string artist)const {
		std::list<Song> collection(m_collection.size()); // get all songs

		auto compare_artist = [&](const Song& name) { // check name of artists for match
			return name.m_artist == artist;
		};

		auto copy_songs = std::copy_if(m_collection.begin(), m_collection.end(), collection.begin(), compare_artist); // copy songs

		collection.resize(std::distance(collection.begin(), copy_songs)); // cut name of artist that aren't wanted
		return collection;
	}

	// Helper Function
	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		size_t minutes = theSong.m_length / 60; // conversion to minutes
		size_t seconds = theSong.m_length % 60; // conversion to seconds
		out << "| " << std::setw(20) << std::left << theSong.m_title;
		out << " | " << std::setw(15) << std::left << theSong.m_artist;
		out << " | " << std::setw(20) << std::left << theSong.m_album;
		out << " | " << std::setw(6) << std::right << theSong.m_release;
		out << " | " << minutes << ":";

		if (seconds < 10) { // seconds for the duration of the song
			out << "0" << seconds;
		}
		else {
			out << seconds;
		}

		out << " | " << theSong.m_price << " |"; // price 
		return out;
	}
}
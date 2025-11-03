/*
 * Belle Biery
 * 11/3/25
 * Music media class, inherits base Media class
 */
#include <iostream>
#include "Music.h"

using namespace std;

// Default Constructor
Music::Music():Media() {

	artist = new char[80];
	duration = 0;
	publisher = new char[80];

}

// Parameterized Constructor
Music::Music(char* setTitle, char* setArtist, int setYear, float setDuration, char* setPublisher): 
	Media(setTitle, setYear), 
	artist(setArtist),
	duration(setDuration),
	publisher(setPublisher) {}

// Returns artist
char* Music::getArtist() {
	return artist;
}

// Returns duration
float Music::getDuration() {
	return duration;
}

// Returns publisher
char* Music::getPublisher() {
	return publisher;
}

// Prints details
void Music::printDetails() {

	cout    << "Title: " << title << endl
		<< "Artist: " << artist << endl
		<< "Year: " << year << endl
		<< "Duration: " << duration << endl
		<< "Publisher: " << publisher << endl;
}

// Deconstructor
Music::~Music() {
	delete[] artist;
	delete[] publisher;
	artist = nullptr;
	publisher = nullptr;
}

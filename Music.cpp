#include <iostream>
#include "Music.h"

using namespace std;

Music::Music():Media() {

	artist = new char[80];
	duration = 0;
	publisher = new char[80];

}

Music::Music(char* setTitle, char* setArtist, int setYear, float setDuration, char* setPublisher): 
	Media(setTitle, setYear), 
	artist(setArtist),
	duration(setDuration),
	publisher(setPublisher) {}

char* Music::getArtist() {
	return artist;
}

float Music::getDuration() {
	return duration;
}

char* Music::getPublisher() {
	return publisher;
}

void Music::printDetails() {

	cout    << "Title: " << title << endl
		<< "Artist: " << artist << endl
		<< "Year: " << year << endl
		<< "Duration: " << duration << endl
		<< "Publisher: " << publisher << endl;
}

Music::~Music() {
	delete[] artist;
	delete[] publisher;
	artist = nullptr;
	publisher = nullptr;
}

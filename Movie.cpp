/*
 * Belle Biery
 * 11/3/25
 * Movie media class, inherits base Media class
 */
#include <iostream>
#include "Movie.h"

using namespace std;

// Default constructor
Movie::Movie(): Media() {
	director = new char[80];
	duration = 0;
	rating = 0;
}

// Parameterized constructor
Movie::Movie(char* setTitle, char* setDirector, int setYear, float setDuration, float setRating): 
	Media(setTitle, setYear),
	director(setDirector),
	duration(setDuration),
	rating(setRating) {}

// Returns director
char* Movie::getDirector() {
	return director;
}

// Returns duration
float Movie::getDuration() {
	return duration;
}

// Returns rating
float Movie::getRating() {
	return rating;
}

// Prints deatils about the movie
void Movie::printDetails() {

	cout    << "Title: " << title << endl
		<< "Director: " << director << endl
		<< "Year: " << year << endl
		<< "Duration: " << duration << endl
		<< "Rating: " << rating << endl;
}

// Deconstructor
Movie::~Movie() {
	delete[] director;
	director = nullptr;
}

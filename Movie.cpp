#include <iostream>
#include "Movie.h"

using namespace std;

Movie::Movie(): Media() {
	director = new char[80];
	duration = 0;
	rating = 0;
}

Movie::Movie(char* setTitle, char* setDirector, int setYear, float setDuration, float setRating): Media(setTitle, setYear) {
	director = setDirector;
	duration = setDuration;
	rating = setRating;
}

char* Movie::getDirector() {
	return director;
}

float Movie::getDuration() {
	return duration;
}

float Movie::getRating() {
	return rating;
}

void Movie::printDetails() {

	cout    << "Title: " << title << endl
		<< "Director: " << director << endl
		<< "Year: " << year << endl
		<< "Duration: " << duration << endl
		<< "Rating: " << rating << endl;
}

Movie::~Movie() {
	delete[] director;
	director = nullptr;
}

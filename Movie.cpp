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

Movie::~Movie() {
	delete[] director;
	director = nullptr;
}

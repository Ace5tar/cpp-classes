/* 
 * Belle Biery
 * 11/3/25
 * Base media class for all types of media
 */
#include <iostream>
#include "Media.h"

using namespace std;

// Default constructor
Media::Media() {

	title = new char[80];
	year = 0;

}

// Parameterized constructor
Media::Media(char* setTitle, int setYear): 
	title(setTitle), 
	year(setYear){}

// Returns the year
int Media::getYear() {

	return year;

}

// Returns the title
char* Media::getTitle() {

	return title;

}

// Prints all of the information about a given media
// This method should never be called, as it is from the parent class
// Is virtual 
void Media::printDetails() {

	cout << "WARNING: PRINTED PARENT MEDIA CLASS" << endl;
	cout    << "Title: " << title << endl
		<< "Year: " << year << endl;
}

// Deconstructor, deallocates memory and sets pointer to null
// is virtual
Media::~Media() {

	delete[] title;
	title = nullptr;

}

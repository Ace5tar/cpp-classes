#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

Media::Media() {

	title = new char[80];
	year = 0;

}

Media::Media(char* setTitle, int setYear) {
	title = setTitle;
	year = setYear;
}

int Media::getYear() {

	return year;

}

char* Media::getTitle() {

	return title;

}

void Media::printDetails() {

	cout << "WARNING: PRINTED PARENT MEDIA CLASS" << endl;
	cout    << "Title: " << title << endl
		<< "Year: " << year << endl;
}

Media::~Media() {
	delete[] title;
	title = nullptr;
}

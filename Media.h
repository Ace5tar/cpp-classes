#include <iostream>
#include <cstring>

using namespace std;

#ifndef MEDIA_H
#define MEDIA_H

class Media {
	public:
		Media();
		Media(char* setTitle, int setYear);
		int getYear();
		char* getTitle();
		virtual void printDetails();
		~Media();
	protected:
		int year;
		char* title;
};

#endif

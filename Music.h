/*
 * Belle Biery
 * 11/3/25
 * Header file for Music class
 */
#include <iostream>
#include "Media.h"

using namespace std;

class Music: public Media {
	public:
		Music();
		Music(char* setTitle, char* setArtist, int setYear, float setDuration, char* setPublisher);
		char* getArtist();
		float getDuration();
		char* getPublisher();
		void printDetails();
		~Music();
	protected:
		char* artist;
		float duration;
		char* publisher;

};

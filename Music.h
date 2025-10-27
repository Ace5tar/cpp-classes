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
	protected:
		char* artist;
		float duration;
		char* publisher;

};

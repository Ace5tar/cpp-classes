#include <iostream>
#include "Media.h"

using namespace std;

class Movie: public Media{
	public:
		Movie();
		Movie(char* setTitle, char* setDirector, int setYear, float setDuration, float setRating);
		char* getDirector();
		float getDuration();
		float getRating();
		~Movie();
	protected:
		char* director;
		float duration;
		float rating;
};

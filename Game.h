#include <iostream>
#include "Media.h"

using namespace std;

class Game: public Media {

	public:
		Game();
		Game(char* setTitle, int setYear, char* setPublisher, float setRating);
		char* getPublisher();
		float getRating();
		void printDetails();
		~Game();
	protected:
		char* publisher;
		float rating;

};

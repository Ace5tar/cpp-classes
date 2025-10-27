#include <iostream>
#include <cstring>

using namespace std;

class Media {
	public:
		Media();
		Media(char* setTitle, int setYear);
		int getYear();
		char* getTitle();
	protected:
		int year;
		char* title;
};

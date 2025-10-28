/*
 * https://stackoverflow.com/questions/17017563/char-array-with-cin-getline
 */


#include <iostream>
#include <cstring>
#include <vector>
#include "Media.h"
#include "Game.h"
#include "Movie.h"
#include "Music.h"

using namespace std;

void clearVars(vector<Media*>& mediaVect) {

	//Delete each media in list
	for (Media* media : mediaVect) {
		delete media;
	}
}

void addMedia(vector<Media*>& mediaVect) {

	// Note: before cin.getline must used cin.ignore to clear buffer

	char input[80];
	
	cout << "What kind of media do you want to add? ('GAME', 'MOVIE', or 'MUSIC')" << endl;
	cin >> input;

	if (strcmp(input, "GAME") == 0) {
	
		cout << "Title:" << endl;
		char title[80];
		cin.ignore();
		cin.getline(title, 80);

		cout << "Year:" << endl;
		int year;
		cin >> year;

		cout << "Publisher:" << endl;
		char pub[80];
		cin.ignore();
		cin.getline(pub, 80);

		cout << "Rating:" << endl;
		float rating;
		cin >> rating;

		Game* newGame = new Game(title, year, pub, rating);

		mediaVect.push_back(newGame);

		return;
	
	}

	if (strcmp(input, "MOVIE") == 0) {

		cout << "Title:" << endl;
		char title[80];
		cin.ignore();
		cin.getline(title, 80);

		cout << "Director:" << endl;
		char director[80];
		cin.ignore();
		cin.getline(director, 80);

		cout << "Year:" << endl;
		int year;
		cin >> year;

		cout << "Duration:" << endl;
		float duration;
		cin >> duration;

		cout << "Rating:" << endl;
		float rating;
		cin >> rating;

		Movie* newMovie = new Movie(title, director, year, duration, rating);

		mediaVect.push_back(newMovie);

		return;
	}

	if (strcmp(input, "MUSIC") ==0) {
		//INIT MUSIC
		return;
	}
	cout << "Error: Invalid media type. Options are 'GAME', 'MOVIE', or 'MUSIC'." << endl;




}

int main() {

	char input[80];

	vector<Media*> mediaVect;

	bool running = true;

	while(running) {

		cin >> input;
		if (strcmp(input, "QUIT") == 0) running = false; 
		if (strcmp(input, "ADD") == 0) addMedia(mediaVect); 

	}

	clearVars(mediaVect);
	return 0;

}

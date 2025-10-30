/*
 * https://stackoverflow.com/questions/17017563/char-array-with-cin-getline
 * https://stackoverflow.com/questions/120876/what-are-the-rules-for-calling-the-base-class-constructor
 * https://stackoverflow.com/questions/120876/what-are-the-rules-for-calling-the-base-class-constructor
 */


#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
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

	// Note: sometimes before cin.getline must use cin.ignore to clear buffer

	char input[80];
	
	cout << "What kind of media do you want to add? ('GAME', 'MOVIE', or 'MUSIC')" << endl;
	cin >> input;

	if (strcmp(input, "GAME") == 0) {
	
		cout << "Title:" << endl;
		char* title = new char[80];
		cin.ignore();
		cin.getline(title, 80);

		cout << "Year:" << endl;
		int year;
		cin >> year;

		cout << "Publisher:" << endl;
		char* pub = new char[80];
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
		char* title = new char[80];
		cin.ignore();
		cin.getline(title, 80);

		cout << "Director:" << endl;
		char* director = new char[80];
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

		cout << "Title:" << endl;
		char* title = new char[80];
		cin.ignore();
		cin.getline(title, 80);

		cout << "Artist:" << endl;
		char* artist = new char[80];
		cin.getline(artist, 80);

		cout << "Year:" << endl;
		int year;
		cin >> year;

		cout << "Duration:" << endl;
		float duration;
		cin >> duration;

		cout << "Publisher:" << endl;
		char* publisher = new char[80];
		cin.ignore();
		cin.getline(publisher, 80);
		
		Music* newMusic = new Music(title, artist, year, duration, publisher);

		mediaVect.push_back(newMusic);

		return;
	}
	cout << "Error: Invalid media type. Options are 'GAME', 'MOVIE', or 'MUSIC'." << endl;




}

vector<Media*> searchMedia(vector<Media*>& mediaVect) {

	vector<Media*> foundMedia;
	char input[80];

	cout << "Would you like to search by 'YEAR' or 'TITLE'?" << endl;
	cin >> input;

	if (strcmp(input, "YEAR") == 0) {
		cout << "Input year: ";
		cin >> input;

		for (Media* media: mediaVect) {
			if (media->getYear() == atoi(input)) {
				foundMedia.push_back(media);
			}
	 	}
	} else if (strcmp(input, "TITLE") == 0) {
		cout << "Input title: ";
		cin >> input;
	
		for (Media* media : mediaVect) {
			if (strcmp(media->getTitle(), input) == 0) {
				foundMedia.push_back(media);
			}
		
		}	

	} else {
		cout << "invalid choice" << endl;
	}
	if (foundMedia.size() == 0) cout << "No media found!" << endl;
	return foundMedia;
}

void printMedia(vector<Media*>& mediaVect) {
	for (Media* media : searchMedia(mediaVect)) {
		media->printDetails();
	}
}

void deleteMedia(vector<Media*>& mediaVect) {
	char input;
	int index = 0;

	for (Media* media : searchMedia(mediaVect)) {
		cout << "Are you sure you want to delete \"" << media->getTitle() << "\"? ('y', or 'n')" << endl;
		cin >> input;
		if (input == 'y') {
			index = 0;
			for (Media* mediaInMain : mediaVect) {
				if (mediaInMain = media) {
					delete mediaInMain;
					mediaVect.erase(mediaVect.begin() + index);
					++index;
				}
			}
		}
	}
}


int main() {

	char input[80];

	vector<Media*> mediaVect;

	bool running = true;

	while(running) {

		cin >> input;
		if (strcmp(input, "QUIT") == 0) running = false; 
		if (strcmp(input, "ADD") == 0) addMedia(mediaVect); 
		if (strcmp(input, "SEARCH") == 0) printMedia(mediaVect);
		if (strcmp(input, "DELETE") == 0) deleteMedia(mediaVect);

	}

	clearVars(mediaVect);
	return 0;

}

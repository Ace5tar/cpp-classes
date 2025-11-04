/*
 * Belle Biery
 * 11/4/25
 * Database for storing and accessing different kinds of media 
 *
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

// Deallocate memory to prevent memory leaks
void clearVars(vector<Media*>& mediaVect) {

	//Delete each media in list
	for (Media* media : mediaVect) {
		delete media;
	}
}

// Add a media to the main vector
void addMedia(vector<Media*>& mediaVect) {

	// Note: sometimes before cin.getline must use cin.ignore to clear buffer

	char input[80];
	
	// Ask what kind of media to add
	cout << "What kind of media do you want to add? ('GAME', 'MOVIE', or 'MUSIC')" << endl;
	cin >> input;

	if (strcmp(input, "GAME") == 0) {
	
		// Ask for title 
		cout << "Title:" << endl;
		char* title = new char[80];
		cin.ignore();
		cin.getline(title, 80);

		// Ask for year
		cout << "Year:" << endl;
		int year;
		cin >> year;

		// Ask for publisher
		cout << "Publisher:" << endl;
		char* pub = new char[80];
		cin.ignore();
		cin.getline(pub, 80);

		// Ask for rating
		cout << "Rating:" << endl;
		float rating;
		cin >> rating;

		// Create new game pointer
		Game* newGame = new Game(title, year, pub, rating);

		// Append it to the media vector
		mediaVect.push_back(newGame);

		cout << "\"" << newGame->getTitle() << "\" added!" << endl; 

		return;
	
	}

	if (strcmp(input, "MOVIE") == 0) {

		// Ask for title
		cout << "Title:" << endl;
		char* title = new char[80];
		cin.ignore();
		cin.getline(title, 80);

		// Ask for director
		cout << "Director:" << endl;
		char* director = new char[80];
		cin.getline(director, 80);

		// Ask for year
		cout << "Year:" << endl;
		int year;
		cin >> year;

		// Ask for duration
		cout << "Duration:" << endl;
		float duration;
		cin >> duration;

		// Ask for rating
		cout << "Rating:" << endl;
		float rating;
		cin >> rating;

		// Create new movie pointer
		Movie* newMovie = new Movie(title, director, year, duration, rating);

		// Append it to the media vector
		mediaVect.push_back(newMovie);

		cout << "\"" << newMovie->getTitle() << "\" added!" << endl; 

		return;
	}

	if (strcmp(input, "MUSIC") ==0) {

		// Ask for title
		cout << "Title:" << endl;
		char* title = new char[80];
		cin.ignore();
		cin.getline(title, 80);
	
		// Ask for artist
		cout << "Artist:" << endl;
		char* artist = new char[80];
		cin.getline(artist, 80);

		// Ask for year
		cout << "Year:" << endl;
		int year;
		cin >> year;

		// Ask for duration
		cout << "Duration:" << endl;
		float duration;
		cin >> duration;

		// Ask for publisher
		cout << "Publisher:" << endl;
		char* publisher = new char[80];
		cin.ignore();
		cin.getline(publisher, 80);
		
		// Create new music pointer
		Music* newMusic = new Music(title, artist, year, duration, publisher);

		// Append it to the media vector
		mediaVect.push_back(newMusic);

		cout << "\"" << newMusic->getTitle() << "\" added!" << endl; 

		return;
	}
	// Only reaches here if media type was not in options
	cout << "Error: Invalid media type. Options are 'GAME', 'MOVIE', or 'MUSIC'." << endl;




}

// Iterates through all media and returns a vector of all matching media
vector<Media*> searchMedia(vector<Media*>& mediaVect) {

	vector<Media*> foundMedia;
	char input[80];

	// Ask for search type
	cout << "Would you like to search by 'YEAR' or 'TITLE'?" << endl;
	cin >> input;

	if (strcmp(input, "YEAR") == 0) {
		// Get year to search for
		cout << "Input year: ";
		cin >> input;

		// Iterate over media vector
		for (Media* media: mediaVect) {
			if (media->getYear() == atoi(input)) {
				// If year matches append to foundMedia
				foundMedia.push_back(media);
			}
	 	}
	} else if (strcmp(input, "TITLE") == 0) {
		// Get title to search for
		cout << "Input title: ";
		cin.ignore();
		cin.getline(input, 80);
	
		// Iterate over media vector
		for (Media* media : mediaVect) {
			if (strcmp(media->getTitle(), input) == 0) {
				// If title matches append to foundMedia
				foundMedia.push_back(media);
			}
		}	

	} else {
		// Gave invalid option, return empty vector	
		cout << "Invalid choice! Please use 'YEAR' or 'TITLE'." << endl;
		return foundMedia;
	}
	// If vector is empty then no media was found
	if (foundMedia.size() == 0) cout << "No media found matching description!" << endl;
	return foundMedia;
}

// Allows user to search for media and calls printDetails funtion for each matching media
void printMedia(vector<Media*>& mediaVect) {
	for (Media* media : searchMedia(mediaVect)) {
		media->printDetails();
	}
}

// Allows user to search for media and delete any of their choice.
void deleteMedia(vector<Media*>& mediaVect) {
	char input;
	int index = 0;

	for (Media* media : searchMedia(mediaVect)) {
		// Promt user for confirmation
		cout << "Are you sure you want to delete \"" << media->getTitle() << "\"? ('y', or 'n')" << endl;
		cin >> input;
		if (input == 'y') {
			index = 0;
			// Iterate over each media in the media vector
			for (Media* mediaInMain : mediaVect) {
				// If the media in the media vector is the one to delete
				if (mediaInMain = media) {
					cout << "\"" << media->getTitle() << "\" successfully deleted!" <<endl;
					// Deallocate the memory
					delete mediaInMain;
					// Remove pointer from the vector
					mediaVect.erase(mediaVect.begin() + index);
					
				}
				++index;
			}
		}
	}
}


// Show a list of commands
void showHelp() {
	cout	<< "'QUIT' - Exit the program." << endl
		<< "'ADD' - Create a new media entry." << endl
		<< "'SEARCH' - Search for media by title or year." << endl
		<< "'DELETE' - Remove media from the main list." << endl
		<< "'HELP' - Show this help menu." << endl;
}

int main() {

	char input[80];

	vector<Media*> mediaVect;

	bool running = true;

	cout << "Welcome to the media management database! Here is the list of commands: " << endl;
	showHelp();

	while(running) {

		cin >> input;
		if (strcmp(input, "QUIT") == 0) {running = false;} 
		else if (strcmp(input, "ADD") == 0) {addMedia(mediaVect);} 
		else if (strcmp(input, "SEARCH") == 0) {printMedia(mediaVect);}
		else if (strcmp(input, "DELETE") == 0) {deleteMedia(mediaVect);}
		else if (strcmp(input, "HELP") == 0) {showHelp();}
		else {cout << "Command not recognized, use 'HELP' for a list of commands" << endl;}
	}

	clearVars(mediaVect);
	return 0;

}

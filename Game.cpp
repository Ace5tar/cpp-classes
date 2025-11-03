/*
 * Belle Biery
 * 11/3/25
 * Game media type class, inherits Media class
 */
#include <iostream>
#include "Game.h"

using namespace std;

// Default constructor
Game::Game():Media() {

	publisher = new char[80];
	rating = 0;

}

// Parameterized constuctor
Game::Game(char* setTitle, int setYear, char* setPublisher, float setRating):
	Media(setTitle, setYear),
	publisher(setPublisher),
	rating(setRating) {}

// Returns the publisher
char* Game::getPublisher() {
	return publisher;
}

// Returns the rating
float Game::getRating() {
	return rating;
}

// Prints all details about the game
void Game::printDetails() {
	cout    << "Title: " << title << endl
		<< "Year: " << year << endl
		<< "Publisher: " << publisher << endl
		<< "Rating: " << rating << endl;
} 

// Deconstructor
Game::~Game() {
	delete[] publisher;
	publisher = nullptr;
}

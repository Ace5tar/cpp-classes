#include <iostream>
#include "Game.h"

using namespace std;

Game::Game():Media() {

	publisher = new char[80];
	rating = 0;

}

Game::Game(char* setTitle, int setYear, char* setPublisher, float setRating):Media(title, year) {

	publisher = setPublisher;
	rating = setRating;

}

char* Game::getPublisher() {
	return publisher;
}

float Game::getRating() {
	return rating;
}

void Game::printDetails() {

	cout    << "Title: " << title << endl
		<< "Year: " << year << endl
		<< "Publisher: " << publisher << endl
		<< "Rating: " << rating << endl;
} 

Game::~Game() {
	delete[] publisher;
	publisher = nullptr;
}

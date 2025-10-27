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

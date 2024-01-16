#include "Game.h"
#include "Console.h"
#include<iostream>

using namespace std;

Game::Game() : Console() {
	title = "";
	developer = "";
	genre = "";
	date = 1972; // Year first video game was created
	price = 0.00;
}

Game::Game(string consoleName, string gameTitle, string gameDev, 
	string gameGenre, int gameYear, double gamePrice) : title(gameTitle), developer(gameDev), genre(gameGenre), 
	date(gameYear), price(gamePrice), Console(consoleName) {
	
	title = gameTitle;
	developer = gameDev;
	genre = gameGenre;
	date = gameYear;
	price = gamePrice;
}

void Game::displayInfo() {
	cout << "\nGame Title: " << getTitle() << endl;
	Console::gameInfoDis();
	cout << "Game Developer: " << getDev() << endl;
	cout << "Game Genre: " << getGenre() << endl;
	cout << "Release Date: " << getDate() << endl;
	cout << "Game Price: $" << getPrice() << endl;
}

// Getters
string Game::getTitle(){
	return title;
}

string Game::getDev(){
	return developer;
}

string Game::getGenre() {
	return genre;
}

int Game::getDate() {
	return date;
}

double Game::getPrice() {
	return price;
}

// Setters
void Game::setTitle(string gameTitle){
	title = gameTitle;
}

void Game::setDev(string gameDev){
	developer = gameDev;
}

void Game::setGenre(string gameGenre) {
	genre = gameGenre;
}

void Game::setDate(int releaseDate) {
	date = releaseDate;
}

void Game::setPrice(double gamePrice) {
	price = gamePrice;
}
#include "Console.h"
#include<iostream>

using namespace std;

// Defualt constructor
Console::Console() {
	name = "";
	brand = OTHER;
	date = 1972; // Year first home console was created
}

Console::Console(string consoleName, Brand consoleBrand, int releaseDate) {
	name = consoleName;
	brand = consoleBrand;
	date = releaseDate;
}

Console::Console(string consoleName) {
	name = consoleName;
}

void Console::displayInfo() {
	cout << "\nConsole Information:" << endl;
	cout << "Console Name: " << getName() << endl;
	cout << "Console Release Date: " << getYear() << endl;
}

void Console::gameInfoDis() {
	cout << "Console: " << getName() << endl;
}

// Getters
string Console::getName(){
	return name;
}

Brand Console::getConsole(){
	return brand;
}

int Console::getYear(){
	return date;
}

// Setters
void Console::setName(string consoleName){
	name = consoleName;
}

void Console::setConsole(Brand consoleBrand){
	brand = consoleBrand;
}

void Console::setDate(int releaseDate){
	date = releaseDate;
}
#ifndef CONSOLE_H
#define CONSOLE_H

#include<iostream>
#include <string>

using namespace std;

// Enumeration
enum Brand { OTHER, Nintendo, Sony, Microsoft, PC };

class Console
{
private:
	string name;
	Brand brand;
	int date;

public:
	// Default constructor
	Console();

	Console(string consoleName, Brand consoleBrand, int releaseDate);
	
	Console(string consoleName);

	void displayInfo();
	void gameInfoDis();

	// Getters
	string getName();
	Brand getConsole();
	int getYear();

	// Setters
	void setName(string consoleName);
	void setConsole(Brand consoleBrand);
	void setDate(int releaseDate);
};
#endif

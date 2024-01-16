//Mark Middleton //
//CIS 1202 501 //
//December 2, 2022 //
// Final Project: 
// Video Game and Console Inventory System

#include "Console.h" //
#include "Game.h" //

#include <iostream> //
#include <string> //
#include <cmath> //
#include <fstream>//

using namespace std; //

// Prototype functions
int menu(); //
string consoleSelect(int); //

// Main fucntion
int main() { // 
	// Class arrays to hold the collection, along w/ array size
	const int SIZE = 5; //
	Console consoles[SIZE]; //
	Game games[SIZE]; //

	// Creating and opening binary file to write data to
	fstream inventory;
	inventory.open("ConsoleAndGameInfo.txt", ios::out | ios::binary);

	// Various variables for the program
	int conNum = 0, gameNum = 0; //
	string conName = "", gameName = "", gameGen = "", Dev = ""; // 
	int temp = 0, gameYear = 0; //
	double gamePrice = 0.00, totalYear = 0.0, avgYear = 0.0, avgAge = 0.0, totalPrice = 0.0,
		avgPrice = 0.0, avgRunTime = 0.0, avgGameYear = 0.0, avgGameAge = 0.0;

	// Main menu loop
	int choice = 0; //
	while (choice != 7) //
	{
		choice = menu(); //

		switch (choice) //
		{
		case 1: //
			// User emumerator selection for the brand/manufacturer of video game system

			cout << " 0 Other / 1 Nintendo / 2 Sony / 3 Microsoft / 4 PC\nEnter console brand: "; //
			cin >> temp; //

			if (temp <= 0 || temp >= 4) { //
				cout << "Invalid Selction: Enter a 0 - 4: "; //
				cin >> temp; //
			} //

			consoles[conNum].setConsole(static_cast<Brand>(temp)); //

			cout << "Enter A Console Name: "; //
			cin.ignore(100, '\n');
			getline(cin, conName);//
			consoles[conNum].setName(conName); //

			cout << "Enter the release date: "; //
			cin >> temp; //
			
			consoles[conNum].setDate(temp); //

			conNum++; //
			

			cout << endl; //

			break;
		case 2:
			// User input for the Game class
			cout << "Enter Game Name: "; //
			cin.ignore(100, '\n');
			getline(cin, gameName); //
			games[gameNum].setTitle(gameName); //

			cout << "Enter Console Platform: "; //
			getline(cin, conName); //
			games[gameNum].setTitle(conName); //

			cout << "Enter Game Genre: "; //
			getline(cin, gameGen); //
			games[gameNum].setGenre(gameGen); //
			
			cout << "Enter Release Date: "; //
			cin >> gameYear; //
			games[gameNum].setDate(gameYear); //

			cout << "Enter Development Studio: "; //
			cin.ignore(100, '\n');
			getline(cin, Dev); //
			games[gameNum].setDev(Dev); //

			cout << "Enter Game Price: "; //
			cin >> gamePrice; //
			games[gameNum].setPrice(gamePrice); //

			games[gameNum] = Game(conName, gameName, Dev, gameGen, gameYear, gamePrice);

			gameNum++; //

			break;
		case 3:
			// Loops through the Console class and diplays data
			for (int i = 0; i < conNum; i++) //
			{
				consoles[i].displayInfo(); //
				cout << "Console Brand: " << consoleSelect(consoles[i].getConsole()) << endl;
			}
			break; //
		case 4: //
			// Loops through the Game class and diplays data
			for (int j = 0; j < gameNum; j++) //
			{ //
				games[j].displayInfo();
			} //
			break; //
		case 5:
			// Finds the average age of consoles
			
			for (int k = 0; k < conNum; k++)
			{
				totalYear += consoles[k].getYear();
				avgYear = totalYear / conNum;
				avgAge = 2022 - avgYear;
			}
			cout << "\nThe average age of your consoles is " << avgAge << endl;
			
			// Finds the average price and age of games
			for (int l = 0; l < gameNum; l++)
			{
				totalPrice += games[l].getPrice();
				avgPrice = totalPrice / gameNum;
				avgGameYear += games[l].getDate();
				avgGameAge = 2022 - (avgGameYear / gameNum);
			}
			cout << "Average Game Price: $" << avgPrice << endl;
			cout << "The average age of your games is " << avgGameAge << endl;
			break;
		case 6: 
			
			// Write console data to the file
			for (int m = 0; m < SIZE; m++) {
				inventory << "\nConsole #" << (m + 1) << "\n\n"; //
				inventory << "Console Brand: " << consoles[m].getConsole() << endl; //
				inventory << "Console Name: " << consoles[m].getName() << endl; //
				inventory << "Release date: " << consoles[m].getYear() << endl;
			}

			// Writes game data to the fill
			for (int n = 0; n < SIZE; n++) {
				inventory << "\nGame #" << (n + 1) << "\n\n"; //
				inventory << "Game title: " << games[n].getTitle() << endl; //
				inventory << "Developer: " << games[n].getDev() << endl; //
				inventory << "Genre: " << games[n].getGenre() << endl; //
				inventory << "Release Date: " << games[n].getDate() << endl; //
				inventory << "Price: $" << games[n].getPrice() << endl; //
			break;
			}
		}
	}

	// Close the file
	inventory.close();


	// Exits program
	return 0;
}

// Main menu fucntion
int menu()
{
	int choice = 0;

	// Prints the menu
	cout << "\nVideo Game Inventory System\n" << endl;
	cout << "\t1. Enter A Console\n";
	cout << "\t2. Enter A Game\n";
	cout << "\t3. Display Consoles\n";
	cout << "\t4. Display Game Library\n";
	cout << "\t5. Display Statisics\n";
	cout << "\t6. Write to File\n";
	cout << "\t7. Exit The Program\n\n";

	// Gets the user selection
	cout << "Enter Your Selection: ";
	cin >> choice;

	// Input validation
	if (choice < 1 || choice > 7)
	{
		cout << "\nEnter a number 1-7: ";
		cin >> choice;
	}

	return choice;
}

// Translates the enum to a string
string consoleSelect(int brandName) {
	string brand;

	switch (brandName) {
	case 0: brand = "Other";
		break;
	case 1: brand = "Nintendo";
		break;
	case 2: brand = "Sony";
		break;
	case 3: brand = "Microsoft";
		break;
	case 4: brand = "PC";
		break;
	}

	return brand;
}
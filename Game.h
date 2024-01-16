#ifndef GAME_H
#define GAME_H
#include "Console.h"

#include<iostream>
#include<string>

class Game : public Console
{

private:
    string title;
    string developer;
    string genre;
    int date;
    double price;

public:
    // Default constructor
    Game();

    Game(string consoleName, string gameTitle, string gameDev, string gameGenre, int gameYear, double gamePrice);

    void displayInfo();

    // Getters
    string getTitle();
    string getDev();
    string getGenre();
    int getDate();
    double getPrice();

    // Setters
    void setTitle(string);
    void setDev(string);
    void setGenre(string);
    void setDate(int);
    void setPrice(double);
};
#endif
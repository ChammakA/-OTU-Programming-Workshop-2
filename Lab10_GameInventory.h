#pragma once
#include <iostream>
#include <vector>

//header file for the GameInventory

class GameInventory // creating the class GameInventory and initializing the private/public values as well as the functions 
                    // that will be used in the .cpp file.
{
    private:
        std::string name;
        std::string brand;
        int year;
        double price;
    public:
        GameInventory();
        GameInventory(std::string name, std::string brand, int year, double price);
        std::string getName();
        std::string getBrand();
        int getYear();
        double getPrice();
        void displayGame();
        bool isSimilar(const GameInventory& game);

};

// initializing the global variables
bool searchInventory(std::vector<GameInventory>& v, GameInventory& game);
void displayInventory(std::vector<GameInventory>& v);
bool addNewGame(std::vector<GameInventory>& v, GameInventory& game);



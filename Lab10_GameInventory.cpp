#include "Lab10_GameInventory.h" 
//cpp file that calls from the header file

GameInventory::GameInventory() //default constructor that initializes the basic values.
{
    name = "";
    brand = "";
    year = 0;
    price = 0.0;
};

GameInventory::GameInventory(std::string name, std::string brand, int year, double price) //parameterized constructor
                                                                                        // that sets the values as per the parameters
{
    this->name = name;
    this->brand = brand;
    this->year = year;
    this->price = price;
};

std::string GameInventory::getName() //function to return the "name"  from object
{
    return this->name;
};

std::string GameInventory::getBrand() // function to return the "brand" from object
{
    return this->brand;
};
int GameInventory::getYear() //function to return the "year" from object
{
    return this->year;
};
double GameInventory::getPrice() //function to return the "price" from object
{
    return this->price;
};

void GameInventory::displayGame() // function that will output the name, brand, year, and price of the games as desired
{
    std::cout << "Name: " << this->name << ", Brand: " << this->brand << ", Year: " << this->year << ", Price: " << this->price << std::endl;
};
bool GameInventory::isSimilar(const GameInventory& game) //function that will check if the object (game) in the vector, is the same as
                                                         // as the "game" being sent. If so, return true. Else, false.
{   
    if (this->name == game.name && this->brand == game.brand && this->year == game.year && this->price == game.price)
    {
        return true;
    }
    return false;
};

bool searchInventory(std::vector<GameInventory>& v, GameInventory& game) // function that will iterate through each item in the vector
                                                                         // and then pass those values to the isSimilar function
                                                                         // along with the "game" vector to see if they are the same
                                                                         // and return that result
{
    for (int i = 0; i < v.size(); i++)
    {
        return (v[i].isSimilar(game));
    }

};

void displayInventory(std::vector<GameInventory>& v) // function that will iterate through the vector and output all the contents
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i].displayGame();
    }
};

bool addNewGame(std::vector<GameInventory>& v, GameInventory& game) // this function will check to see if the "game" already
                                                                    // exists in the vector and if it doesn't it will add the
                                                                    // new game to the list and return true.
                                                                    // However, if it does, it will return false
                                                                    
{    
    try 
    {
        if(!searchInventory(v, game))
        {
            v.push_back(game);
            return true;
        }
        else
        {
            throw 1001; // if false, will throw this "error"
        }
    }
    catch(int ex) // catches the "error" and will perfrom this command if caught
    {
        return false;
    }  
};



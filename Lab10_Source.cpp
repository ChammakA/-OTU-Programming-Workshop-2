#include "Lab10_GameInventory.h"
 
/**
 * @Sammak Ahmed - 100747439
 * Lab 10 - Modular Programming
 * This program will create a vector object of class GameINventory and then display the current games in that vector. It will
 * then attempt to add 2 new games into the list if they don't already exist. The first attempts will be successful while the
 * second will not 
 * 
 * @return int 
 */
int main()
{
    //Set of existing games
    std::vector<GameInventory> games = {
        {"Need For Speed", "Xbox", 2018, 45.0},
        {"Hitman 2", "Playstation", 2020, 75.5},
        {"Mario Brothers", "Nintendo", 2010, 30.0},
        {"Assassin's Creed", "Playstation", 2021, 70.5},
        {"Uncharted 4: A Thief's End", "Playstation", 2020, 85.0},
        {"Spiderman Miles Morales", "Xbox", 2021, 65.5},
        {"Resident Evil", "Xbox", 2018, 45.0},
    };

    //Displaying current games in the Inventory
    std::cout << "Current Games in the Inventory" << std::endl;
    std::cout << "*****************************" << std::endl;
    displayInventory(games);

    //Adding a new game
    GameInventory game = GameInventory("Hitman 3", "Playstation", 2022, 95);
    std::cout << "\nAdding another game in the Inventory..." << std::endl;

    //Checks to see if this game already exists in the collection
    if (searchInventory(games, game))
    {
        std::cout << "\nFollowing Game already exists in the Inventory..." << std::endl;
        game.displayGame();
    }
    else
    {
        if(addNewGame(games, game))
        {
            std::cout << "\nFollowing Game added to the Inventory successfully.. " << std::endl;
            game.displayGame();
            std::cout << std::endl;

        }
    }

    //Displaying curret Games in the Inventory
    std::cout << "Current Games in the Inventory" << std::endl;
    std::cout << "******************************" << std::endl;
    displayInventory(games);

    //Adding another new game which already exists in the inventory
    game = GameInventory("Need For Speed", "Xbox", 2018, 45.0);
    std::cout << "\nAdding another game in the Inventory..." << std::endl;

    //Checks to see if this game already exists in the collection
    if (searchInventory(games, game))
    {
        std::cout << "\nFollowing Game already exists in the Inventory..." << std::endl;
        game.displayGame();
        std::cout << std::endl;
    }
    else
    {
        if(addNewGame(games, game))
        {
            std::cout << "\nFollowing Game added to the inventory successfully..." << std::endl;
            game.displayGame();
            std::cout << std::endl;
        }
    }

    //Displaying current Games in the Inventory
    std::cout << "Current Games in the Inventory" << std::endl;
    std::cout << "*******************************" << std::endl;
    displayInventory(games);

    return 0;
}
#include <SFML/Graphics.hpp>
#include "Class.hpp"
#include "Game.hpp"
#include "Treat.hpp"

int main()
{
    //Random number generator
    srand(time(NULL));
    //Create a game object of type Game
    Game game;
    //Run the game
    game.run();
    

    return 0;
}

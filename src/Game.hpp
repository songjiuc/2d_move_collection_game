//  Game.hpp
//  Created by Jo Song & Lauryn C. Hansen on 9/21/22.

#ifndef Game_hpp
#define Game_hpp
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Class.hpp"
#include "Treat.hpp"

//Create a Game class
class Game{
public:
    //Game constructor
    Game();
    void run();
    
private:
    //Declare variables associated with game window & objects
    const std::string gameName = "Marlene the Cat";
    static const int gameWidth = 1280;
    static const int gameHeight =720;
    int screenWidth = 1280;
    int screenHeight =720;
    double aspectRatio = (float)gameWidth/(float)screenWidth;
    
    //sf(view class reference in SFML)
    sf::RenderWindow window;
    sf::Event event1;
    sf::Texture texture_background;
    sf::Sprite sprite_background;
    sf::Texture texture_gameover;
    sf::Sprite sprite_gameover;
    //Declare variable named marlene of type Cat
    Cat marlene;
    //Declare of variable named treat of type Treat
    Treat treat;
    //Create a vector named treats of type Treat(we need many treats to fall in game window)
    std::vector<Treat> treats;
    sf::Time timetoSpawn;
    sf::Sound sound;
    sf::SoundBuffer buffer;
    sf::Text text;
    sf::Text timer;
    sf::Font font;
    sf::Music music;
    sf::Clock clock;
    sf::Time timetoplay;
    sf::RenderWindow window_gameover;
    
    //Game methods
    int loadBackground();
    void update();
    void spawnTreats();
    void handleCollisions();
    void loadSound();
    void setText();
    void setTime();
    void handleTimer();
    void drawSprites();
    void gameOver();
};

#endif /* Game_hpp */

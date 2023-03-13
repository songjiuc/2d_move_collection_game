//  Class.hpp
//
//  Created by Jo Song & Lauryn C. Hansen on 9/19/22.

#ifndef Class_hpp
#define Class_hpp
#include <SFML/Graphics.hpp>

//Create a Cat class
class Cat{
private:
    //Initialize a texture and sprite to be used for cat object
    sf::Texture texture;
    sf::Sprite sprite;
    //Initialize variables for x,y coordinate for cat sprite position in game window
    int x = 550;
    int y = 500;
    //Initialize variable that will be used to determine when treat sprites exit game window
    bool onScreen = false;
    int points = 0;
    
public:
    //Cat constructor
    Cat();
    //Method to create a cat sprite
    const sf::Sprite getSprite();
    //Method to move cat sprite in game window
    void move(const sf::RenderWindow& window);
    //Method to draw cat sprite in game window
    void drawsprite(sf::RenderWindow& window);
    //Method to get current points
    int getPoints();
    //Method to add points when cat eats treat
    void setPoints();
};

#endif /* Class_hpp */

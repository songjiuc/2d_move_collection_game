//  Treat.hpp
//
//  Created by Jo Song & Lauryn C. Hansen on 9/21/22.

#ifndef Treat_hpp
#define Treat_hpp
#include <SFML/Graphics.hpp>
#include <vector>

//Create a treat class
class Treat{
private:
    //Initialize a texture and sprite to be used for treat object
    sf::Texture texture;
    sf::Sprite sprite;
    
public:
    //Treat constructor
    Treat();
    //Method to create a treat sprite
    const sf::Sprite getSprite();
    //Method to set position of treat sprite
    void setPosition(int x, int y);
    //Method to move treat sprite in game window
    void move();
    //Method to determine if a treat sprite has gone out of game window
    bool shouldDestroy(const sf::RenderWindow& window)const;
    //Method to draw treat sprite
    void drawsprite(sf::RenderWindow& window);
};

#endif /* Treat_hpp */

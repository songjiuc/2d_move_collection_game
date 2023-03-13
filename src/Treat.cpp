//  Treat.cpp
//
//  Created by Jo Song & Lauryn C. Hansen on 9/21/22.

#include "Treat.hpp"
#include <iostream>

//Treat constructor
Treat::Treat(){
    //Create a treat texture - jpeg needs to be in terminal build folder to properly load.
    //If the jpeg doesn't load, print out an error.
    if (!texture.loadFromFile("treat.PNG")) {
        std::cout << "treat.PNG not properly loading.\n";
    }
    //Create a treat sprite
    sprite.setTexture(texture);
    //Set the scale of the sprite (numbers > 1 make sprite bigger, numbers < 1 make sprite smaller)
    sprite.setScale(0.6f,0.6f);
}

//Get method which returns a treat sprite
//Const because we always want to create the same treat sprite
const sf::Sprite Treat::getSprite(){
    return sprite;
}
//Method to set the position of a sprite
void Treat::setPosition(int x, int y){
    sprite.setPosition(x,y);
}
//Method to move an object of type Treat only in the y direction(vertical falling treats from the sky)
void Treat::move(){
    sprite.move(0.f,10.f);
}
//Method that determines when treat objects go out of the game window
bool Treat::shouldDestroy(const sf::RenderWindow& window)const{
    auto position = sprite.getPosition();
    return position.x<0 || position.x > window.getSize().x || position.y <0 || position.y > window.getSize().y;
}
//Method to draw treat sprite objects in the game window
void Treat::drawsprite(sf::RenderWindow& window){
    window.draw(sprite);
}

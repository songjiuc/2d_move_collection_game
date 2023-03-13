//  Class.cpp
//  Created by Jo Song & Lauryn C. Hansen on 9/19/22.
//
#include "Class.hpp"
#include <iostream>

//Cat constructor
Cat::Cat(){
    //Create a cat texture - jpeg needs to be in terminal build folder to properly load.
    //If the jpeg doesn't load, print out an error.
    if(!texture.loadFromFile("cat.PNG")){
        std::cout << "cat.PNG not properly loading.\n";
    }
    sprite.setTexture(texture);
    //Set the scale of the sprite (numbers > 1 make sprite bigger, numbers < 1 make sprite smaller)
    sprite.setScale(0.5f,0.5f);
    //Set the starting position of sprite
    sprite.setPosition(x,y);
}

//Method to get cat sprite
const sf::Sprite Cat::getSprite(){
    return sprite; // get sprite which is private
}

//const int Cat::getX(){
//    return x;
//}
//
//const int Cat::getY(){
//    return y;
//}


//Method to move the cat sprite in game window
void Cat::move(const sf::RenderWindow& window){
    //If user presses left key, move the cat in the negative x direction
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        sprite.move(-20.f,0);
    }
    //If user presses right key, move the cat in the positive x direction
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        sprite.move(20.f,0);
    }
    auto pos = sprite.getPosition();
    
    //Check if the cat sprite is within the game window
    if (pos.x > 0 && pos.x < window.getSize().x){
        onScreen = true;
    }
    //If the cat sprite moves out of game window, send cat back into window
    //from positive or negative x direction
    if (onScreen){
        while(pos.x<0){
            pos.x += window.getSize().x;
        }
        while(pos.x >window.getSize().x){
            pos.x -=window.getSize().x;
        }
        sprite.setPosition(pos);
    }
}
//Method to draw cat sprite in the game window
void Cat::drawsprite(sf::RenderWindow& window){
    window.draw(sprite);
}

//Method to get current points
int Cat::getPoints(){
    return points;
}

//Method to add points when cat eats treat
void Cat::setPoints(){
    points ++;
}


//  Game.cpp

//  Created by Jo Song & Lauryn C. Hansen on 9/21/22.

#include "Game.hpp"

//Create a game session
Game::Game():window(sf::VideoMode(gameWidth,gameHeight),"")
{
    //Set game window screen size
    screenWidth = sf::VideoMode::getDesktopMode().width;
    screenHeight = sf::VideoMode::getDesktopMode().height;
    
    //Set game window name
    window.setTitle(gameName);
    window.setFramerateLimit(60);
    
    //Resize all objects if window is resized
    sf::View view1(sf::FloatRect(0.f,0.f,(float)gameWidth,(float)gameHeight));
    aspectRatio = (float)gameWidth/(float)screenWidth;
    
    window.setView(view1);
}
//Run a game session
void Game::run(){
    loadBackground(); // background
    loadSound(); // sound
    setText(); // text
    //sf::Music music; // music
//    music.openFromFile("music.wav");
//    music.setLoop(true);
//    music.setVolume(20.f);
    music.play();
    //setTime();
    while(window.isOpen()){
        while(window.pollEvent(event1)){

            if (event1.type == sf::Event::Closed){
                window.close();
            }
        }
        while(window_gameover.isOpen()==false){
            update();
        }
        
        //setTime();
        
        //update();
        
        //drawSprites();
        
//        while(window_gameover.isOpen()){
//            update();
//            gameOver();
//        }

    }
}
//Create a game window background sprite
int Game::loadBackground(){
    // load textures
    texture_background.loadFromFile("background.jpg");
    
    // load sprites
    sprite_background.setTexture(texture_background);
    
    // load gameover button
    texture_gameover.loadFromFile("gameover.png");
    sprite_gameover.setTexture(texture_gameover);
    
    return 0;
}
//Updates to game session
void Game::update(){
    window.clear();
    
    setTime();
    
    marlene.move(window); // move cat
    
    //Move treat sprites
    for (auto& treat: treats){
        treat.move();
    }
    
    //Erase treat sprites that go out of game window
    treats.erase(
        std::remove_if(treats.begin(),treats.end(),[this](const Treat& b)
                       {return b.shouldDestroy(window);}),
                 treats.end());
    
    //Collision(cat & treat) and erase
    handleCollisions();
    
    spawnTreats();
    
    
    handleTimer();
    
    window.draw(sprite_background);
    
    //Draw treat sprites
    for (auto& treat: treats){
        treat.drawsprite(window);
    }
    
    //Draw cat sprite
    marlene.drawsprite(window);
    window.draw(text);
    window.draw(timer);
    
    //Display all sprites in game window
    window.display();
    
}
//Method to distribute(spawn) treats during game session
void Game::spawnTreats(){
    //Set treat sprite position
    treat.setPosition(rand()%int(screenWidth - treat.getSprite().getGlobalBounds().width),treat.getSprite().getGlobalBounds().height);
    //Spawn treat sprites
    const float secBetweenSpawn = 0.1;
    if(clock.getElapsedTime()>=timetoSpawn){
        treats.push_back(treat);
        timetoSpawn = sf::seconds(secBetweenSpawn);
        clock.restart();
    }
}

//Collision and Erasure of sprites, add points, play collision sound
void Game::handleCollisions(){
    for(size_t i = 0; i < treats.size(); i++){
        if(marlene.getSprite().getGlobalBounds().intersects(treats [i].getSprite().getGlobalBounds())==true){
            treats.erase(treats.begin()+i);
            marlene.setPoints();
            text.setString("Points: " + std::to_string(marlene.getPoints()));
            sound.play();
        }
    }
}

//Load meow sound
void Game::loadSound(){
    buffer.loadFromFile("meow.wav");
    sound.setBuffer(buffer);
    sound.setPitch(1.2f);
    music.openFromFile("music.wav");
    music.setLoop(true);
    music.setVolume(20.f);
}

//Load font and set text
void Game::setText(){
    font.loadFromFile("example_font.ttf");
    text.setString("Points: 0");
    text.setFont(font);
    text.setPosition(500.f,20.f);
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    timer.setString("Time: 30");
    timer.setFont(font);
    timer.setPosition(50.f,20.f);
    timer.setCharacterSize(100);
    timer.setFillColor(sf::Color::Black);
    timer.setStyle(sf::Text::Bold);
}

void Game::setTime(){
    timetoplay = sf::seconds(30);
}

void Game::handleTimer(){
    while (clock.getElapsedTime()!=sf::seconds(30)){
        timetoplay = timetoplay - sf::seconds(1);
        timer.setString("Time: " + std::to_string(timetoplay.asSeconds()));
    }
//    if (timetoplay == sf::seconds(0)){
//        //Set game window name
//        window_gameover.setTitle("Game Over!");
//        window_gameover.setFramerateLimit(60);
//        window_gameover.draw(sprite_gameover);
        //gameOver();
//}
}

void Game::drawSprites(){
    //Draw game window background
    window.draw(sprite_background);
    
    //Draw treat sprites
    for (auto& treat: treats){
        treat.drawsprite(window);
    }
    
    //Draw cat sprite
    marlene.drawsprite(window);
    window.draw(text);
    window.draw(timer);
    
    //Display all sprites in game window
    window.display();
}

void Game::gameOver(){
    if (timetoplay == sf::seconds(0)){
        //Set game window name
        window_gameover.setTitle("Game Over!");
        window_gameover.setFramerateLimit(60);
        window_gameover.draw(sprite_gameover);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        clock.restart();
        timetoplay = sf::seconds(30);
    }
}

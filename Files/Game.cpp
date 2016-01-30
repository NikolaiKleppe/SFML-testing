#include "const.h"
#include "Game.h"
#include "Player.h"
#include "gravity.h"
#include "Monster.h"
#include "Collide.h"
#include "Bullet.h"
#include <iostream>
#include <sstream>      // std::stringstream
#include "AnimatedSprite.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

extern Player  *player;
extern Gravity *gv;
extern Monster *monster;
extern Collide *collide;
extern Bullet  *bullet;


Game::Game() {
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Green dot vs The World");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(FPS);
    loadTextures();


	player  = new Player();
    gv      = new Gravity();
    monster = new Monster(0, false);
    collide = new Collide();

    currentAnimation = player->getDown();       
    animatedSprite = player->getPlayerAnim();
}

void Game::loadTextures() {
    ground.loadFromFile("../../files/texture/level/ground.png");
    block.loadFromFile("../../files/texture/level/block.png");

    player           = new Player();
    gv               = new Gravity();
    monster          = new Monster(0, false);
    collide          = new Collide();
    bullet           = new Bullet();

    currentAnimation = player->getDown();
    animatedSprite   = player->getPlayerAnim();


}

void Game::runWindow() {   
   // level = new Level();

    while (window.isOpen()) {   

        /*Make the game run at 60fps*/
        const int frameTime = 1000000 / FPS;
        sf::Clock c;
        sf::Time t = c.getElapsedTime();
        sf::Int64 nextFrameTime = t.asMicroseconds() + frameTime;

        int loops = 0;
        while (t.asMicroseconds() < nextFrameTime && loops < FRAMESKIP)  {
        
            updateTime = updateClock.restart().asMilliseconds();
            userInput();
            drawGameLevel();
            drawPlayer();
            drawPlayerShadow();
            monster->drawMonsters();
//          bullet->makeBullet();
            t = c.getElapsedTime();
            loops++;

        }
        window.display();
    }   
}



void Game::drawRectangle(sf::RectangleShape name, float r_width, float r_height, float x, float y) {
    name.setSize(sf::Vector2f(r_width, r_height));
    name.setPosition(x, y);
    draw(name);
    collide->playerCollide(name);
}




void Game::drawGameLevel() {
    window.clear();

    drawTextures(blocks, 100, ground);
    drawTextures(borders, 100, block);

    //                            w        h        x        y
    drawRectangle(borders[1],     15,     200,    -200,     20);
    drawRectangle(borders[2],   2250,      15,    -200,    470);
    drawRectangle(borders[3],    450,      15,    -200,     20);
    drawRectangle(blocks[1],      80,      50,     100,    420);
    drawRectangle(blocks[2],      80,      80,    -100,    370);
    drawRectangle(blocks[3],      80,      50,      70,    280);
    drawRectangle(blocks[4],      80,      50,     -80,    160);
    drawRectangle(blocks[5],      80,      50,     160,    100);

    drawView();
}


void Game::drawTextures(std::vector<sf::RectangleShape> &shape, int size, sf::Texture &text) {
    shape.resize(size);
    for (auto i = shape.begin(); i != shape.end(); i++) {
        i->setTexture(&text);
    }
}


void Game::drawView() {
    sf::View view(sf::FloatRect(200, 200, 300, 200));
    sf::RectangleShape pp = player->getPlayerShadow();
    sf::Vector2f player_pos = pp.getPosition();

    view.setSize(1200, 800);
    view.setViewport(sf::FloatRect(0, 0, 1, 1));
    view.setCenter(260, 250);
    
    /* Player moves out of screen region, move the view*/

    /* Exits right border*/
    if (player_pos.x >= 830) {
        view.move(1190, 0);
    }

    
    window.setView(view);
}



void Game::draw(sf::RectangleShape sprite) {
    window.draw(sprite);
}

void Game::draw(sf::Sprite sprite) {
    window.draw(sprite);
}

void Game::draw(AnimatedSprite sprite) {
    window.draw(sprite);
}

void Game::userInput() {    
    

    while (window.pollEvent(event)) {
        if ((event.type == sf::Event::Closed) ||
           ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::D)))
           window.close();
    }


    vel = gv->updateVelocity();
    //vel = player->getPlayerSpeed();
    frameTime = frameClock.restart();
    

    movePlayer(0.0, vel.y);                         //Up-Down
    movePlayer(vel.x, 0.0);                         //Left-Right
    
    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

        currentAnimation = player->getUp();
        vel = gv->isOnGround();
        noKeyWasPressed = false;
    }
    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        currentAnimation = player->getLeft();
        vel = gv->movingLeft();
        noKeyWasPressed = false;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        currentAnimation = player->getRight();
        vel = gv->movingRight();
        noKeyWasPressed = false;
    }

    else                                            //No button press, de-accelerate player
        vel = gv->deAccelerate();
        gv->limitAcceleration();

           


    //Firing
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            fireBullet();
        }




    
    if (noKeyWasPressed)
    {
        animatedSprite.stop();
    }
    noKeyWasPressed = true;

        
    
        
     
    /* Debug: show coodinate*/
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        player->showCoord();
    //  gv->printVelocity();
    }

    
}




void Game::movePlayer(float x, float y) {
    animatedSprite.move(x,  y);     
    player->moveShadow(x, y);
}




void Game::setPlayerPos(float x, float y) {
    player->setPlayerPos(x, y);
}

void Game::drawPlayer() {
    animatedSprite.play(*currentAnimation);
    window.draw(animatedSprite);
    animatedSprite.update(frameTime);
}


void Game::drawPlayerShadow() {                             
    draw(player->getPlayerShadow());
}

AnimatedSprite Game::getAnim() {
    return animatedSprite;
}

void Game::fireBullet() {
    
    bullet->fireBullet();

}
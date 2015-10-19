#include "const.h"
#include "Game.h"
#include "Player.h"
#include "gravity.h"
#include "Monster.h"
#include "Collide.h"
#include "Bullet.h"
#include "level.h"
#include <iostream>
#include <sstream>   // std::stringstream
#include "AnimatedSprite.hpp"
#include <SFML/Graphics.hpp>

extern Player        *player;
extern Gravity       *gv;
extern Monster       *monster;
extern Collide       *collide;
extern Bullet        *bullet;
extern Level         *level;

Game::Game() {
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Green dot vs The World");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(FPS);

    player           = new Player();
    gv               = new Gravity(0, 0.4F, 0.0008F, -0.05F, -0.8F, -0.1F, sf::Vector2f(0.0F, 0.0F), sf::Vector2f(0.F, 0.003F), 10, false, false, 5.0F);
    monster          = new Monster(0, false);
    collide          = new Collide();
    level            = new Level();
    bullet           = new Bullet();

    currentAnimation = player->getDown();       
    animatedSprite   = player->getPlayerAnim();
}

void Game::runWindow() {    
    while (window.isOpen()) {   

        /*Make the game run at 60fps*/     
        time = clock.getElapsedTime();
        nextFrameTime = time.asMicroseconds() + FRAMETIME;

        int loops = 0;
        while (time.asMicroseconds() < nextFrameTime && loops < FRAMESKIP)  {
            window.clear();
            updateTime = updateClock.restart().asMilliseconds();

            userInput();
            level->drawGameLevel();
            drawPlayer();
            drawPlayerShadow();
            monster->drawMonsters();

            time = clock.getElapsedTime();
            loops++;
        }
        window.display();
        window.setView(level->drawView());
    }   
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
           
    if (noKeyWasPressed)
    {
        animatedSprite.stop();
    }
    noKeyWasPressed = true;


    //Firing
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        bullet->fireBullet();
    }


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
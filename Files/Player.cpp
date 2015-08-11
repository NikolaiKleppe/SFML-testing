#include "const.h"
#include "Player.h"
#include "Game.h"
#include "gravity.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"

extern Game *game;
extern Gravity *gv;

Player::Player() {
    loadTextures();
    setupAnim();

    playerShadow = sf::RectangleShape(sf::Vector2f(20, 30));
    playerShadow.setOrigin(20, 30);      //Apparently this one is super important for the collision detection >.<
    playerShadow.setPosition(sf::Vector2f(276, 290));
    playerShadow.setTexture(&shadowTexture);

    mainPlayer.setLooped(false);
    mainPlayer.isPlaying();
    mainPlayer.setPosition(sf::Vector2f(250, 260));

    playerSpeed = 0.4F;                  //Default player speed

}

void Player::loadTextures() {
    texture.loadFromFile("../../files/texture/player/player.png");

    shadowImage.loadFromFile("../../files/texture/player/playerShadow.png");
    shadowImage.createMaskFromColor(sf::Color::White);

    shadowTexture.loadFromImage(shadowImage);
    
}




void Player::movePlayer(float x, float y) { 
    mainPlayer.move(x, y);
}

void Player::moveShadow(float x, float y) {         
    playerShadow.move(x, y);
}


void Player::setPlayerPos(float x, float y) {
    mainPlayer.setPosition(x, y);
}



float Player::getPlayerSpeed() {
    return playerSpeed;
}



sf::RectangleShape Player::getPlayerShadow() {
    return playerShadow;
}

AnimatedSprite Player::getPlayerAnim() {
    return mainPlayer;
}

Animation * Player::getDown() {
    return &walkingAnimationDown;
}

Animation * Player::getLeft() {
    return &walkingAnimationLeft;
}

Animation * Player::getRight() {
    return &walkingAnimationRight;
}

Animation * Player::getUp() {
    return &walkingAnimationUp;
}





void Player::setupAnim() {
        // set up the animations for all four directions (set spritesheet and push frames)

        walkingAnimationDown.setSpriteSheet(texture);
        walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
        walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
        walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
        walkingAnimationDown.addFrame(sf::IntRect(0, 0, 32, 32));


        walkingAnimationLeft.setSpriteSheet(texture);
        walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
        walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
        walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
        walkingAnimationLeft.addFrame(sf::IntRect(0, 32, 32, 32));

        walkingAnimationRight.setSpriteSheet(texture);
        walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
        walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
        walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
        walkingAnimationRight.addFrame(sf::IntRect(0, 64, 32, 32));

        walkingAnimationUp.setSpriteSheet(texture);
        walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
        walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
        walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
        walkingAnimationUp.addFrame(sf::IntRect(0, 96, 32, 32));
    }



/*Debugging function*/
void Player::showCoord() {
    /*std::cout << "Current X-Position:  " << mainPlayer.getPosition().x << "\n";
    std::cout << "Current Y-Position:  " << mainPlayer.getPosition().y << "\n\n";*/

    std::cout << "Current X-Position:  " << playerShadow.getPosition().x << "\n";
    std::cout << "Current Y-Position:  " << playerShadow.getPosition().y << "\n\n";
}
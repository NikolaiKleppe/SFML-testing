#include "const.h"
#include "Player.h"
#include "Game.h"
#include "gravity.h"
#include <iostream>
#include <SFML/Graphics.hpp>

extern Game *game;
extern Gravity *gv;

Player::Player() {
	std::cout << "\nPlayer constructor\n";
	mainPlayer = sf::RectangleShape(sf::Vector2f(50, 30));
	newPlayer();
	loadTextures();
}

void Player::loadTextures() {
	texture.loadFromFile("../../files/texture/snipar.jpg");
	mainPlayer.setTexture(&texture);
}


void Player::newPlayer() {
	mainPlayer.setOrigin(20, 30);
	mainPlayer.setPosition(260, 250);
	mainPlayer.setFillColor(sf::Color::Green);
}


sf::RectangleShape Player::getPlayer() {
	return mainPlayer;
}



void Player::movePlayer(float x, float y) {	
	mainPlayer.move(x, y);
}


void Player::setPlayerPos(float x, float y) {
	mainPlayer.setPosition(x, y);
}

/*Debugging function*/
void Player::showCoord() {
	std::cout << "Current X-Position:  " << mainPlayer.getPosition().x << "\n";
	std::cout << "Current Y-Position:  " << mainPlayer.getPosition().y << "\n\n";
}








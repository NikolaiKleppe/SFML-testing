#include "const.h"
#include "Player.h"
#include "Game.h"
#include "test.h"
#include <iostream>
#include <SFML/Graphics.hpp>

extern Game *game;

Player::Player() {
	std::cout << "\nPlayer constructor\n";
	mainPlayer = sf::RectangleShape(sf::Vector2f(50, 30));
	newPlayer();




}


void Player::newPlayer() {

	
	texture.loadFromFile("../../files/texture/snipar.jpg");

	mainPlayer.setTexture(&texture);


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
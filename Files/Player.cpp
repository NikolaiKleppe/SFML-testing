#include "const.h"
#include "Player.h"
#include "Game.h"
#include "test.h"
#include <iostream>
#include <SFML/Graphics.hpp>

extern Game *game;

Player::Player() {
	std::cout << "\nPlayer constructor\n";
	mainPlayer = sf::RectangleShape(sf::Vector2f(20, 30));
	newPlayer();
//	playerSpeed.x = 0.5F;		
//	playerSpeed.y = 0.5F;		


}


void Player::newPlayer() {
	mainPlayer.setOrigin(20, 30);
	mainPlayer.setPosition(260, 250);
	mainPlayer.setFillColor(sf::Color::Green);
}


sf::RectangleShape Player::getPlayer() {
	return mainPlayer;
}


/*	Improvement: use vectors to move the player instead of direct float values. */
void Player::movePlayer(float x, float y) {	
	mainPlayer.move(x, y);
//	showCoord(mainPlayer);	//For debugging. NB: Slows the whole game down by quite a lot. xD

}


/*Debugging function*/
void Player::showCoord(sf::RectangleShape player) {
	std::cout << "Current X-Position:  " << player.getPosition().x << "\n";
	std::cout << "Current Y-Position:  " << player.getPosition().y << "\n\n";
}
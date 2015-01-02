#include "const.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>



Player::Player() {

	mainPlayer = sf::RectangleShape(sf::Vector2f(20, 30));

}





void Player::newPlayer() {
	mainPlayer.setOrigin(20, 30);
	mainPlayer.setPosition(200, 400);
	mainPlayer.setFillColor(sf::Color::Red);
	std::cout << "Player is set up\n";
}



void Player::drawPlayer() {	
	//playerWindow.draw(mainPlayer);
	/*
	
	*/
}


sf::RectangleShape Player::getPlayer() {
	return mainPlayer;
}


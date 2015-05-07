#include "const.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

extern Player *player;															//Borrow data from player.cpp
sf::Font font;



Game::Game() {
	window.create(sf::VideoMode(WIDTH, HEIGHT), "Green dot vs The World");		//Initializes the video mode	
//	window.setFramerateLimit(60);
	font.loadFromFile("../arial.ttf");											//Load font for text use

}


void Game::runWindow() {			
	while (window.isOpen()) {	
		userInput();	
		drawGame();			
		drawPlayer();
		window.display();		
	}	
}


void Game::drawBorders() {

	/*4 borders*/
	sf::RectangleShape bottom(sf::Vector2f(WIDTH-2*BORDER, BORDER));
	bottom.setPosition(BORDER, HEIGHT-BORDER-50);
	bottom.setFillColor(sf::Color::Cyan);

	sf::RectangleShape top(sf::Vector2f(WIDTH-2*BORDER, BORDER));
	top.setPosition(BORDER, 5);
	top.setFillColor(sf::Color::Cyan); 

	sf::RectangleShape left(sf::Vector2f(BORDER, HEIGHT-10));
	left.setPosition(5, 5);
	left.setFillColor(sf::Color::Cyan); 

	sf::RectangleShape right(sf::Vector2f(BORDER, HEIGHT-10));
	right.setPosition(WIDTH-BORDER-5, 5);
	right.setFillColor(sf::Color::Cyan); 

	/*Set up collision for the borders*/
	playerCollide(top,    0.0F,  0.1F);
	playerCollide(bottom, 0.0F, -0.1F);
	playerCollide(left,   0.1F,  0.0F);
	playerCollide(right, -0.1F,  0.0F);



	window.clear();				
	draw(bottom);
	draw(top);
	draw(left);
	draw(right);

}


/* Draw anything that is always there. (Not moving) */
void Game::drawGame() {
	drawBorders();

}




/* General purpose function to draw a sprite */
void Game::draw(sf::RectangleShape sprite) {
	window.draw(sprite);
}


void Game::userInput() {	
	sf::Event event;
	while (window.pollEvent(event)) {
		if ((event.type == Event::Closed) ||
		   ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::D)))			//Press D to close the game
		   window.close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		movePlayer(0, YMIN);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		movePlayer(0, YPLU);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		movePlayer(XMIN, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		movePlayer(XPLU, 0);
	}
}


void Game::movePlayer(float x, float y) {
	player->movePlayer(x, y);
}


void Game::drawPlayer() {
	draw(player->getPlayer());
}


////////////////////////////////////////////////////COLLISION DETECTION////////////////////////////////////////////////////

void Game::playerCollide(RectangleShape sprite, float xDir, float yDir) {
	if (sprite.getGlobalBounds().intersects(player->getPlayer().getGlobalBounds())) {
		player->movePlayer(xDir, yDir);
	}
}



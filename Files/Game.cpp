#include "const.h"
#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Game::Game() {
	window.create(sf::VideoMode(WIDTH, HEIGHT), "Ping Pong");		//Initializes the video mode	
	MainPlayer = sf::RectangleShape(sf::Vector2f(20, 30));			//Initialize MainPlayer with vector properties
	playerSpeed.x = 0.5;
	playerSpeed.y = 0.5;
}



void Game::runWindow() {
	
	
	newPlayer2();
	while (window.isOpen())
    {	
		userInput();
	
        drawGame();					
		window.display();
		
	}	
}




void Game::newPlayer2() {
	
	MainPlayer.setOrigin(20, 30);
	MainPlayer.setPosition(200, 400);
	MainPlayer.setFillColor(sf::Color::Red);
	cout << "Player is set up\n";

}



void Game::drawBorders() {
	//Bottom
	int a = 1;
	sf::RectangleShape bottom(sf::Vector2f(WIDTH-2*BORDER, BORDER));
	bottom.setPosition(BORDER, HEIGHT-BORDER-5);
	bottom.setFillColor(sf::Color::Cyan);


	//Top
	int b = 2;
	sf::RectangleShape top(sf::Vector2f(WIDTH-2*BORDER, BORDER));
	top.setPosition(BORDER, 5);
	top.setFillColor(sf::Color::Cyan); 

	//Left
	int c = 3;
	sf::RectangleShape left(sf::Vector2f(BORDER, HEIGHT-10));
	left.setPosition(5, 5);
	left.setFillColor(sf::Color::Cyan); 

	//Right
	int d = 4;
	sf::RectangleShape right(sf::Vector2f(BORDER, HEIGHT-10));
	right.setPosition(WIDTH-BORDER-5, 5);
	right.setFillColor(sf::Color::Cyan); 

	colDetectionForBorders(MainPlayer,  bottom, a);
	colDetectionForBorders(MainPlayer,  top,    b);
	colDetectionForBorders(MainPlayer,  left,   c);
	colDetectionForBorders(MainPlayer,  right,  d);


	window.clear();				//Updates the screen after each full draw. IMPORTANT!!!
	window.draw(bottom);
	window.draw(top);
	window.draw(left);
	window.draw(right);
}




void Game::drawGame() {
	drawBorders();
	window.draw(MainPlayer);
}

void Game::draw(sf::RectangleShape sprite) {
	window.draw(sprite);
}


void Game::userInput() {
	
	

	sf::Event event;
	while (window.pollEvent(event)) {
		if ((event.type == Event::Closed) ||												
		   ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)) )
				window.close();			
		
		}

		/*	
		Moving shape up, down, left, right
		http://www.sfml-dev.org/tutorials/2.0/graphics-transform.php
		*/

	
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			MainPlayer.move(0, YMIN);
			showCoord(MainPlayer);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			MainPlayer.move(0, YPLU);
			showCoord(MainPlayer);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			MainPlayer.move(XMIN, 0);
			showCoord(MainPlayer);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			MainPlayer.move(XPLU, 0);
			showCoord(MainPlayer);
		}

		

}


void Game::showCoord(sf::RectangleShape player) {
	std::cout << "Current X-Position:  " << player.getPosition().x << "\n";
	std::cout << "Current Y-Position:  " << player.getPosition().y << "\n\n";
}


////////////////////////////////////////////////////COLLISION DETECTION////////////////////////////////////////////////////
bool Game::intersects(const sf::RectangleShape & rect1, const sf::RectangleShape & rect2) {

	FloatRect r1 = rect1.getGlobalBounds();
    FloatRect r2 = rect2.getGlobalBounds();
    return r1.intersects (r2);

}


void Game::colDetectionForBorders(sf::RectangleShape player, sf::RectangleShape obstacle, int num) { 
	
	
	
	if (intersects(player, obstacle)) {
		if (num == 1) {			//Bottom side							So bad coding XD
			playerSpeed.y = -playerSpeed.y;
			MainPlayer.move(0, playerSpeed.y-2);
		}
		else if (num == 2) {	//Top side
			playerSpeed.y = +playerSpeed.y;		
			MainPlayer.move(0, playerSpeed.y + 2);
		}
		else if (num == 3) {	//Left side
			playerSpeed.x = -playerSpeed.x;
			MainPlayer.move(playerSpeed.x + 2, 0);
		}
		else if (num == 4) {	//Right side
			playerSpeed.x = +playerSpeed.x;
			MainPlayer.move(playerSpeed.x -2, 0);
		}
		else
			cout << "\nWrong number @ colDetection\n";		
	}
}




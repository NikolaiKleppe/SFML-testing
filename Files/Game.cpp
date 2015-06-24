#include "const.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <sstream>      // std::stringstream
#include <SFML/Graphics.hpp>

using namespace std;

extern Player *player;															


Game::Game() {
	window.create(sf::VideoMode(WIDTH, HEIGHT), "Green dot vs The World");		
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(FPS);

	if (!font.loadFromFile("arial.ttf"))
		cout << "\nError";

}


void Game::runWindow() {		
	
	while (window.isOpen()) {	

		/*Makes the game run at 60fps*/
		time = renderClock.getElapsedTime();
		float fFps = 1000000 / time.asMicroseconds();
		std::stringstream s;
		s << fFps << " fps";				//Fungerer ikke? 
		fps.setString(s.str());
		renderClock.restart();

		const int frameTime = 1000000 / FPS;
		Clock c;
		Time t = c.getElapsedTime();
		int nextFrameTime = t.asMicroseconds() + frameTime;

		int loops = 0;
		while (t.asMicroseconds() < nextFrameTime && loops < MAX_FRAMESKIP)  {
			userInput();
			updateTime = updateClock.restart().asMilliseconds();
			drawGame();
			drawPlayer();
			t = c.getElapsedTime();
			loops++;
		}
		window.display();
	}	
}



void Game::drawRectangle(sf::RectangleShape name, int r, int g, int b, int width, int height, int x, int y) {
	sf::Color color(r, g, b);
	name.setSize(sf::Vector2f(width, height));
	name.setPosition(x, y);
	name.setFillColor(color);
	draw(name);
}


void Game::drawGame() {
	window.clear();




	//Borders
	sf::RectangleShape	b1;
	sf::RectangleShape	b2;
	sf::RectangleShape	b3;

	drawRectangle(b1, 100, 100, 100, B_WIDTH, B_HEIGHT, 20, 20);
	drawRectangle(b2, 100, 100, 100, B_HEIGHT , B_WIDTH, 20, 470);
	drawRectangle(b3, 100, 100, 100, B_HEIGHT, B_WIDTH, 20, 20);






	
	
	

	drawView();
}


void Game::drawView() {
	sf::View view(sf::FloatRect(200, 200, 300, 200));
	view.setSize(1200, 800);
	view.setViewport(sf::FloatRect(0, 0, 1, 1));
	window.setView(view);
}



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


	/* Debug: show fps*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		player->showCoord();
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



#include "const.h"
#include "Game.h"
#include "Player.h"
#include "gravity.h"
#include <iostream>
#include <sstream>      // std::stringstream
#include <SFML/Graphics.hpp>

using namespace std;

extern Player *player;
extern Gravity *gv;


Game::Game() {
	window.create(sf::VideoMode(WIDTH, HEIGHT), "Green dot vs The World");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(FPS);
	loadTextures();
}

void Game::loadTextures() {
	texture2.loadFromFile("../../files/texture/ground.png");
	texture3.loadFromFile("../../files/texture/block.png");
}

void Game::runWindow() {	
	while (window.isOpen()) {	

		/*Makes the game run at 60fps*/
		const int frameTime = 1000000 / FPS;
		Clock c;
		Time t = c.getElapsedTime();
		Int64 nextFrameTime = t.asMicroseconds() + frameTime;

		int loops = 0;
		while (t.asMicroseconds() < nextFrameTime && loops < FRAMESKIP)  {
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



void Game::drawRectangle(sf::RectangleShape name, float r_width, float r_height, float x, float y) {
	name.setSize(sf::Vector2f(r_width, r_height));
	name.setPosition(x, y);
	draw(name);
	playerCollide2(name);
}





void Game::drawGame() {
	window.clear();

	drawTextures(blocks, 100, texture2);
	drawTextures(borders, 100, texture3);

	//                            w        h      x      y
	drawRectangle(borders[1],     15,     200,    20,    20);
	drawRectangle(borders[2],   2250,      15,    20,   470);
	drawRectangle(borders[3],    450,      15,    20,    20);
	drawRectangle(blocks[1],      80,      50,   300,   420);
	drawRectangle(blocks[2],      80,      80,   500,   350);
	drawRectangle(blocks[3],      80,      50,   350,   250);
	drawRectangle(blocks[4],      80,      50,   500,   150);
	drawRectangle(blocks[5],      80,      50,   600,   100);

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
	sf::RectangleShape pp = player->getPlayer();
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




void Game::userInput() {	


	while (window.pollEvent(event)) {
		if ((event.type == Event::Closed) ||
		   ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::D)))		
		   window.close();
	}


	sf::Vector2f pos	   = player->getPlayer().getPosition();
	sf::RectangleShape pp  = player->getPlayer();
	sf::Vector2f vel	   = gv->setupGravity();

	

	movePlayer(0.0, vel.y);							//Up-Down
	movePlayer(vel.x, 0.0);							//Left-Right

	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		vel = gv->isOnGround();
	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		vel = gv->movingLeft();
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		vel = gv->movingRight();
	}

	else 											// No button press, de-accelerate player
		vel = gv->deAccelerate();
		gv->limitAcceleration();
		


		/* Debug: show coodinate*/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		//	player->showCoord();
			gv->printVelocity();
		}

	
}


void Game::movePlayer(float x, float y) {
	player->movePlayer(x, y);
}

void Game::setPlayerPos(float x, float y) {
	player->setPlayerPos(x, y);
}

void Game::drawPlayer() {
	draw(player->getPlayer());

}




void Game::playerCollide(RectangleShape sprite, float xDir, float yDir) {
	sf::RectangleShape pp = player->getPlayer();
	if (sprite.getGlobalBounds().intersects(pp.getGlobalBounds())) {
		movePlayer(xDir, yDir);  
	}
}


void Game::playerCollide2(RectangleShape sprite) {
	sf::RectangleShape pp = player->getPlayer();


	if (b_intersects(pp, sprite)) {							//Player has hit a block
										
		FloatRect f_player = pp.getGlobalBounds();

		FloatRect f_sprite = sprite.getGlobalBounds();		//The block to collide with
		Vector2f  v_sprite = sprite.getPosition();			//The block position
		Vector2f  v_player = pp.getPosition();				//The player position



		/* Sprite hit from right side */
		if ((v_player.x - 1.0) < v_sprite.x - f_player.height) {
			movePlayer(-1.0, 0.0);
			gv->setBelowSidesBool();

		}


		/* Sprite hit from left side */
		else if ((v_player.x - 18) > v_sprite.x + (f_sprite.width)) {
			movePlayer(1, 0.0);
			gv->setBelowSidesBool();
		}


		/* Sprite hit from top side */
		else if (v_player.y <= v_sprite.y + (f_sprite.height)) {
			movePlayer(0.0, -1.0);
			gv->setGroundBool();
		}


		/* Sprite hit from bot side*/
		else if (v_player.y >= v_sprite.y + (f_sprite.height)) {
			movePlayer(0.0, 1.0);
			gv->setBelowSidesBool();
		}
	}

	
}



bool Game::b_intersects(const RectangleShape &rect1, const RectangleShape &rect2) {
	FloatRect r1 = rect1.getGlobalBounds();
	FloatRect r2 = rect2.getGlobalBounds();
	return r1.intersects(r2);
}





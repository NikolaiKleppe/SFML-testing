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



void Game::drawRectangle(sf::RectangleShape name, int r, int g, int b, float r_width, float r_height, float x, float y) {
	sf::Color color(r, g, b);
	name.setSize(sf::Vector2f(r_width, r_height));
	name.setPosition(x, y);
	name.setFillColor(color);
	draw(name);

	playerCollide2(name);

}


void Game::drawGame() {
	window.clear();




	//Borders
	sf::RectangleShape	b1;
	sf::RectangleShape	b2;
	sf::RectangleShape	b3;

	//Blocks
	sf::RectangleShape  block;



	drawRectangle(b1, 200, 100, 100, B_WIDTH, 200, 20, 20);
	drawRectangle(b2, 150, 320, 140, B_HEIGHT*5 , B_WIDTH, 20, 470);
	drawRectangle(b3, 100, 100, 100, B_HEIGHT, B_WIDTH, 20, 20);
	drawRectangle(block, 50, 30, 30, 80, 80, 300, 420);




	
	
	

	drawView();
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
	sf::Event event;
	while (window.pollEvent(event)) {
		if ((event.type == Event::Closed) ||
		   ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::D)))			//Press D to close the game
		   window.close();
	}


	 sf::Vector2f pos = player->getPlayer().getPosition();
	 sf::RectangleShape pp = player->getPlayer();
	 const bool onground = pos.y >= 469;	//Update later to use blocks 

	 vel += gravity;
	 movePlayer(0.0, vel.y);

	if (vel.y > maxFall) {
		vel.y = maxFall;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (onground) {						//Onground -> initial jumping acceleration is increased
			vel.y += jumpAcc * 2;
			jumpcounter = jumpframes;		//Reset the jumpcounter to 10 when player hits ground
			movePlayer(0.0, vel.y);
		}

		else if (jumpcounter > 0) {			//Player is in the air, because Up was pressed from the ground
			vel.y += jumpAcc;				
			jumpcounter--;					//Decrease to 0 to exit loop
			movePlayer(0.0, vel.y);
		}
	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		vel.x -= runAcc;
		movePlayer(vel.x, 0.0);

	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		vel.x += runAcc;
		movePlayer(vel.x, 0.0);
	}

	
	else 								// No button press, de-accelerate player
		vel.x *= 0.992;
		movePlayer(vel.x, 0.0);
		std::cout << vel.x << "\n";
		



		/* Limits acceleration */
		if (vel.x > maxSpeed){
			vel.x = maxSpeed;
		}
		else if (vel.x < -maxSpeed) {
			vel.x = -maxSpeed;
		}

		///* Debug: show coodinate*/
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		//	player->showCoord();
		//}
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

	if (b_intersects(pp, sprite)) {

		FloatRect f_player = pp.getGlobalBounds();

		FloatRect f_sprite = sprite.getGlobalBounds();		//The block to collide with
		Vector2f  v_sprite = sprite.getPosition();			//The block position
		Vector2f  v_player = pp.getPosition();				//The player position
		

		/* TODO: Fix the random values*/

		/* Sprite hit from right side */
		/* A bit different: uses f_player.height. Makes more sense
		   but cant get it working for the other functions */
		if ((v_player.x - 1.0) < v_sprite.x - f_player.height) {
			movePlayer(-1.0, 0.0);
			
		}


		/* Sprite hit from left side */
		else if ((v_player.x - 18) > v_sprite.x + (f_sprite.width)) {
			movePlayer(1, 0.0);

		}


		/* Sprite hit from top side */
		else if (v_player.y <= v_sprite.y + (f_sprite.height)) {
			movePlayer(0.0, -1.0);

		}

		
		/* Sprite hit from bot side*/
		else if (v_player.y >= v_sprite.y + (f_sprite.height)) {
			movePlayer(0.0, 1.0);	
		}
	}

}







float Game::clamp(const float x, const float a, const float b) {
	return std::min(std::max(a, x), b);
}


bool Game::b_intersects(const RectangleShape &rect1, const RectangleShape &rect2) {
	FloatRect r1 = rect1.getGlobalBounds();
	FloatRect r2 = rect2.getGlobalBounds();
	return r1.intersects(r2);
}





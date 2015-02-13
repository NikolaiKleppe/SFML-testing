#if !defined(__Game_H)
#define __Game_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Player.h"

using namespace sf;


class Game {

protected:
	RenderWindow	window;
	Texture			pic;

public:

	Game();

	void runWindow();							//While window.isOpen etc					
	void drawBorders();							//Playfield
	void drawGame();							//Calls all the "draw" functions and renders the game
	void drawHealthBar();
	void drawPlayer();							//Retrieves data from player.cpp and draws it
	void draw(sf::RectangleShape sprite);		//Draw a sprite
	void userInput();							//General key pressing
	void movePlayer(float x, float y);

	void showCoord(sf::RectangleShape player);
	void playerCollide(RectangleShape sprite, float xDir, float yDir);	//Player collides with "sprite", move in direction X and Y. 
	bool intersecting(const sf::RectangleShape &rect1, const sf::RectangleShape &rect2);
};










#endif
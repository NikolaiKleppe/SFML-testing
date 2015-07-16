#if !defined(__Game_H)
#define __Game_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Player.h"

using namespace sf;


class Game {

private:
	RenderWindow	window;
	Texture			texture;
	Font			font;
	Int64			updateTime;					//60fps
	Clock			updateClock;				//60fps
	Event			event;						//Main event for userInput

	RectangleShape b1, b2, b3;
	RectangleShape block1, block2, block3, block4, block5;


public:

	Game();
	~Game();
	void runWindow();							
	void drawRectangle(sf::RectangleShape name, int r, int g, int b, float r_width, float r_height, float x, float y);
	void drawGame();							
	void drawView();							//How big the visible field is in res
	void drawPlayer();							
	void draw(sf::RectangleShape sprite);		
	void userInput();							
	void movePlayer(float x, float y);
	void setPlayerPos(float x, float y);

	void playerCollide(RectangleShape sprite, float xDir, float yDir);
	void playerCollide2(RectangleShape sprite);
	float clamp(const float x, const float a, const float b);
	bool b_intersects(const RectangleShape &rect1, const RectangleShape &rect2);
};










#endif
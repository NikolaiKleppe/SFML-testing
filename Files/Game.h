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



	Font			font;
	Text			fps;						//FPS display
	Time			time;						//FPS display
	Clock			renderClock, updateClock;	//FPS display
	int				updateTime;					//FPS display

public:

	Game();

	void runWindow();							//While window.isOpen etc	
	void drawRectangle(sf::RectangleShape name, int r, int g, int b, int width, int height, int x, int y);
	void drawGame();							//Calls all the "draw" functions and renders the game
	void drawView();
	void drawPlayer();							//Retrieves data from player.cpp and draws it
	void draw(sf::RectangleShape sprite);		//Draw a sprite

	void userInput();							//General key pressing
	void movePlayer(float x, float y);

	//void showCoord2(sf::RectangleShape player);
	void playerCollide(RectangleShape sprite, float xDir, float yDir);	//Player collides with "sprite", move in direction X and Y. 
};










#endif
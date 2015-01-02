#if !defined(__Game_H)
#define __Game_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

using namespace sf;


class Game {

protected:
	RenderWindow	window;
	//RectangleShape	MainPlayer;				
	//Vector2f		playerSpeed;
	

public:

	Game();

	void runWindow();							//While window.isOpen etc
	/*void newPlayer();*/							
	void drawBorders();							//Playfield
	void drawGame();							//Calls all the "draw" functions and renders the game
	void draw(sf::RectangleShape sprite);		//Uses "RenderWindow window" to render a sprite. 
	void userInput();							//Key Press etc
	void movePlayer(float x, float y);

	void showCoord(sf::RectangleShape player);
	/*void colDetectionForBorders(sf::RectangleShape, sf::RectangleShape, int num);*/			//Collision detection on borders
	bool intersecting(const sf::RectangleShape &rect1, const sf::RectangleShape &rect2);

	
};











#endif
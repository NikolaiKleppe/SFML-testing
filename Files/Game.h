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
	Texture			texture, texture2, texture3;
	Font			font;
	Int64			updateTime;					//60fps
	Clock			updateClock;				//60fps
	Event			event;						//Main event for userInput

	RectangleShape	b1, b2, b3;

	std::vector<sf::RectangleShape> blocks;
	std::vector<sf::RectangleShape> borders;

public:

	Game();
	~Game();
	void			runWindow();							
	void			drawRectangle(sf::RectangleShape name, float r_width, float r_height, float x, float y);
	void			drawGame();	
	void			drawTextures(std::vector<sf::RectangleShape> &shape, int size, sf::Texture &text);
	void			drawView();							//How big the visible field is in res
	void			drawPlayer();		
	void			draw(sf::RectangleShape sprite);	
	
	void			userInput();							
	void			movePlayer(float x, float y);
	void			setPlayerPos(float x, float y);

	void			loadTextures();

	void			playerCollide(RectangleShape sprite, float xDir, float yDir);
	void			playerCollide2(RectangleShape sprite);
	bool			b_intersects(const RectangleShape &rect1, const RectangleShape &rect2);
};










#endif
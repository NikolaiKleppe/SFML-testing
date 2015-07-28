#if !defined(__Game_H)
#define __Game_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Player.h"

 


class Game {

private:
	sf::RenderWindow		window;
	sf::Texture				ground, block;
	sf::Font				font;
	sf::Int64				updateTime;					//60fps
	sf::Clock				updateClock;				//60fps
	sf::Event				event;						//Main event for userInput

	sf::Vector2f			pos;
	sf::RectangleShape		pp;
	sf::Vector2f			vel;

	std::vector<sf::RectangleShape> blocks;
	std::vector<sf::RectangleShape> borders;

public:

	Game();
	~Game();
	void			runWindow();							
	void			drawRectangle(sf::RectangleShape name, float r_width, float r_height, float x, float y);
	void			drawGameLevel();	
	void			drawTextures(std::vector<sf::RectangleShape> &shape, int size, sf::Texture &text);
	void			drawView();							//How big the visible field is in res
	void			drawPlayer();		
	void			drawMonster();
	void			draw(sf::RectangleShape sprite);	
	
	void			userInput();							
	void			movePlayer(float x, float y);
	void			setPlayerPos(float x, float y);

	void			loadTextures();

};










#endif
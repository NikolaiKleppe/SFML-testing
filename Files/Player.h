#if !defined(__Player_H)
#define __Player_H


#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;


class Player {

protected:
	RenderWindow	playerWindow; //?
	RectangleShape	mainPlayer;
	Vector2f		playerSpeed;


public:
	Player();			
	void newPlayer();			//Initialize a player (setPosition etc)
	void drawPlayer();
	RectangleShape getPlayer();

	
};


	
	
	















#endif
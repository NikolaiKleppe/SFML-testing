#if !defined(__Player_H)
#define __Player_H


#include <SFML/Graphics.hpp>
#include <iostream>


 


class Player {

private:
	sf::RectangleShape	mainPlayer;
	sf::Texture			texture;

public:
	Player();			
	void				newPlayer();						//Initialize a player (setPosition etc)

	void				loadTextures();
	sf::RectangleShape	getPlayer();
	void				movePlayer(float x, float y);
	void				setPlayerPos(float x, float y);
	void				showCoord();
	


};


	
	
	















#endif
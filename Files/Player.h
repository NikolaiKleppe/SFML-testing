#if !defined(__Player_H)
#define __Player_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "AnimatedSprite.hpp"

 


class Player {

private:
	AnimatedSprite		mainPlayer;
	sf::RectangleShape  playerShadow;
	sf::Texture			texture;
	sf::Image			shadowImage;
	sf::Texture			shadowTexture;

	Animation walkingAnimationDown;
	Animation walkingAnimationLeft;
	Animation walkingAnimationRight;
	Animation walkingAnimationUp;

public:
	Player();			

	void				loadTextures();
	sf::RectangleShape  getPlayerShadow();
	AnimatedSprite		getPlayerAnim();
	void				movePlayer(float x, float y);
	void				moveShadow(float x, float y);
	void				setPlayerPos(float x, float y);
	void				showCoord();
	
	void setupAnim();


	Animation * getDown();
	Animation * getLeft();
	Animation * getRight();
	Animation * getUp();







};


	
	
	















#endif
#if !defined(__Game_H)
#define __Game_H


#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;


class Game {

protected:
	RenderWindow	window;
	RectangleShape	MainPlayer;				
	Vector2f		playerSpeed;

public:

	Game();

	void runWindow();							//While window.isOpen etc
	sf::RectangleShape newPlayer();				//The ball. Return value = player object
	void newPlayer2();							//Same as above, just no return value (Testing)
	void drawBorders();							//Playfield
	void drawGame();							//Calls all the "draw" functions and renders the game
	void draw(sf::RectangleShape sprite);		//Uses "RenderWindow window" to render a sprite. 
	void userInput(/*sf::RectangleShape player*/);	//Key Press etc
	

	void showCoord(sf::RectangleShape player);
	void colDetectionForBorders(sf::RectangleShape, sf::RectangleShape, int num);			//Collision detection, special case just for the borders
	bool intersects(const sf::RectangleShape &rect1, const sf::RectangleShape &rect2);


};











#endif
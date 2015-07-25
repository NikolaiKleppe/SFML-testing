#if !defined(__Monster_H)
#define __Monster_H

#include <SFML/Graphics.hpp>
#include <iostream>

 

class Monster {

private:
	sf::RectangleShape	mob;
	int moveCount;
	bool test;

public:
	Monster();
	Monster(int mC, bool t);

	void loadTextures();
	void moveMonster();
	sf::RectangleShape getMonster();




};

	
	
	















#endif
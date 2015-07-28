#if !defined(__Monster_H)
#define __Monster_H

#include <SFML/Graphics.hpp>
#include <iostream>

 

class Monster {

private:
	sf::RectangleShape	mob;
	sf::Texture			text1, text2;
	int moveCount;
	bool test;

	std::vector<sf::RectangleShape> monster;

public:
	Monster();
	Monster(int mC, bool t);


	void makeMonster(sf::RectangleShape name);
	void drawMonsters();
	void loadTextures();
	void moveMonster(sf::RectangleShape &name);




};

	
	
	















#endif
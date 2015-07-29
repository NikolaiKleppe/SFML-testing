#if !defined(__Monster_H)
#define __Monster_H

#include <SFML/Graphics.hpp>
#include <iostream>

 

class Monster {

private:
	sf::Texture			text1, text2;
	int moveCount;
	bool test;

	std::vector<sf::RectangleShape> monster;

public:
	Monster();
	Monster(int mC, bool t);


	void makeMonster(sf::RectangleShape name, float posX, float posY);
	void drawMonsters();
	void loadTextures();
	void moveMonster(sf::RectangleShape &name, sf::Texture &texture1, sf::Texture &texture2);




};

	
	
	















#endif
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Monster.h"
#include "Game.h"
#include "Collide.h"

extern Collide *collide;
extern Game *game;


Monster::Monster() {

}

Monster::Monster(int mC, bool t) {
	mob.setPosition(730, 300);			//cant be here
	moveCount = mC;
	test	  = t;	

	loadTextures();
}



void Monster::makeMonster(sf::RectangleShape name) {

	name.setSize(sf::Vector2f(200.0, 250.0));
	game->draw(name);
	collide->playerCollide(name);
	
}

void Monster::drawMonsters() {
	makeMonster(mob);

	/* make more monsters here */

	moveMonster(mob);					


}

void Monster::loadTextures() {
	text1.loadFromFile("../../files/texture/diablo_Left.png");
	text2.loadFromFile("../../files/texture/diablo_Right.png");
}



/* TODO: 
	Setup different movement path options with a switch	and put each option in its own function
		i.e all the code below should be in its own function.
*/
void Monster::moveMonster(sf::RectangleShape &name) {

	if (test == true) {
		name.move(0.2F, 0.0F);
		name.setTexture(&text2);
		moveCount--;
		if (moveCount == 0) {
			test = false;
		}
	}

	else if (test == false) {
		name.move(-0.2F, 0.0F);
		name.setTexture(&text1);
		moveCount++;
		if (moveCount == 1500) {
			test = true;
			
		}
	}
	
}


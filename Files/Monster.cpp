#include <iostream>
#include <SFML/Graphics.hpp>
#include "Monster.h"
#include "Game.h"
#include "Collide.h"

extern Collide *collide;


Monster::Monster() {

}

Monster::Monster(int mC, bool t) {
	mob = sf::RectangleShape(sf::Vector2f(60, 50));
	mob.setOrigin(20, 30);
	mob.setPosition(800, 450);
	mob.setFillColor(sf::Color::Red);

	moveCount = mC;
	test	  = t;

	
}


void Monster::loadTextures() {
	
}




void Monster::moveMonster() {
	collide->playerCollide(mob);
	if (test == true) {
		mob.move(0.2, 0.0);
		moveCount--;
		if (moveCount == 0) {
			test = false;
		}
	}

	else if (test == false) {
		mob.move(-0.2, 0.0);
		moveCount++;
		if (moveCount == 700) {
			test = true;
			
		}
	}
	
}

sf::RectangleShape Monster::getMonster() {
	return mob;
}
#include <SFML/Graphics.hpp>
#include <SFML/Collision.h>
#include "Game.h"
#include "Player.h"
#include "gravity.h"
#include "Monster.h"
#include "Collide.h"
#include "Bullet.h"
#include <iostream>


Game    *game;
Player	*player;
Gravity *gv;
Monster *monster;
Collide *collide;
Bullet  *bullet;
//AnimatedSprite *animatedSprite;



int main() { 	
	game    = new Game;
	game->runWindow();
	return 0;
}



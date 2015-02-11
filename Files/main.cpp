#include <SFML/Graphics.hpp>
#include <SFML/Collision.h>
#include "Game.h"
#include "Player.h"
#include "test.h"
#include <iostream>


Game *game;
Player *player;

int main() { 	
	game = new Game;
	player = new Player;
	game->runWindow();
	return 0;
}


/*	
http://riseagain.wordpress.com/2012/07/17/sfml-2-tutorial-pong/
http://www.wildbunny.co.uk/blog/2011/04/06/physics-engines-for-dummies/	
https://gist.github.com/anonymous/4444729
//Collision detection with other objects (blocks)
https://github.com/eXpl0it3r/Examples/blob/master/SFML/SimpleAABB.cpp


Moving shape up, down, left, right
http://www.sfml-dev.org/tutorials/2.0/graphics-transform.php

*/
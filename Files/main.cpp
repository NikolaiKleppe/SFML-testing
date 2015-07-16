#include <SFML/Graphics.hpp>
#include <SFML/Collision.h>
#include "Game.h"
#include "Player.h"
#include "gravity.h"
#include <iostream>


Game    *game;
Player	*player;

Gravity *gv;


int main() { 	
	game   = new Game;
	player = new Player;
	gv = new Gravity(0, 0.5F, 0.001F, -0.05F, -0.6F, 0.30F, -0.1F, sf::Vector2f(0.0F, 0.0F), sf::Vector2f(0.F, 0.003F), 10, false, false, 5.0F);
	game->runWindow();
	return 0;
}



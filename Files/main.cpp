#include <SFML/Graphics.hpp>
#include <SFML/Collision.h>
#include "Game.h"
#include "Player.h"
#include "test.h"
#include <iostream>


Game    *game;
Player	*player;

int main() { 	
	game   = new Game;
	player = new Player;
	game->runWindow();
	return 0;
}



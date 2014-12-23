#include <SFML/Graphics.hpp>
#include <SFML/Collision.h>
#include "Game.h"
#include <iostream>


Game *game;


int main()
{
 

	
	game = new Game;
	game->runWindow();


      

    

    return 0;

}













/*	http://riseagain.wordpress.com/2012/07/17/sfml-2-tutorial-pong/
	http://www.wildbunny.co.uk/blog/2011/04/06/physics-engines-for-dummies/
*/


		/*	
			//Collision detection for the window
			//https://gist.github.com/anonymous/4444729

			float xPos = player.getPosition().x;
			float yPos = player.getPosition().y;

			if ( xPos < 0 || xPos > WIDTH) {
				//
			}

		*/






			//Collision detection with other objects (blocks)
			//https://github.com/eXpl0it3r/Examples/blob/master/SFML/SimpleAABB.cpp
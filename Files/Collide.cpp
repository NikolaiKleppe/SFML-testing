
#include <SFML/Graphics.hpp>
#include "Collide.h"
#include "Game.h"
#include "Player.h"
#include "gravity.h"

extern Player *player;
extern Gravity *gv;

Collide::Collide() {

}

Collide::~Collide() {

}


void Collide::playerCollide(sf::RectangleShape sprite) {

	sf::RectangleShape pp = player->getPlayer();


	if (b_intersects(pp, sprite)) {								//Player has hit a block

		sf::FloatRect f_player = pp.getGlobalBounds();

		sf::FloatRect f_sprite = sprite.getGlobalBounds();		//The block to collide with
		sf::Vector2f  v_sprite = sprite.getPosition();			//The block position
		sf::Vector2f  v_player = pp.getPosition();				//The player position



		/* Sprite hit from right side */
		if ((v_player.x - 1.0) < v_sprite.x - f_player.height) {
			player->movePlayer(-1.0, 0.0);
			gv->setBelowSidesBool();

		}


		/* Sprite hit from left side */
		else if ((v_player.x - 18) > v_sprite.x + (f_sprite.width)) {
			player->movePlayer(1, 0.0);
			gv->setBelowSidesBool();
		}


		/* Sprite hit from top side */
		else if (v_player.y <= v_sprite.y + (f_sprite.height)) {
			player->movePlayer(0.0, -1.0);
			gv->setGroundBool();
		}


		/* Sprite hit from bot side*/
		else if (v_player.y >= v_sprite.y + (f_sprite.height)) {
			player->movePlayer(0.0, 1.0);
			gv->setBelowSidesBool();
		}
	}

}


bool Collide::b_intersects(const sf::RectangleShape &rect1, const sf::RectangleShape &rect2) {
	sf::FloatRect r1 = rect1.getGlobalBounds();
	sf::FloatRect r2 = rect2.getGlobalBounds();
	return r1.intersects(r2);
}


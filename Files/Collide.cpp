
#include <SFML/Graphics.hpp>
#include "Collide.h"
#include "Game.h"
#include "Player.h"
#include "gravity.h"
#include "AnimatedSprite.hpp"


extern Player *player;
extern Gravity *gv;
extern Game *game;

Collide::Collide() {

}

Collide::~Collide() {

}


void Collide::playerCollide(sf::RectangleShape sprite) {

    /* TODO: Size (height and width) of "sprite" determines if this works or not. 
        Only 1 size works atm, (50, 30).
        Fix the random values somehow. 
    */
    sf::RectangleShape pp = player->getPlayerShadow();
    
          
    if (b_intersects(pp, sprite)) {                             //Player has hit a block

        sf::FloatRect f_player = pp.getGlobalBounds();

        sf::FloatRect f_sprite = sprite.getGlobalBounds();      //The block to collide with
        sf::Vector2f  v_sprite = sprite.getPosition();          //The block position
        sf::Vector2f  v_player = pp.getPosition();              //The player position



        /* Sprite hit from right side */
        if ((v_player.x - 31.0) < v_sprite.x - f_player.height) {
            game->movePlayer(-1.0, 0.0);
            gv->setBelowSidesBoolToTrue();
        }


        /* Sprite hit from left side */
        else if ((v_player.x - 18) > v_sprite.x + (f_sprite.width)) {
            game->movePlayer(1.0, 0.0);

            gv->setBelowSidesBoolToTrue();
            


            gv->setBelowSidesBoolToTrue();

        }


        /* Sprite hit from top side */
        else if (v_player.y <= v_sprite.y + (f_sprite.height)) {
            game->movePlayer(0.0, -1.0);
            gv->setGroundBoolToTrue();
        }


        /* Sprite hit from bot side*/
        else if (v_player.y >= v_sprite.y + (f_sprite.height)) {
            game->movePlayer(0.0, 1.0);
            gv->setBelowSidesBoolToTrue();
        }
    }

}





bool Collide::b_intersects(const sf::RectangleShape &rect1, const sf::RectangleShape &rect2) {

    sf::FloatRect r1 = rect1.getGlobalBounds();
    sf::FloatRect r2 = rect2.getGlobalBounds();
    return r1.intersects(r2);
}


void Collide::movePlayer(float x, float y) {
    player->moveShadow(x, y);
    game->movePlayer(x, y);
}
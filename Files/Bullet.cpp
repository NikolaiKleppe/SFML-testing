#include "Bullet.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

extern Game *game;

Bullet::Bullet() {

    loadTextures();
//  bullet.resize(1000);
    sprite.setPosition(200, 200);

}

Bullet::~Bullet() {

}



void Bullet::makeBullet() {
    
    /*Everytime fireBullet() is called:
    - Make a new bullet
    - Put into vector
    - 
    
    */


    game->draw(sprite);

}

void Bullet::fireBullet() {
    makeBullet();   //Start with making a bullet when Space is held down

    /*
    Everything on update position, set start position etc
    Fire velocity
    Delete when out of screen or time has passed
    
    */


}


void Bullet::loadTextures() {

    texture.loadFromFile("../../files/texture/weapons/bullet.png");
    sprite.setTexture(texture);

}
























#include "Bullet.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

extern Game *game;

Bullet::Bullet() {
    bullet.resize(100); 
    loadTextures();
    std::cout << "\dd";
}

Bullet::~Bullet() {
    std::cout << "\ndead";
}



void Bullet::makeBullet(sf::Sprite &name, float posX, float posY, sf::Texture &text) {
    
    /*Everytime fireBullet() is called:
    - Make a new bullet
    - Put into vector
    - 
    
    */

    name.setOrigin(sf::Vector2f(posX, posY));       //Later: origin = player position etc etc
    name.setTexture(text);

    
   
    game->draw(name);
    
    
    
}

void Bullet::fireBullet() {
    

    makeBullet(bullet[1], -400, -400, texture);  //Start with making a bullet when Space is held down

    test(bullet[1]);
    

    /*
    Everything on update position, set start position etc
    Fire velocity
    Delete when out of screen or time has passed
    
    */
    

   
}

void Bullet::test(sf::Sprite &sprite) {
    


    sprite.move(0.5F, 0.0F);
    
  
}


void Bullet::loadTextures() {




  /*  texture.loadFromFile("../../files/texture/weapons/bullet.png"); */
  
    image.loadFromFile("../../files/texture/weapons/bullet.png");

    image.createMaskFromColor(sf::Color::White);

    texture.loadFromImage(image);
}
























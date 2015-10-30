#include "Bullet.h"
#include "Game.h"
#include <SFML/Graphics.hpp>



extern Game *game;

Bullet::Bullet() {
    bullet.resize(100); 
    isFiring = false;
    loadTextures();
}

Bullet::~Bullet() {
}



void Bullet::createBullet(sf::Sprite &name, sf::Texture &text) {
    


    name.setOrigin(sf::Vector2f(-400.0, -400.0));       //Later: origin = player position etc etc
    name.setTexture(text);

    /*
    Need to push_back here
    */

    game->draw(name);
    
    
    
}

void Bullet::fireBullet() {
    
    /*Everytime fireBullet() is called:
    1) Create a new bullet (push_back into vector)
    2) Move the bullet until hit hits screen border
    3) Delete the bullet (pop)
    */


    /*
    Start with making a bullet when Space is pressed(!)
    [1] is temp hardcoded, need to be dynamic. Cant get push_back to work ._.
    */
    createBullet(bullet[1], texture);



   
    //Everything on update position, set start position etc
    moveBullet(bullet[1]);



    //Delete when out of screen or a set time has passed (pop)
    
    
    

   
}

void Bullet::moveBullet(sf::Sprite &sprite) {
    float x, y = 0.F;

    sprite.move(0.5F, 0.0F);  // X direction. Only temporary. This only works as long as space is held down







//   Set fire velocity 
//   x += velocity
//   y += velocity
//   sprite.setPosition(x, y);


   
    
  
}


void Bullet::loadTextures() {
  /*  texture.loadFromFile("../../files/texture/weapons/bullet.png"); */
  
    image.loadFromFile("../../files/texture/weapons/bullet.png");
    image.createMaskFromColor(sf::Color::White);
    texture.loadFromImage(image);
}






















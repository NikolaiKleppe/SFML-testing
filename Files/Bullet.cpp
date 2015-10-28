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
    


    name.setOrigin(sf::Vector2f(posX, posY));       //Later: origin = player position etc etc
    name.setTexture(text);

    
   
    game->draw(name);
    
    
    
}

void Bullet::fireBullet() {
    
    /*Everytime fireBullet() is called:
    - Make a new bullet
    - Put into vector
    -

    */


    /*
    Start with making a bullet when Space is pressed(!)
    -400, -400 is just temporary position. Needs to be started from current player position + an offset. 
    */
    makeBullet(bullet[1], -400, -400, texture);    

    moveBullet(bullet[1]);
    

   
  //  Everything on update position, set start position etc



  //  Set fire velocity ? 



  //  Delete when out of screen or a set time has passed
    
    
    

   
}

void Bullet::moveBullet(sf::Sprite &sprite) {
    float x, y = 0.F;



    sprite.move(0.5F, 0.0F);  // X direction. Only temporary



//   x += blabla
//   y += blabla
//   sprite.setPosition(x, y);


   
    
  
}


void Bullet::loadTextures() {
  /*  texture.loadFromFile("../../files/texture/weapons/bullet.png"); */
  
    image.loadFromFile("../../files/texture/weapons/bullet.png");
    image.createMaskFromColor(sf::Color::White);
    texture.loadFromImage(image);
}
























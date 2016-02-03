#include "Bullet.h"
#include "Game.h"
#include <SFML/Graphics.hpp>


extern Game *game;


Bullet::Bullet() {

    /*
    Can also use bullet.resize. This puts X elements into the vector so we don't
    have to do an allocate(insert) operation every time a new bullet is created. 
    Then if we want to shoot 10 bullets, out of 50 available, we loop until 10
    bullets are fired then stop. 

    A reload function can just be another bullet.resize operation. 
    
    */                   
    loadTextures();


    velocity.x = 0.2F;                       //Temporay
    velocity.y = 0.0F;

    position = sf::Vector2f(280.0F, 470.0F); //Temporary

    maxAmmmo = 1;
}

Bullet::~Bullet() {

}








void Bullet::fireBullet() {
    
    /*Everytime fireBullet() is called:
    1) Create a new bullet. push_back
    2) Move the bullet until it hits screen border
    3) Delete the bullet (pop from vector?)
    */

    createBullet();
   // std::cout << "Amount of bullets in vector: " << (bullet.size()) << std::endl;

}





void Bullet::createBullet() {
    if (bullet.size() < maxAmmmo) {
        bullet.push_back(bulletSpr);

       // std::cout << bullet.size() << std::endl;
        
    }
    moveBullet();
}


void Bullet::moveBullet() {
       /* Timer
        http://www.sfml-dev.org/tutorials/2.0/system-time.php   
        Need a way to put a delay between each bullet spawn!
       */

    position += velocity;

    for (size_t i = 0; i < bullet.size(); i++) {
        game->draw(bullet[i]);      //Doesn't work, idk why.


        bullet[i].setPosition(position);
        std::cout << bullet[i].getPosition().x << std::endl;
    }

    //bullet[bul - 1].setPosition(position);
    //game->draw(bullet[bul - 1]); 
    //std::cout << bullet[bul - 1].getPosition().x << "\n";
}



void Bullet::deleteBullets() {
    /*
    Once ONE bullet has reached the edge of the screen, delete. 
    Repeat.
    */

}



void Bullet::loadTextures() {
    if (!bulletImage.loadFromFile("../../files/texture/weapons/bullet.png")) {
        std::cout << "your nan is fat\n";
    }


    bulletImage.createMaskFromColor(sf::Color::White);
    texture.loadFromImage(bulletImage);


    bulletSpr.setTexture(texture);
    bulletSpr.setOrigin(sf::Vector2f(-400.0, -400.0));
}
















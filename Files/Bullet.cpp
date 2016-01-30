#include "Bullet.h"
#include "Game.h"
#include <SFML/Graphics.hpp>


extern Game *game;


Bullet::Bullet() {
   //// bullet.resize(10);                      
   // loadTextures();
   // std::cout << "hi\n";


}

Bullet::~Bullet() {

}








void Bullet::fireBullet() {
    
    /*Everytime fireBullet() is called:
    1) Create a new bullet. push_back
    2) Move the bullet until it hits screen border
    3) Delete the bullet (pop from vector)
    */

    

   // std::cout << "Amount of bullets in vector: " << (bullet.size()) << std::endl;

}





void Bullet::createBullet() {

  //  bullet.push_back(Bullet());


}


void Bullet::moveBullet() {





    //if (isFiring == true) {

    //    //Timer here. 
    //    //http://www.sfml-dev.org/tutorials/2.0/system-time.php   


    //        bulletTime--;
    //        sprite.move(0.2F, 0.0);


    //        if (bulletTime <= 10) {

    //            isFiring = false;       //Enough time has passed, de-spawn bullet.
    //            bulletTime = 1000;      //Reset
    //        }
    //    
    //}


}







void Bullet::loadTextures() {
    bulletImage.loadFromFile("../../files/texture/weapons/bullet.png");
    bulletImage.createMaskFromColor(sf::Color::White);
    texture.loadFromImage(bulletImage);


    bulletSpr.setTexture(texture);
    bulletSpr.setOrigin(sf::Vector2f(-400.0, -400.0));



}
















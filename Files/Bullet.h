#if !defined(__Bullet_H)
#define __Bullet_H


#include <SFML/Graphics.hpp>
#include <iostream>

 


class Bullet {

private:

    sf::Sprite              bulletSpr;
    sf::Texture             texture;
    sf::Image               bulletImage;

    //std::vector<sf::Sprite> bullet;
    std::vector<Bullet>     bullet;

   





public:

    Bullet();
    ~Bullet();




    void                    createBullet();
    void                    fireBullet();
    void                    loadTextures();

    void                    moveBullet();



};


    
    
    















#endif
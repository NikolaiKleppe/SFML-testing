#if !defined(__Bullet_H)
#define __Bullet_H


#include <SFML/Graphics.hpp>
#include <iostream>

 


class Bullet {

private:
    sf::Sprite              sprite;
    sf::Texture             texture;
    sf::Vector2f            targetDirection;

    std::vector<sf::Sprite> bullet;

public:
    Bullet();
    ~Bullet();

    void                    makeBullet();
    void                    fireBullet();
    void                    loadTextures();
};


    
    
    















#endif
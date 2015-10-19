#if !defined(__Bullet_H)
#define __Bullet_H


#include <SFML/Graphics.hpp>
#include <iostream>

 


class Bullet {

private:
    sf::Sprite              sprite;
    sf::Texture             texture;
    sf::Image               image;
    sf::Vector2f            targetDirection; 

    std::vector<sf::Sprite> bullet;

public:
    Bullet();
    ~Bullet();

    void                    makeBullet(sf::Sprite &name, float posX, float posY, sf::Texture &text);
    void                    fireBullet();
    void                    loadTextures();

    void test(sf::Sprite &sprite);
};


    
    
    















#endif
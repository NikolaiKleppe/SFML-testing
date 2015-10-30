#if !defined(__Bullet_H)
#define __Bullet_H


#include <SFML/Graphics.hpp>
#include <iostream>

 


class Bullet {

private:
    sf::Sprite              sprite;
    sf::Texture             texture;
    sf::Image               image;

    std::vector<sf::Sprite> bullet;

    int                     travelTime;
    bool                    isFiring;

public:
    Bullet();
    ~Bullet();

    void                    createBullet(sf::Sprite &name, sf::Texture &text);
    void                    fireBullet();
    void                    loadTextures();

    void                    moveBullet(sf::Sprite &sprite);
};


    
    
    















#endif
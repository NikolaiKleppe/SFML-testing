#if !defined(__Game_H)
#define __Game_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Player.h"
#include "AnimatedSprite.hpp"
 


class Game {

private:

     

    sf::RenderWindow        window;
    sf::Texture             ground, block;
    sf::Font                font;
    sf::Int64               updateTime;                 //60fps
    sf::Clock               updateClock;                //60fps
    sf::Event               event;                      //Main event for userInput

    sf::Vector2f            pos; 
    sf::Vector2f            vel;                        //Velocity

    std::vector<sf::RectangleShape> blocks;
    std::vector<sf::RectangleShape> borders;


    Animation *currentAnimation;
    AnimatedSprite animatedSprite;


    sf::Clock frameClock;
    sf::Time frameTime;
    bool noKeyWasPressed;

    


public:

    Game();
    ~Game();
    void            runWindow();                            
    void            drawRectangle(sf::RectangleShape name, float r_width, float r_height, float x, float y);
    void            drawGameLevel();    
    void            drawTextures(std::vector<sf::RectangleShape> &shape, int size, sf::Texture &text);
    void            drawView();                         //How big the visible field is in res
    void            drawPlayer();                       //Player = animation
    void            drawMonster();
    void            draw(sf::RectangleShape sprite);    
    void            draw(sf::Sprite sprite);
    void            draw(AnimatedSprite);
    
    void            userInput();                            
    void            movePlayer(float x, float y);
    void            setPlayerPos(float x, float y);

    void            loadTextures();




    void                   drawPlayerShadow();
    AnimatedSprite         getAnim();

    void fireBullet();


};










#endif
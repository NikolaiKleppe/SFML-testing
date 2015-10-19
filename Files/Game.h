#if !defined(__Game_H)
#define __Game_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Player.h"
#include "AnimatedSprite.hpp"
#include "level.h"
 
class Game {

private:
    sf::RenderWindow        window;
    sf::Font                font;
    sf::Event               event;                      //Main event for userInput

    sf::Vector2f            vel;                        //Player velocity

     /* 60 FPS */
    sf::Int64               updateTime, nextFrameTime;
    sf::Clock               updateClock, clock;
    sf::Time                time;

	/* Animation stuff */
    Animation              *currentAnimation;
    AnimatedSprite         animatedSprite;
    sf::Clock              frameClock;								
    sf::Time               frameTime;									
    bool                   noKeyWasPressed;								

public:
    Game();
    ~Game();
    void                   runWindow();                            
	void                   drawPlayer();                //Player = animation
	void                   drawMonster();
	void                   draw(sf::RectangleShape sprite);
	void                   draw(sf::Sprite sprite);
	void                   draw(AnimatedSprite);
    
	void                   userInput();
	void                   movePlayer(float x, float y);
	void                   setPlayerPos(float x, float y);

    void                   drawPlayerShadow();
    AnimatedSprite         getAnim();
};










#endif
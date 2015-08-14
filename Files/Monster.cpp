#include <iostream>
#include <SFML/Graphics.hpp>
#include "Monster.h"
#include "Game.h"
#include "Collide.h"

extern Collide *collide;
extern Game *game;


Monster::Monster() {

}

Monster::Monster(int mC, bool t) {
    moveCount = mC;
    test      = t;  

    loadTextures();
}



void Monster::makeMonster(sf::RectangleShape name, float posX, float posY, float sizeX, float sizeY) {
    name.setOrigin(sf::Vector2f(posX, posY));
    name.setSize(sf::Vector2f(sizeX, sizeY));
    game->draw(name);
    collide->playerCollide(name);                   //Set up collision with the player
}

void Monster::drawMonsters() {
    monster.resize(100);
    makeMonster(monster[1], -600.0, -100.0, 200.0, 250.0);

    moveMonster(monster[1], text1, text2);
}

void Monster::loadTextures() {
    image1.loadFromFile("../../files/texture/hostile/cow_Left.png");
    image1.createMaskFromColor(sf::Color::White);

    image2.loadFromFile("../../files/texture/hostile/cow_Right.png");
    image2.createMaskFromColor(sf::Color::White);

    text1.loadFromImage(image1);
    text2.loadFromImage(image2);
}



/* TODO: 
    Setup different movement path options with a switch and put each option in its own function
        i.e all the code below should be in its own function.
*/
void Monster::moveMonster(sf::RectangleShape &name, sf::Texture &texture1, sf::Texture &texture2) {

    if (test == true) {
        name.move(0.2F, 0.0F);
        name.setTexture(&texture2);
        moveCount--;
        if (moveCount == 0) {
            test = false;
        }
    }

    else if (test == false) {
        name.move(-0.2F, 0.0F);
        name.setTexture(&texture1);
        moveCount++;
        if (moveCount == 1500) {
            test = true;
            
        }
    }
    
}


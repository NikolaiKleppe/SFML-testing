#include <SFML/Graphics.hpp>
#include "level.h"
#include "Collide.h"
#include "Game.h"
#include "Player.h"

extern Game *game;
extern Collide *collide;
extern Player *player;

Level::Level() {
    loadTextures();
}

void Level::loadTextures() {
    ground.loadFromFile("../../files/texture/level/ground.png");
    block.loadFromFile("../../files/texture/level/block.png");
}

void Level::drawGameLevel() {
    drawTexture(blocks, 100, ground);
    drawTexture(borders, 100, block);

    //                            w        h        x        y
    drawRectangle(borders[1],     15,      200,   -200,     20);
    drawRectangle(borders[2],   2250,      15,    -200,    470);
    drawRectangle(borders[3],    450,      15,    -200,     20);

    drawRectangle(blocks[1],      80,      50,     100,    420);
    drawRectangle(blocks[2],      80,      80,    -100,    370);
    drawRectangle(blocks[3],      80,      50,     70,     280);
    drawRectangle(blocks[4],      80,      50,     -80,    180);
    drawRectangle(blocks[5],      150,     50,     160,    100);
}

sf::View Level::drawView() {
    sf::View view(sf::FloatRect(200, 200, 300, 200));
    sf::RectangleShape pp = player->getPlayerShadow();
    sf::Vector2f player_pos = pp.getPosition();

    view.setSize(1200, 800);
    view.setViewport(sf::FloatRect(0, 0, 1, 1));
    view.setCenter(260, 250);

    /* Player moves out of screen region, move the view*/

    /* Exits right border*/
    if (player_pos.x >= 830) {
        view.move(1190, 0);
    }
    return view;
}

void Level::drawRectangle(sf::RectangleShape name, float r_width, float r_height, float x, float y) {
    name.setSize(sf::Vector2f(r_width, r_height));
    name.setPosition(x, y);
    game->draw(name);
    collide->playerCollide(name);
}

void Level::drawTexture(std::vector<sf::RectangleShape> &shape, int size, sf::Texture &text) {
    shape.resize(size);
    for (auto i = shape.begin(); i != shape.end(); i++) {
        i->setTexture(&text);
    }
}
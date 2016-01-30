#if !defined(__Level_H)
#define __Level_H

#include <SFML/Graphics.hpp>

class Level {
private:
    sf::Texture             ground, block;
    std::vector<sf::RectangleShape> blocks;
    std::vector<sf::RectangleShape> borders;


public:
    Level();

    void                    loadTextures();
        
    void                    drawGameLevel();
    sf::View                drawView();

    void                    drawRectangle(sf::RectangleShape name, float r_width, float r_height, float x, float y);
    void                    drawTexture(std::vector<sf::RectangleShape> &shape, int size, sf::Texture &text);
};






#endif
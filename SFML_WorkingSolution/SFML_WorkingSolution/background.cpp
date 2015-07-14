#include <SFML/Graphics.hpp>
#include "background.h"


void Background::setBackground(std::string name, sf::Vector2f pos) {
	BGI.loadFromFile(name);
	BG.setTexture(BGI);
	BG.setPosition(pos);
}
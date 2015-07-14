#if !defined(__Background_H)
#define __Background_H


#include <SFML/Graphics.hpp>
#include <iostream>




class Background {



private: 
	sf::Texture BGI;
	sf::Sprite BG;

public:
	Background(std::string name) {
		setBackground(name, sf::Vector2f(0.f, 0.f));
	}

	void setBackground(std::string name, sf::Vector2f pos);
	

};





// https://stackoverflow.com/questions/13616847/how-to-pass-an-image-in-sfml-c
























#endif
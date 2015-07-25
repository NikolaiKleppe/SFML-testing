#if !defined(__Collide_H)
#define __Collide_H


#include <SFML/Graphics.hpp>




class Collide {

private:

public:

	Collide();
	~Collide();


	void				playerCollide(sf::RectangleShape sprite);
	bool				b_intersects(const sf::RectangleShape &rect1, const sf::RectangleShape &rect2);
	
	

};



#endif
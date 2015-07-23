#if !defined(__Gravity_H)
#define __Gravity_H


#include <SFML/Graphics.hpp>



class Gravity {

private:

	int				jumpCounter;
	float			maxFall;
	float			runAcc;
	float			jumpAcc;
	float			maxJumpSpeed;
	float			maxYSpeed;
	float			maxAcc;

	sf::Vector2f	vel;
	sf::Vector2f	gravity;
	

	int				jumpFrames;

	bool			hitGround;
	bool			hitSidesOrBelow;
	float			hitTimer;

public:
	Gravity();
	~Gravity();
	Gravity(int jC, const float mF, const float rA, const float jA, const float jS, const float mS, const float mA,
		sf::Vector2f v, sf::Vector2f g,
		const int jF, bool hG, bool hS, float hT
		);


	sf::Vector2f	updateGravity();
	sf::Vector2f	isOnGround();
	sf::Vector2f	isInAir();
	sf::Vector2f	movingLeft();
	sf::Vector2f	movingRight();
	sf::Vector2f	deAccelerate();
	void			limitAcceleration();
	void			setGroundBool();
	void			setBelowSidesBool();

	void			printBools();
	void			printVelocity();

	



};





#endif
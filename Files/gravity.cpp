#include "gravity.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Gravity::Gravity() {
	
}

Gravity::Gravity(int jC, const float mF, const float rA, const float jA, const float jS, const float mS, const float mA,
			     sf::Vector2f v, sf::Vector2f g,
				 const int jF, bool hG, bool hS, float hT) {


	jumpCounter		= jC;
	maxFall			= mF;
	runAcc			= rA;
	jumpAcc			= jA;
	maxJumpSpeed    = jS;
	maxSpeed		= mS;
	maxAcc			= mA;

	vel				= v;
	gravity			= g;

	jumpFrames		= jF;
	hitGround		= hG;
	hitSidesOrBelow = hS;
	hitTimer		= hT;




		std::cout << "JumpCounter        "			<< jumpCounter << "\n";
		std::cout << "maxFall            "				<< maxFall << "\n";
		std::cout << "runAcc             "				<< runAcc << "\n";
		std::cout << "jumpAcc            "				<< jumpAcc << "\n";
		std::cout << "maxSpeed           "			<< maxSpeed << "\n";
		std::cout << "maxAcc             "				<< maxAcc << "\n";

		std::cout << "vel.y              "				<< vel.y << "\n";
		std::cout << "vel.x              "				<< vel.x << "\n";

		std::cout << "hitGround          "			<< hitGround << "\n";
		std::cout << "hitSidesOrBelow    "		<< hitSidesOrBelow << "\n";
		std::cout << "hitTimer           "			<< hitTimer << "\n";

}



sf::Vector2f Gravity::setupGravity() {

	vel += gravity;
	return vel;
	
}




sf::Vector2f Gravity::isOnGround() {
	if (hitGround == true) {					
		vel.y += jumpAcc * 2.0;					//Onground -> initial jumping acceleration is increased
		jumpCounter = jumpFrames;				//Reset the jumpcounter to 10 when player hits ground
		hitTimer *= 0.9;						//While in air, decrease value
		if (hitTimer < 2.2) {					//It's time to stop player acceleration
			hitGround = false;					//Break out of main loop
		}
	}

	else if (jumpCounter > 0) {					//>0 means player is in the air
		vel.y += jumpAcc;						//Accelerate player
		jumpCounter--;							//Decrease to 0 to exit acceleration loop
		hitTimer = 5.0F;						//Reset timer for next time hitGround is true
		/*std::cout << vel.y << "\n";	*/
	}
	return vel;
}


sf::Vector2f Gravity::movingLeft() {
	vel.x -= runAcc;
	return vel;
}


sf::Vector2f Gravity::movingRight() {
	vel.x += runAcc;
	return vel;

}


sf::Vector2f Gravity::deAccelerate() {
	vel.x *= 0.992;
	return vel;

}

void Gravity::limitAcceleration() {
	/*This whole function exists because the other code is bad and buggy ^)*/

	/* Limit acceleration (left and right) */
	if (vel.x > maxSpeed){
		vel.x = maxSpeed;
	}
	else if (vel.x < -maxSpeed) {
		vel.x = -maxSpeed;
	}

	/* Limit fallspeed acceleration */
	if (vel.y > maxFall) {
		vel.y = maxFall;
	}


	/* Limit jump speed */
	if (vel.y < maxJumpSpeed) {
		vel.y = maxJumpSpeed;
	}


	/* Stops a bug where player will accelerate too fast when hitting blocks from the side*/
	if ((vel.y < maxAcc) && (hitSidesOrBelow == true)) {
		vel.y = maxAcc;
	}
	else {
		hitSidesOrBelow = false;
	}







}


void Gravity::setGroundBool() {
	hitGround = true;

}

void Gravity::setBelowSidesBool() {
	hitSidesOrBelow = true;

}


void Gravity::printBools() {
	std::cout << "hitGround: " << hitGround << "\n";
	std::cout << "hitSidesOrBelow: " << hitSidesOrBelow << "\n";

}


void Gravity::printVelocity() {
	std::cout << vel.y << "\n";
}
#include "gravity.h"
#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>



//Gravity(0, 0.4F, 0.0008F, -0.05F, -0.8F, -0.1F, sf::Vector2f(0.0F, 0.0F), sf::Vector2f(0.F, 0.003F), 10, false, false, 5.0F);


Gravity::Gravity() {

    jumpCounter     = 0;
    jumpFrames      = 10;
    maxFall         = 0.4F;
    hitTimer        = 5.0F;
    maxAcc          = -0.1F;          //Idk?
    maxJumpSpeed    = -0.8F;
    maxXSpeed       = -0.1F;
    hitGround       = false;
    hitSidesOrBelow = false;
    jumpAcc         = -0.05F;
    runAcc          = 0.0008F;
    vel             = sf::Vector2f(0.0F, 0.0F);
    gravity         = sf::Vector2f(0.0F, 0.003F);

    Player *player = new Player();
    maxXSpeed = player->getPlayerSpeed();
    

}


sf::Vector2f Gravity::updateVelocity() {
    vel += gravity;
    return vel; 
}


sf::Vector2f Gravity::isOnGround() {
    if (hitGround == true) {                    
        vel.y += jumpAcc * 2.0F;                //Onground -> initial jumping acceleration is increased
        jumpCounter = jumpFrames;               //Reset the jumpcounter to 10 when player hits ground
        hitTimer *= 0.9F;                       //While in air, decrease value
        if (hitTimer < 2.2) {                   //It's time to stop player acceleration
            hitGround = false;                  //Break out of main loop
        }
    }

    else if (jumpCounter > 0) {                 //>0 means player is in the air
        vel.y += jumpAcc;                       //Accelerate player
        jumpCounter--;                          //Decrease to 0 to exit acceleration loop
        hitTimer = 5.0F;                        //Reset timer for next time hitGround is true
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
    vel.x *= 0.980F;
    return vel;
}


void Gravity::limitAcceleration() {
    /* Stops sudden weird speeds under certain conditions */


    if (vel.x > maxXSpeed){              //Limit acceleration right
        vel.x = maxXSpeed;
    }
    else if (vel.x < -maxXSpeed) {       //Limit acceleration left
        vel.x = -maxXSpeed;             
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
    /* TODO: setup else here, same as on maxXspeed */

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
    std::cout << "hitGround: "       << hitGround << "\n";
    std::cout << "hitSidesOrBelow: " << hitSidesOrBelow << "\n";
}


void Gravity::printVelocity() {
    std::cout << vel.y << "\n";
}
#include "gravity.h"
#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Gravity::Gravity() {
    
}

Gravity::Gravity(
    int                _jumpCounter, 
    const float        _maxFall, 
    const float        _runAcc, 
    const float        _jumpAcc, 
    const float        _maxYSpeed,  
    const float        _maxAcc,
    sf::Vector2f       _velocity, 
    sf::Vector2f       _gravity,
    const int          _jumpFrames, 
    bool               _hitGround,
    bool               _hitSidesOrBelow, 
    float              _hitTimer
    ) {

    Player *player = new Player();
    maxXSpeed = player->getPlayerSpeed();
    
    jumpCounter     =  _jumpCounter;
    maxFall         =  _maxFall;
    runAcc          =  _runAcc;
    jumpAcc         =  _jumpAcc;
    maxJumpSpeed    =  _maxYSpeed;
    maxAcc          =  _maxAcc;

    vel             =  _velocity;
    gravity         =  _gravity;

    jumpFrames      =  _jumpFrames;
    hitGround       =  _hitGround;
    hitSidesOrBelow =  _hitSidesOrBelow;
    hitTimer        =  _hitTimer;


    std::cout <<       "JumpCounter        "         << jumpCounter     << "\n";
    std::cout <<       "maxFall            "         << maxFall         << "\n";
    std::cout <<       "runAcc             "         << runAcc          << "\n";
    std::cout <<       "jumpAcc            "         << jumpAcc         << "\n";
    std::cout <<       "maxJumpSpeed       "         << maxJumpSpeed    << "\n";
    std::cout <<       "maxXSpeed          "         << maxXSpeed       << "\n";
    std::cout <<       "maxAcc             "         << maxAcc          << "\n";

    std::cout <<       "vel.y              "         << vel.y           << "\n";
    std::cout <<       "vel.x              "         << vel.x           << "\n";
    std::cout <<       "gravity            "         << gravity.y       << "\n";

    std::cout <<       "hitGround          "         << hitGround       << "\n";
    std::cout <<       "hitSidesOrBelow    "         << hitSidesOrBelow << "\n";
    std::cout <<       "hitTimer           "         << hitTimer        << "\n";

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
    /*This whole function exists because the other code is bad and buggy ^)
        The different speeds are always increasing when there's no limit set. 
    */

                                        
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
#if !defined(__Gravity_H)
#define __Gravity_H


#include <SFML/Graphics.hpp>



class Gravity {

private:

    int                     jumpCounter;
    float                   maxFall;
    float                   runAcc;
    float                   jumpAcc;
    float                   maxJumpSpeed;
    float                   maxXSpeed;
    float                   maxAcc;

    sf::Vector2f            vel;
    sf::Vector2f            gravity;
    

    int                     jumpFrames;

    bool                    hitGround;
    bool                    hitSidesOrBelow;
    float                   hitTimer;

public:
    Gravity();
    ~Gravity();
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
    );


    sf::Vector2f            updateVelocity();
    sf::Vector2f            isOnGround();
    sf::Vector2f            isInAir();
    sf::Vector2f            movingLeft();
    sf::Vector2f            movingRight();
    sf::Vector2f            deAccelerate();
    void                    limitAcceleration();
    void                    setGroundBoolToTrue();
    void                    setBelowSidesBoolToTrue();

    void                    printBools();
    void                    printVelocity();

    



};





#endif
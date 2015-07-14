#if !defined(__CONST_H)
#define __CONST_H

#include <SFML/Graphics.hpp>

const int   WIDTH    = 640;			//Screen 
const int   HEIGHT   = 480;			//Screen 
const float B_WIDTH  = 15;			//Border
const float B_HEIGHT = 450;			//Border



const int	FPS      = 60;
const int  FRAMESKIP = 10;



static int jumpcounter = 0;
const float maxFall  = 0.5F;				//Max fall velocity
const float runAcc   = 0.001F;				//Running acceleration
const float jumpAcc  = -0.05F;				//Jump acceleration
const float maxSpeed = 0.30F;
const float maxAcc = -0.1;

static sf::Vector2f vel(0.f, 0.f);
static sf::Vector2f gravity(0.f, 0.003f);

const int jumpframes = 10;					//Number of frames to accelerate in


static bool hitGround = false;
static bool hitSidesOrBelow = false;
static float hitTimer = 5.0;

#endif
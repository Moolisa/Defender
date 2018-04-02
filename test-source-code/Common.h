#ifndef COMMON
#define COMMON
#include <cmath>
/**
 * @class COMMON
 * @author Moolisa
 * @author Sheena
 * @date 05/10/2015
 * @file Common.h
 * @brief This class contains all the common varriables used through out the program. These include the screen dimensions
 */
struct POSITION {
    float xPosition, yPosition;
};

enum class Direction { UP, DOWN, RIGHT, LEFT };

// spaceship specifications
const float SpaceshipWidth = 48;
const float SpaceshipHeight = 48;
//const float SpaceshipSpeed = 0.5;
// lander specifications
const float LanderWidth = 36;
const float LanderHeight = 36;
const float LanderSpeed = 0.1;
const double LanderMoveUpdateTime = 2;
// Laser specifications
const float LaserSpeed = 0.8;
const float LaserWidth = 11;
const float LaserHeight = 8;
//window boundaries
const float windowUpperBoundary = 100;
const float windowLowerBoundary = 880;
const float windowLestmostBoundary = 20;
const float windowRightmostBoundary = 1580;


#endif // COMMON-INCLUDED
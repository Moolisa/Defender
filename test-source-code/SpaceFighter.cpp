//============================================================================================
///                                     SPACEFIGHTER

#include "SpaceFighter.h"
#include <iostream>

using namespace std;

SpaceFighter::SpaceFighter()
{
    coord.xPosition = 750;
    coord.yPosition = 400;
}

POSITION SpaceFighter::getPosition()
{
    return coord;
}

void SpaceFighter::moveSpaceFighter(Direction dir)
{

    switch(dir) {
    case Direction::UP: {
        coord.yPosition -= SpaceshipSpeed;
        break;
    }

    case Direction::DOWN: {
        coord.yPosition += SpaceshipSpeed;
        break;
    }

    case Direction::RIGHT: {
        coord.xPosition += SpaceshipSpeed;
        break;
    }

    case Direction::LEFT: {
        coord.xPosition -= SpaceshipSpeed;
        break;
    }

    default:
        break;
    }

    if(coord.yPosition < windowUpperBoundary)
        coord.yPosition = windowUpperBoundary + 1;

    if(coord.yPosition > windowLowerBoundary)
        coord.yPosition = windowLowerBoundary - 1;

    if(coord.xPosition < windowLestmostBoundary)
        coord.xPosition = windowLestmostBoundary + 1;

    if(coord.xPosition > windowRightmostBoundary)
        coord.xPosition = windowRightmostBoundary - 1;
}

//============================================================================================
///                                     LANDERS

#include "Landers.h"
#include <iostream>

#include <ctime>

using namespace std;

Landers::Landers(int xPos, int yPos)
{
    coord.xPosition = xPos;
    coord.yPosition = yPos;
}

POSITION Landers::getPosition()
{
    return coord;
}

void Landers::moveLanders(int directionNumber)

{

    switch(directionNumber) {
    case 1: {
        coord.yPosition -= LanderSpeed;
        break;
    }

    case 2: {
        coord.yPosition += LanderSpeed;
        break;
    }

    case 3: {
        coord.xPosition += LanderSpeed;
        break;
    }

    case 4: {
        coord.xPosition -= LanderSpeed;
        break;
    }
    
    case 5: {
        coord.xPosition += LanderSpeed;
        coord.yPosition += LanderSpeed;
        break;
    }
    
    case 6: {
        coord.xPosition += LanderSpeed;
        coord.yPosition -= LanderSpeed;
        break;
    }
    
    case 7: {
        coord.xPosition -= LanderSpeed;
        coord.yPosition -= LanderSpeed;
        break;
    }
    
    case 8: {
        coord.xPosition -= LanderSpeed;
        coord.yPosition += LanderSpeed;
        break;
    }

    default:
        break;
    }
    
    if(coord.yPosition < windowUpperBoundary)
        coord.yPosition = windowUpperBoundary+1;
    
    if(coord.yPosition > windowLowerBoundary)
        coord.yPosition = windowLowerBoundary-1;
    
    if(coord.xPosition < windowLestmostBoundary) 
        coord.xPosition = windowLestmostBoundary+1;
        
    if(coord.xPosition > windowRightmostBoundary)
        coord.xPosition = windowRightmostBoundary-1;
}

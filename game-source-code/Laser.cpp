

#include "Laser.h"
#include "Common.h"

using namespace std;

Laser::Laser(int xPos, int yPos)
{
    coord.xPosition = xPos;
    coord.yPosition = yPos;
}

POSITION Laser::getPosition()
{
    return coord;
}

void Laser::moveLaser(Direction dir)
{
    switch(dir) {
    case Direction::LEFT: {
        coord.xPosition -= LaserSpeed;
        break;
    }

    case Direction::RIGHT: {
        coord.xPosition += LaserSpeed;
        break;
    }
    }
}
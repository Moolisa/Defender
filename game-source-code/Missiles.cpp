#include "Missiles.h"
#include "Common.h"

using namespace std;

Missiles::Missiles(POSITION spaceshipPos, POSITION landerPos)
{

    double deltaY = spaceshipPos.yPosition - landerPos.yPosition;
    double deltaX = spaceshipPos.xPosition - landerPos.xPosition;

    int incline; // =
    // determineInclination(spaceshipPos.xPosition,spaceshipPos.yPosition,landerPos.xPosition,landerPos.yPosition);

    if(spaceshipPos.xPosition > landerPos.xPosition && spaceshipPos.yPosition > landerPos.yPosition)
        incline = 1; // return 1;
    // Schoot diagonally down-right
    else if(spaceshipPos.xPosition < landerPos.xPosition && spaceshipPos.yPosition > landerPos.yPosition)
        incline = 3; // return 3;
    // shoot diagonally up-left
    else if(spaceshipPos.xPosition < landerPos.xPosition && spaceshipPos.yPosition < landerPos.yPosition)
        incline = 5; // return 5;
    // shoot diagonally up-right
    else if(spaceshipPos.xPosition > landerPos.xPosition && spaceshipPos.yPosition < landerPos.yPosition)
        incline = 7; // return 7;
    // shoot up
    else if(spaceshipPos.xPosition == landerPos.xPosition && spaceshipPos.yPosition > landerPos.yPosition)
        incline = 2; // return 2;
    // shoot right
    else if(spaceshipPos.xPosition < landerPos.xPosition && spaceshipPos.yPosition == landerPos.yPosition)
        incline = 4; // return 4;
    // shoot down
    else if(spaceshipPos.xPosition == landerPos.xPosition && spaceshipPos.yPosition < landerPos.yPosition)
        incline = 6; // return 6;
    // shoot left
    else if(spaceshipPos.xPosition > landerPos.xPosition && spaceshipPos.yPosition == landerPos.yPosition)
        incline = 8; // return 8;

    MissileInclination = incline; // determineInclination(POSITION spaceshipPos, POSITION landerPos);

    gradient = deltaY / deltaX;

//    if(abs(spaceshipPos.xPosition - landerPos.xPosition) < 200) {
//        missileSpeed = 0.02;
//    } else {
//        missileSpeed = 1;
    //}

        missileSpeed = 0.5;
    

    coord.xPosition = landerPos.xPosition;
    coord.yPosition = landerPos.yPosition;
}

POSITION Missiles::getPosition()
{
    return coord;
}

void Missiles::moveMissiles()
{
    switch(MissileInclination) {
    case 1: {
        coord.xPosition += missileSpeed;
        coord.yPosition += gradient * missileSpeed;
        break;
    }

    case 2: {
        coord.yPosition += missileSpeed;
        break;
    }

    case 3: {
        coord.xPosition += (-missileSpeed);
        coord.yPosition += (-gradient) * (missileSpeed);
        break;
    }

    case 4: {
        coord.xPosition -= missileSpeed;
        break;
    }

    case 5: {
        coord.xPosition += (-missileSpeed);
        coord.yPosition += gradient * (-missileSpeed);
        break;
    }

    case 6: {
        coord.yPosition -= missileSpeed;
        break;
    }

    case 7: {
        coord.xPosition += (missileSpeed);
        coord.yPosition += gradient * (missileSpeed);
        break;
    }
    }
}

//int determineInclination(float a,
//                         float b,
//                         float c,
//                         float d) // spaceshipPos.yPosition,landerPos.xPosition,landerPos.yPosition)//(POSITION
//                                  // spaceshipPos, POSITION landerPos)
//{

    //    if(spaceshipPos.xPosition > landerPos.xPosition && spaceshipPos.yPosition > landerPos.yPosition)
    //        return 1;
    //    // Schoot diagonally down-right
    //    else if(spaceshipPos.xPosition < landerPos.xPosition && spaceshipPos.yPosition > landerPos.yPosition)
    //        return 3;
    //    // shoot diagonally up-left
    //    else if(spaceshipPos.xPosition < landerPos.xPosition && spaceshipPos.yPosition < landerPos.yPosition)
    //        return 5;
    //    // shoot diagonally up-right
    //    else if(spaceshipPos.xPosition > landerPos.xPosition && spaceshipPos.yPosition < landerPos.yPosition)
    //        return 7;
    //    // shoot up
    //    else if(spaceshipPos.xPosition = landerPos.xPosition && spaceshipPos.yPosition > landerPos.yPosition)
    //        return 2;
    //    // shoot right
    //    else if(spaceshipPos.xPosition < landerPos.xPosition && spaceshipPos.yPosition = landerPos.yPosition)
    //        return 4;
    //    // shoot down
    //    else if(spaceshipPos.xPosition = landerPos.xPosition && spaceshipPos.yPosition < landerPos.yPosition)
    //        return 6;
    //    // shoot left
    //    else if(spaceshipPos.xPosition > landerPos.xPosition && spaceshipPos.yPosition = landerPos.yPosition)
    //        return 8;

//    if(a > c && b > d)
//        return 1;
//    // Schoot diagonally down-right
//    else if(a < c && b > d)
//        return 3;
//    // shoot diagonally up-left
//    else if(a < c && b < d)
//        return 5;
//    // shoot diagonally up-right
//    else if(a > c && b < d)
//        return 7;
//    // shoot up
//    else if(a == c && b > d)
//        return 2;
//    // shoot right
//    else if(a < c && b == d)
//        return 4;
//    // shoot down
//    else if(a == c && b < d)
//        return 6;
//    // shoot left
//    else if(a > c && b == d)
//        return 8;
//}

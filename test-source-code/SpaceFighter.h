#ifndef SPACEFIGHTER_H
#define SPACEFIGHTER_H
#include "Common.h"

using namespace std;

/**
 * @class SpaceFighter
 * @author Moolisa Tlali
 * @author Sheena Philip
 * @date 05/09/2015
 * @file SpaceFighter.h
 * @brief This class manages the Spaceship data and its movement responsibilities
 */

class SpaceFighter
{
public:
    /**
     * @brief  Constructor that initialises the spaceship's x and y position.
     */
    SpaceFighter();
    /**
     * @brief  function used to access the class' private data member (coord) which is a struct
               containing the x and y coordinates.
     * @return a struct that contains the x and y coordinates of the spaceship.
     */
    POSITION getPosition();

    /**
     * @brief By making use of the strongly typed direction enumeration, moveSpaceFighter moves the spaceship
     *        in a four directions; either vertically UP or Down or horizontally to the RIGHT or to the LEFT.
     *        The private data member SpaceshipSpeed determines the number of pixel increments per frame.
     * @param dir: is a strongly typed enumeration that is used to determine the direction in which
              the spaceship should move
     */
    void moveSpaceFighter(Direction dir);

private:
    POSITION coord;
    const float SpaceshipSpeed = 0.5;
};

#endif
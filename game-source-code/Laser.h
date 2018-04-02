#ifndef LASER_H
#define LASER_H
#include "Common.h"

/**
 * @class Laser
 * @author Moolisa, Sheena
 * @date 02/10/2015
 * @file Laser.h
 * @brief This class manages the lasers which are shot from the spaceship. It sets their intial position and 
 *        manages how they must move.
 */
class Laser
{
public:
    /**
     * @brief This function is the constructor for this class. It sets the x and y Posistion of each laser object
              to the position of the spaceship at the point at which the laser is created.
     * @param xPos is an interger x coordinate value of the spaceship at the point of laser creation 
     * @param xPos is an interger y coordinate value of the spaceship at the point of laser creation
     */
    Laser(int xPos, int yPos);

    /**
     * @brief By making use of the strongly typed direction enumeration as argument, movelaser function limits the movement   
     *        of  the laser object to two directions i.e. either horizontally to the RIGHT or horizontally to the LEFT.
     * @param dir: is a strongly typed enumeration that is used to determine the direction to which the laser should move.
     */
    void moveLaser(Direction dir);
    /**
     * @brief  function used to access the class' private data member (coord) which is a struct
               containing the x and y coordinates.
     * @return a struct that contains the x and y coordinates of the laser.
     */
    POSITION getPosition();

private:
    POSITION coord;
    //const float LaserSpeed = 0.8;
};

#endif
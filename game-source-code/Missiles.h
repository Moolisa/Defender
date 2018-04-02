#ifndef MISSILES_H
#define MISSILES_H
#include "Common.h"
#include <cmath>

/**
 * @class Missiles
 * @author Moolisa Tlali
 * @author Sheena Philip
 * @date 14/09/2015
 * @file Missiles.h
 * @brief This class manages the missiles which are shot from the landers. It sets the missile's intial position and
 *        manages how it must move.
 */
class Missiles
{
public:
    /**
     * @brief This function is the constructor for this class. It sets the x and y Posistion of a missile object
              to the position of the lander at the point at which the missile is created. The private data member 
              missileInclination defines the position of the missile (upon creation) with respect to the position of 
              the spaceship e.g. MissileInclination 1 corresponds to creating a missile from a lander positioned TOP-LEFT  
              to the spacefighter. This inclination determines a movement direction for the missile and a combination of  
              data members gradient and missileSpeed is used to direct the movement of the missile towards the spaceship. 
              The missile maintains this route until it is rendered to be out of scope.
     * @param spaceshipPos is a struct containing x and y coordinate of the spaceship at the point of missile creation
     * @param landerPos is a struct containing the x and y coordinate of the lander at the point of missile creation.  
              These also make up the initial position of the missile.
    */
    Missiles(POSITION spaceshipPos, POSITION landerPos);
    /**
     * @brief By making use of the pre-determined data members (MissileInclination, gradient and the constant missileSpeed) 
              moveMissile function uses a ratio based method to set the path movement of the missile such that it moves directly
              towards the spaceship. The spaceship position can change in time but the missile will continue to move in this set path 
              until the missile is rendered out of scope.This is achieved by incrementing or decrementing the x coordinate of the 
              missile by a missileSpeed then scaling the missileSpeed by the radient and incrementing or decrementing the y coordinate 
              of the missile by this scale. This ensures that the missile can be shot from any position around the spaceship. This
              function does not take parameters because it uses the set data members.
     */
    void moveMissiles();

    /**
     * @brief function used to access the class' private data member (coord) which is a struct
              containing the x and y coordinates.
     * @return a struct that contains the x and y coordinates of the missile.
     */
    POSITION getPosition();

//    /**
//     * @brief
//     * @return
//     */
    //int determineInclination(float&, float&, float&, float&);

private:
    POSITION coord;
    int MissileInclination;
    double missileSpeed;
    double gradient;
};

#endif
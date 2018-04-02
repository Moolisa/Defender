#ifndef COLLISION_H
#define COLLISION_H
#include <iostream>
#include "Common.h"
using namespace std;

/**
 * @class collision
 * @author Moolisa Tlali
 * @author Sheena Philip
 * @date 02/10/2015
 * @file collision.h
 * @brief The class handles all the collisions between all entities of the game.
          This includes collisions between Spaceship and lander's missiles, between 
          Spaceship and Landers, between spaceship's laser and lander's missile 
          and between laser and lander.
          
 */
class collision
{
public:
    collision();

    /**
     * @brief checkCollision determines a collision between two movable entities. It is a general function 
     *        for all entities. It assumes each entity as rectangular in shape thus each entity has a width
     *        and a height. The Algorithm is based on detecting whether the edges (width and height) of the  
     *        rectangular entities have collided.
     * @param entity1 (one of the entities to be checked for collision)
     * @param entity2 (One of the entities to be checked for collision) 
     * @param entity1Width  (The width of the 1st rectangular entity)
     * @param entity1Height (the height of the 1st rectangular entity)
     * @param entity2Width  (The width of the 2nd rectangular entity) 
     * @param entity2Height (The height of the 2nd rectangular entity)
     * @return boolian true if a collision between the entities has occured, false otherwise
     */
    bool checkCollision(POSITION entity1,
                        POSITION entity2,
                        const float& entity1Width,
                        const float& entity1Height,
                        const float& entity2Width,
                        const float& entity2Height);
private:
};

#endif

#ifndef LANDERS_H
#define LANDERS_H
#include "Common.h"

using namespace std;
/**
 * @class Landers
 * @author Moolisa Tlali
 * @author Sheena Philip
 * @date 08/09/2015
 * @file Landers.h
 * @brief The purpose of this class is to make the landers teleport to positions around the player's spaceship and
 *        move each lander in a random direction  
 */
class Landers
{
public:
    /**
     * @brief This function is the constructor for this class. It sets the random x and y Posistion of each lander object. 
     * @param xPos is a random interger x coordinate value of the lander 
     * @param xPos is a random interger y coordinate value of the lander 
     */
    Landers(int xPos, int yPos);
    
    /**
     * @brief This function gets the position of a lander
     * @return a struct containing x and y position of a lander
     */
    POSITION getPosition();
    
    /**
     * @brief This function takes in a number that defines how the lander must move. The lander can move in 8 diffent directions 
     * @param directionNumber : A number that corresponds to a movement direction of the lander eg. 1-corresponds to moving up
     */
    void moveLanders(int directionNumber);

private:
    POSITION coord;
};

#endif
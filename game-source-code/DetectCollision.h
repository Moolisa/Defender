#ifndef DETECTCOLLISION_H
#define DETECTCOLLISION_H
#include <vector>
#include "Common.h"
#include "Landers.h"
#include "collision.h"
#include "Display.h"
#include "Laser.h"
#include "Missiles.h"

using namespace std;
/**
 * @class DetectCollision
 * @author Moolisa
 * @author Sheena
 * @date 03/10/2015
 * @file DetectCollision.h
 * @brief The purpose of this class is to run through and match all the objects that need to be passed into the class
* Collision.If a collision is returned the class deletes the associated objects or sets the status of the game to
* finished.
 */
class DetectCollision
{
public:
    /**
     * @brief This function is the constructor for the class. It does not perform any specific action
     */
    DetectCollision();
    /**
     * @brief @brief This function passes each lander's current posistion and the spaceship's posistion into the
    * collision class to detect collision. If a collision is returned, the function calls the end game function.
     * @param spaceshipPos The Spaceships current posistion
     * @param enemyVector a vector of type Landers
     * @param _window SFML window object
     */
    void
    detectCollisionsLanderAndSpaceship(POSITION& spaceshipPos, vector<Landers>& enemyVector, sf::RenderWindow& _window);
    /**
     *@brief This function runs through the Lander and the laser vector to get the various objects and their current
    * posistions and passes this into the collision class to detect
    * collision.If a collision is returned the asscociated Lander object is deleted.If all all lander objects are
    * deleted the function calls the end game function.
     * @param enemyVector a vector of Lander objects
     * @param laserVector a vector Lasers objects
     * @param laserSpriteVector a vector of laser sprites
     * @param laserDirections a vector stating the direction of each laser
     * @param enemySprite a vector lander sprites
     * @param destroyedEnemiesCounter keeps count of how many landers have been destroyed
     * @param _window SFML window object
     */
    void detectCollisionsLaserAndLander(vector<Landers>& enemyVector,
                                        vector<Laser>& laserVector,
                                        vector<sf::Sprite>& laserSpriteVector,
                                        vector<Direction>& laserDirections,
                                        vector<sf::Sprite>& enemySprite,
                                        int& destroyedEnemiesCounter,
                                        sf::RenderWindow& _window);
    /**
     * @brief This function runs through the Missile vector to get the various objects and their current
    * positions and passes this and Spaceships current position into the collision class to detect
    * collision.If a collision is returned the function calls the end game function.
     * @param missileVector a vector of Missile objects
     * @param spaceshipPos The Spaceships current posistion
     * @param _window SFML window object
     */
    void detectCollisionsMissileAndSpaceShip(vector<Missiles>& missileVector,
                                             POSITION& spaceshipPos,
                                             sf::RenderWindow& _window);

private:
    collision collisionCheck;
    // Display drawing2;
    int gamestatus = 0;
};

#endif
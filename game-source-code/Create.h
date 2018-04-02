#ifndef CREATE_H
#define CREATE_H
#include <vector>
#include "Common.h"
#include "Laser.h"
//#include "Game.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Landers.h"
#include "SpaceFighter.h"
#include "Missiles.h"

using namespace std;
/**
 * @class Create
 * @author Moolisa Tlali
 * @author Sheena Philip
 * @date 02/09/2015
 * @file Create.h
 * @brief The purpose of this class is to create and populate object vectors and sprite vectors.This includes an enemy
* vector,lander sprite vector,a laser vector,a laser sprite vector, a missile vector and a missile sprite vector.
 */
class Create
{
public:
    /**
     * @brief Constrictor without specific action
     */
    Create();
    /**
     * @brief Function that populates lander vector with lander objects
     * @param enemyVector (Vector of landers)
     * @param enemySprite (Vectoe of lander sprites)
     * @param createdEnemiesCounter (counter to keep track of the number of Landers that are created)
     * @param numberOfLandersVector (vector equal to the size of enemies vector. It is used to store
     * random number to determine the random movement of each lander)
     */
    void creatingEnemyVector(vector<Landers>& enemyVector,
                             vector<sf::Sprite>& enemySprite,
                             int& createdEnemiesCounter,
                             vector<int>& numberOfLandersVector);
    /**
     * @brief This function populates a vector with lander sprites as a lander object is created
     * @param enemySprite   vector of type Landers Sprite
     * @param enemyVector   a vector of type Landers
     */
    void CreateLanderSprites(vector<sf::Sprite>& enemySprite, vector<Landers>& enemyVector);
    /**
     * @brief Function that obtains the amount of time that has passed since the program started executing. It is uded
    to obtain time at different points in the game so that creation of landers and their shooting is timed.
     * @return type double of the time in seconds since the beginning of program execusion.
     */
    double getProcessTime();
    /**
     * @brief This function fills a vector with laser objects
     * @param spaceshipShoots (tells whether a player has pressed the spacebar to shoot)
     * @param spaceshipDirectionLeft (tells whether spaceship is facing left)
     * @param spaceshipFireInterval (a minimum interval between which spaceship can fire)
     * @param spaceshipFireTime (time at which previous laser was fired)
     * @param laserVector (a vector which will/does contain laser objects)
     * @param laserDirections (a vector which states what direction each laser should move in)
     * @param laserSpriteVector ( vector of laser sprites)
     * @param playerPosition (struct of positon of the player)
     */
    void createLaser(bool& spaceshipShoots,
                     bool& spaceshipDirectionLeft,
                     double& spaceshipFireInterval,
                     double& spaceshipFireTime,
                     vector<Laser>& laserVector,
                     vector<Direction>& laserDirections,
                     vector<sf::Sprite>& laserSpriteVector,
                     POSITION& playerPosition);
    /**
     * @brief
     * @param laserSpriteVector
     * @param playerPosition
     */
    void createLaserSprite(vector<sf::Sprite>& laserSpriteVector, POSITION& playerPosition);
    /**
     * @brief This function fills a vector with laser sprites as a laser object is created
     * @param spaceshipPos (struct with Possition of the spaceship)
     * @param enemyVector (vector of landers)
     * @param missileVector (vector of missiles)
     * @param missileSpriteVector (vector of missile sprites)
     */
    void createMissiles(POSITION& spaceshipPos,
                        vector<Landers>& enemyVector,
                        vector<Missiles>& missileVector,
                        vector<sf::Sprite>& missileSpriteVector);
    /**
     * @brief This function fills a vector with missile sprites as a missile object is created
     * @param missileSpriteVector (a vector of type missile Sprite)
     * @param missilePosition (position missile object must be set to)
     */
    void createMissilesSprite(vector<sf::Sprite>& missileSpriteVector, POSITION& missilePosition);

private:
    sf::Texture enemy;
    sf::Texture bullet;
    sf::Texture missile;
    double time1;
    double createEnemyInterval = 5;
};

#endif
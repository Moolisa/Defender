#include "DetectCollision.h"

// POSITION spaceshipPos = player.getPosition();
Display drawing2;
DetectCollision::DetectCollision()
{
}

void DetectCollision::detectCollisionsLanderAndSpaceship(POSITION& spaceshipPos,
                                                         vector<Landers>& enemyVector,
                                                         sf::RenderWindow& _window)
{
    // POSITION spaceshipPos = player.getPosition();
    for(int i = 0; i < enemyVector.size(); i++) {
        POSITION landerPos = enemyVector[i].getPosition();
        if(collisionCheck.checkCollision(
               spaceshipPos, landerPos, SpaceshipWidth, SpaceshipHeight, LanderWidth, LanderHeight)) {
            gamestatus = 0;
            drawing2.EndGame(_window, gamestatus);
        }
    }
}

void DetectCollision::detectCollisionsLaserAndLander(vector<Landers>& enemyVector,
                                                     vector<Laser>& laserVector,
                                                     vector<sf::Sprite>& laserSpriteVector,
                                                     vector<Direction>& laserDirections,
                                                     vector<sf::Sprite>& enemySprite,
                                                     int& destroyedEnemiesCounter,
                                                     sf::RenderWindow& _window)
{

    for(int i = 0; i < enemyVector.size(); i++) {
        POSITION landerPos = enemyVector[i].getPosition();
        for(int j = 0; j < laserVector.size(); j++) {
            POSITION laserPos = laserVector[j].getPosition();
            if(collisionCheck.checkCollision(landerPos, laserPos, LanderWidth, LanderHeight, LaserWidth, LaserHeight)) {
                laserSpriteVector.erase(laserSpriteVector.begin() + j);
                laserVector.erase(laserVector.begin() + j);
                laserDirections.erase(laserDirections.begin() + j);
                enemySprite.erase(enemySprite.begin() + i);
                enemyVector.erase(enemyVector.begin() + i);
                destroyedEnemiesCounter++;

                if(destroyedEnemiesCounter == 15) {
                    gamestatus = 1;
                    //drawing2.EndGame(_window, gamestatus);
                }
            }
        }
    }
}

void DetectCollision::detectCollisionsMissileAndSpaceShip(vector<Missiles>& missileVector,
                                                          POSITION& spaceshipPos,
                                                          sf::RenderWindow& _window)
{
    for(int i = 0; i < missileVector.size(); i++) {
        POSITION missilePos = missileVector[i].getPosition();

        if(collisionCheck.checkCollision(
               spaceshipPos, missilePos, SpaceshipWidth, SpaceshipHeight, LaserWidth, LaserHeight)) {

            gamestatus = 0;
            drawing2.EndGame(_window, gamestatus);
        }
    }
}

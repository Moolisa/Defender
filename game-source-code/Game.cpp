#include "Game.h"
#include "SpaceFighter.h"
#include "Missiles.h"
#include "Landers.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

using namespace std;

DetectCollision collide;
Display drawing;
Game::Game()

    : window(sf::VideoMode(1600, 900), "DEFENDER Version 1.2", sf::Style::Titlebar | sf::Style::Close)

    , spaceshipDirectionLeft{ true }
    , spaceshipShoots{ false }
    //, enemyvectorHasElement{ true }
{
    if(!spaceFighter.loadFromFile("spaceShip.png"))
        throw couldNotLoadFighterFromFile();

    spriteSpaceship.setOrigin(24, 24);
    spriteSpaceship.setTexture(spaceFighter);
    spriteSpaceship.setPosition(750.f, 400.f);
    spriteSpaceship.rotate(-90);
}

void Game::run()
{
    while(window.isOpen()) {
        keys.processEvents(window);
        update();
        render();
    }
}

void Game::update()
{
    SpaceFighterUpdate();
    EnemyUpdate();
    LaserUpdate();
    MissilesUpdate();
    detectCollisions();
}

void Game::render()
{

    drawing.DrawSprites(window, spriteSpaceship, enemySprite, laserSpriteVector, missileSpriteVector);
}

void Game::SpaceFighterUpdate()
{
    POSITION PlayerPosition = player.getPosition();

    if(PlayerPosition.yPosition >= windowUpperBoundary && PlayerPosition.yPosition <= windowLowerBoundary) {

        if(keys.isMovingUp())
            player.moveSpaceFighter(Direction::UP);

        else if(keys.isMovingDown())
            player.moveSpaceFighter(Direction::DOWN);

        else if(keys.isMovingLeft()) {
            if(!spaceshipDirectionLeft) {     // if spaceship is not facing left
                spriteSpaceship.rotate(-180); // rotate it
                spaceshipDirectionLeft = true;
            }
            player.moveSpaceFighter(Direction::LEFT);
        }

        else if(keys.isMovingRight()) {
            if(spaceshipDirectionLeft)        // if spaceship is facing left
                spriteSpaceship.rotate(-180); // rotate it
            spaceshipDirectionLeft = false;
            player.moveSpaceFighter(Direction::RIGHT);
        }
    }

    spriteSpaceship.setPosition(PlayerPosition.xPosition, PlayerPosition.yPosition);
    
    spaceshipFireInterval = enemyMoveTime - spaceshipFireTime;
    spaceshipShoots = keys.SpaceshipFires();
    creation.createLaser(spaceshipShoots,
                         spaceshipDirectionLeft,
                         spaceshipFireInterval,
                         spaceshipFireTime,
                         laserVector,
                         laserDirections,
                         laserSpriteVector,
                         PlayerPosition);
}

void Game::EnemyUpdate()
{
    creation.creatingEnemyVector(enemyVector, enemySprite, createdEnemiesCounter, numberOfLandersVector);
    if(enemyMoveInterval > LanderMoveUpdateTime) {
        for(int i = 0; i < enemyVector.size(); i++) {
            int directionNumber = 1 + (rand() % 8);

            numberOfLandersVector[i] = directionNumber;
        }

        initialTime = getProcessTime();
    }

    enemyMoveTime = getProcessTime();
    enemyMoveInterval = enemyMoveTime - initialTime;

    for(int i = 0; i < enemySprite.size(); i++) {
        enemyVector[i].moveLanders(numberOfLandersVector[i]);

        POSITION newPosition4 = enemyVector[i].getPosition();
        enemySprite[i].setPosition(newPosition4.xPosition, newPosition4.yPosition);
    }

    enemyShoot();
}

void Game::enemyShoot()
{
    enemyShootInterval = enemyMoveTime - enemyFireTime;
    if(enemyShootInterval > 2) {

        POSITION spaceshipPos = player.getPosition();
        creation.createMissiles(spaceshipPos, enemyVector, missileVector, missileSpriteVector);
        enemyFireTime = getProcessTime();
    }

    enemyShootInterval = enemyMoveTime - spaceshipFireTime;
}

void Game::LaserUpdate()
{
    for(int i = 0; i < laserVector.size(); i++) {
        laserVector[i].moveLaser(laserDirections[i]);

        POSITION laserNewPosition = laserVector[i].getPosition();
        laserSpriteVector[i].setPosition(laserNewPosition.xPosition, laserNewPosition.yPosition);

        if(laserVector.size() != 0 && laserNewPosition.xPosition > 1600 ||
           laserNewPosition.xPosition < 0) { // add no collisions
            laserSpriteVector.erase(laserSpriteVector.begin() + i);
            laserVector.erase(laserVector.begin() + i);
            laserDirections.erase(laserDirections.begin() + i);
        }
    }
}

void Game::MissilesUpdate()
{

    for(int i = 0; i < missileVector.size(); i++) {
        missileVector[i].moveMissiles(); // laserDirections[i]);

        POSITION missileNewPosition = missileVector[i].getPosition();
        missileSpriteVector[i].setPosition(missileNewPosition.xPosition, missileNewPosition.yPosition);

        if(missileVector.size() != 0 && missileNewPosition.xPosition > 1600 || missileNewPosition.xPosition < 0 ||
           missileNewPosition.yPosition < windowUpperBoundary ||
           missileNewPosition.yPosition > windowLowerBoundary) { // add no collisions
            missileSpriteVector.erase(missileSpriteVector.begin() + i);
            missileVector.erase(missileVector.begin() + i);
        }
    }
}

double Game::getProcessTime()
{
    clock_t time = clock();
    return static_cast<double>(time) / CLOCKS_PER_SEC;
}

void Game::detectCollisions()
{
   POSITION spaceshipPos = player.getPosition();
        collide.detectCollisionsLanderAndSpaceship(spaceshipPos, enemyVector, window);
        collide.detectCollisionsLaserAndLander(
            enemyVector, laserVector, laserSpriteVector, laserDirections, enemySprite, destroyedEnemiesCounter, window);

        collide.detectCollisionsMissileAndSpaceShip(missileVector, spaceshipPos, window); 
}

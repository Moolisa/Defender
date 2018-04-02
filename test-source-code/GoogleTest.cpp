//============================================================================================
///                                     GOOGLE-TEST
//
////Developed by: SHEENA PHILIP ()
////              MOOLISA TLALI (564988)
//
////Date: 06-SEPTEMBER-2015
//============================================================================================

#include "SpaceFighter.h"
#include "collision.h"
#include "Common.h"
#include "Landers.h"
#include <gtest/gtest.h>
#include <iostream>
#include "Laser.h"
#include "Missiles.h"
#include "Keyboard.h"
#include <SFML/Graphics.hpp>

using namespace std;

// Test if the spaceship is positioned correctly on the screen
TEST(SpaceFighter, checkXPositionOfSpapceFighter)
{
    SpaceFighter spaceFighter;
    POSITION testCoord;
    testCoord.xPosition = 750;
    POSITION spaceps = spaceFighter.getPosition();
    EXPECT_TRUE(spaceps.xPosition == testCoord.xPosition);
}

TEST(SpaceFighter, checkYPositionOfSpapceFighter)
{
    SpaceFighter spaceFighter;
    POSITION testCoord;
    testCoord.yPosition = 400;
    POSITION spaceps = spaceFighter.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testCoord.yPosition);
}

// These test the correct movements of the spacefighter
// TEST UPWARDMOVEMENT
TEST(SpaceFighter, moveSpaceshipUpwards)
{
    SpaceFighter spaceFighter;
    spaceFighter.moveSpaceFighter(Direction::UP);
    POSITION testYposition;
    testYposition.yPosition = 399.5;
    POSITION spaceps = spaceFighter.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testYposition.yPosition);
}

// TEST DOWNWARDMOVEMENT
TEST(SpaceFighter, moveSpaceshipDownwards)
{
    SpaceFighter spaceFighter;
    spaceFighter.moveSpaceFighter(Direction::DOWN);
    POSITION testYposition;
    testYposition.yPosition = 400.5;
    POSITION spaceps = spaceFighter.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testYposition.yPosition);
}

// TEST RIGHTMOVEMENT
TEST(SpaceFighter, moveSpaceshipToRight)
{
    SpaceFighter spaceFighter;
    spaceFighter.moveSpaceFighter(Direction::RIGHT);
    POSITION testXposition;
    testXposition.xPosition = 750.5;
    POSITION spaceps = spaceFighter.getPosition();
    EXPECT_TRUE(spaceps.xPosition == testXposition.xPosition);
}

// TEST LEFTMOVEMENT
TEST(SpaceFighter, moveSpaceshipToLeft)
{
    SpaceFighter spaceFighter;
    spaceFighter.moveSpaceFighter(Direction::LEFT);
    POSITION testXposition;
    testXposition.xPosition = 749.5;
    POSITION spaceps = spaceFighter.getPosition();
    EXPECT_TRUE(spaceps.xPosition == testXposition.xPosition);
}

// TEST LANDERMOVEMENTS
TEST(Landers, moveLanderUpwards)
{
    Landers lander(700,400);
    lander.moveLanders(1);
    POSITION testYposition;
    testYposition.yPosition = 399.9;
    POSITION spaceps = lander.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testYposition.yPosition);
}

TEST(Landers, moveLanderDownwards)
{
    Landers lander(700,400);
    lander.moveLanders(2);
    POSITION testYposition;
    testYposition.yPosition = 400.1;
    POSITION spaceps = lander.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testYposition.yPosition);
}

TEST(Landers, moveLanderRight)
{
    Landers lander(700,400);
    lander.moveLanders(3);
    POSITION testPosition;
    testPosition.xPosition = 700.1;
    testPosition.yPosition = 400;
    POSITION spaceps = lander.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testPosition.yPosition && spaceps.xPosition == testPosition.xPosition);
}

TEST(Landers, moveLanderLeft)
{
    Landers lander(700,400);
    lander.moveLanders(4);
    POSITION testPosition;
    testPosition.xPosition = 699.9;
    testPosition.yPosition = 400;
    POSITION spaceps = lander.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testPosition.yPosition && spaceps.xPosition == testPosition.xPosition);
}

TEST(Landers, moveDownRight)
{
    Landers lander(700,400);
    lander.moveLanders(5);
    POSITION testPosition;
    testPosition.xPosition = 700.1;
    testPosition.yPosition = 400.1;
    POSITION spaceps = lander.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testPosition.yPosition && spaceps.xPosition == testPosition.xPosition);
}

TEST(Landers, moveUpRight)
{
    Landers lander(700,400);
    lander.moveLanders(6);
    POSITION testPosition;
    testPosition.xPosition = 700.1;
    testPosition.yPosition = 399.9;
    POSITION spaceps = lander.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testPosition.yPosition && spaceps.xPosition == testPosition.xPosition);
}

TEST(Landers, moveUpLeft)
{
    Landers lander(700,400);
    lander.moveLanders(7);
    POSITION testPosition;
    testPosition.xPosition = 699.9;
    testPosition.yPosition = 399.9;
    POSITION spaceps = lander.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testPosition.yPosition && spaceps.xPosition == testPosition.xPosition);
}

TEST(Landers, moveDownLeft)
{
    Landers lander(700,400);
    lander.moveLanders(8);
    POSITION testPosition;
    testPosition.xPosition = 699.9;
    testPosition.yPosition = 400.1;
    POSITION spaceps = lander.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testPosition.yPosition && spaceps.xPosition == testPosition.xPosition);
}

TEST(Landers, TestLanderMovingBeyondRightBoundary)
{
    Landers lander(1580,400);
    lander.moveLanders(3);
    POSITION testPosition;
    testPosition.xPosition = 1579;
    testPosition.yPosition = 400;
    POSITION spaceps = lander.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testPosition.yPosition && spaceps.xPosition == testPosition.xPosition);
}

TEST(Landers, TestLanderMovingBeyondLeftBoundary)
{
    Landers lander(20,400);
    lander.moveLanders(4);
    POSITION testPosition;
    testPosition.xPosition = 21;
    testPosition.yPosition = 400;
    POSITION spaceps = lander.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testPosition.yPosition && spaceps.xPosition == testPosition.xPosition);
}

TEST(Landers, TestLanderMovingBeyondTopBoundary)
{
    Landers lander(100,100);
    lander.moveLanders(1);
    POSITION testPosition;
    testPosition.xPosition = 100;
    testPosition.yPosition = 101;
    POSITION spaceps = lander.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testPosition.yPosition && spaceps.xPosition == testPosition.xPosition);
}

TEST(Landers, TestLanderMovingBeyondBottomBoundary)
{
    Landers lander(100,880);
    lander.moveLanders(1);
    POSITION testPosition;
    testPosition.xPosition = 100;
    testPosition.yPosition = 879.9;
    POSITION spaceps = lander.getPosition();
    EXPECT_TRUE(spaceps.yPosition == testPosition.yPosition && spaceps.xPosition == testPosition.xPosition);
}



//TEST LASER
TEST(Laser, moveLaserLeft)
{
    Laser lasers(700,400);
    lasers.moveLaser(Direction::LEFT);
    POSITION testYposition;
    testYposition.yPosition = 400;
    testYposition.xPosition = 699.2;
    POSITION laserPos = lasers.getPosition();
    EXPECT_TRUE(laserPos.yPosition == testYposition.yPosition && laserPos.xPosition == testYposition.xPosition);
}

TEST(Laser, moveLaserRight)
{
    Laser lasers(700,400);
    lasers.moveLaser(Direction::RIGHT);
    POSITION testYposition;
    testYposition.yPosition = 400;
    testYposition.xPosition = 700.8;
    POSITION laserPos = lasers.getPosition();
    EXPECT_TRUE(laserPos.yPosition == testYposition.yPosition && laserPos.xPosition == testYposition.xPosition);
}

TEST(Laser, LaserDoesNotMoveUp)
{
    Laser lasers(700,400);
    lasers.moveLaser(Direction::UP);
    POSITION testYposition;
    testYposition.yPosition = 399.2;
    testYposition.xPosition = 700;
    POSITION laserPos = lasers.getPosition();
    EXPECT_FALSE(laserPos.yPosition == testYposition.yPosition && laserPos.xPosition == testYposition.xPosition);
}

TEST(Laser, LaserDoesNotMoveDown)
{
    Laser lasers(700,400);
    lasers.moveLaser(Direction::UP);
    POSITION testYposition;
    testYposition.yPosition = 400;
    testYposition.xPosition = 700;
    POSITION laserPos = lasers.getPosition();
    EXPECT_TRUE(laserPos.yPosition == testYposition.yPosition && laserPos.xPosition == testYposition.xPosition);
}

TEST(Missiles, TestingMissleCase1)
{
    SpaceFighter spaceShip;
    Landers lander(650,200);
    POSITION spaceshipPos=spaceShip.getPosition();
    POSITION landerPos=lander.getPosition();
    Missiles missile(spaceshipPos,landerPos);
    missile.moveMissiles();
    POSITION MissilePos=missile.getPosition();
    EXPECT_TRUE(MissilePos.xPosition==650.5 && MissilePos.yPosition==201);
    
}

TEST(Missiles, TestingMissleCase2)
{
    SpaceFighter spaceShip;
    Landers lander(750,200);
    POSITION spaceshipPos=spaceShip.getPosition();
    POSITION landerPos=lander.getPosition();
    Missiles missile(spaceshipPos,landerPos);
    missile.moveMissiles();
    POSITION MissilePos=missile.getPosition();
    EXPECT_TRUE(MissilePos.xPosition==750 && MissilePos.yPosition==200.5);
    
}

TEST(Missiles, TestingMissleCase3)
{
    SpaceFighter spaceShip;
    Landers lander(850,200);
    POSITION spaceshipPos=spaceShip.getPosition();
    POSITION landerPos=lander.getPosition();
    Missiles missile(spaceshipPos,landerPos);
    missile.moveMissiles();
    POSITION MissilePos=missile.getPosition();
    EXPECT_TRUE(MissilePos.xPosition==849.5 && MissilePos.yPosition==201);
}

TEST(Missiles, TestingMissleCase4)
{
    SpaceFighter spaceShip;
    Landers lander(850,400);
    POSITION spaceshipPos=spaceShip.getPosition();
    POSITION landerPos=lander.getPosition();
    Missiles missile(spaceshipPos,landerPos);
    missile.moveMissiles();
    POSITION MissilePos=missile.getPosition(); 
    EXPECT_TRUE(MissilePos.xPosition==849.5 && MissilePos.yPosition==400);
}

TEST(Missiles, TestingMissleCase5)
{
    SpaceFighter spaceShip;
    Landers lander(850,600);
    POSITION spaceshipPos=spaceShip.getPosition();
    POSITION landerPos=lander.getPosition();
    Missiles missile(spaceshipPos,landerPos);
    missile.moveMissiles();
    POSITION MissilePos=missile.getPosition();
    EXPECT_TRUE(MissilePos.xPosition==849.5 && MissilePos.yPosition==599);
    
}

TEST(Missiles, TestingMissleCase6)
{
    SpaceFighter spaceShip;
    Landers lander(750,800);
    POSITION spaceshipPos=spaceShip.getPosition();
    POSITION landerPos=lander.getPosition();
    Missiles missile(spaceshipPos,landerPos);
    missile.moveMissiles();
    POSITION MissilePos=missile.getPosition();;
    EXPECT_TRUE(MissilePos.xPosition==750 && MissilePos.yPosition==799.5);
    
}

TEST(Missiles, TestingMissleCase7)
{
    SpaceFighter spaceShip;
    Landers lander(650,500);
    POSITION spaceshipPos=spaceShip.getPosition();
    POSITION landerPos=lander.getPosition();
    Missiles missile(spaceshipPos,landerPos);
    missile.moveMissiles();
    POSITION MissilePos=missile.getPosition();
    EXPECT_TRUE(MissilePos.xPosition==650.5 && MissilePos.yPosition==499.5);
    
}

TEST(Missiles, TestingMissleCase8)
{
    SpaceFighter spaceShip;
    Landers lander(650,400);
    POSITION spaceshipPos=spaceShip.getPosition();
    POSITION landerPos=lander.getPosition();
    Missiles missile(spaceshipPos,landerPos);
    missile.moveMissiles();
    POSITION MissilePos=missile.getPosition();
    EXPECT_TRUE(MissilePos.xPosition==650 && MissilePos.yPosition==400);
    
}


// TEST COLLISIONS
TEST(collision,TestingCollisionFromRight)
{
    SpaceFighter spaceFighter;
    POSITION spaceshipPos = spaceFighter.getPosition();
    Landers lander(spaceshipPos.xPosition+(SpaceshipWidth/2), spaceshipPos.yPosition);
    POSITION landerPos = lander.getPosition();
    collision collideTest;
    EXPECT_TRUE(collideTest.checkCollision(spaceshipPos, landerPos, SpaceshipWidth, SpaceshipHeight, LanderWidth, LanderHeight));                               
}
//
TEST(collision,TestingCollisionFromLeft)
{
    SpaceFighter spaceFighter;
    POSITION spaceshipPos = spaceFighter.getPosition();
    Landers lander(spaceshipPos.xPosition-(SpaceshipWidth/2), spaceshipPos.yPosition);
    POSITION landerPos = lander.getPosition();
    collision collideTest;
    EXPECT_TRUE(collideTest.checkCollision(spaceshipPos, landerPos, SpaceshipWidth, SpaceshipHeight, LanderWidth, LanderHeight));
}
//
TEST(collision,TestingCollisionFromBottom)
{
    SpaceFighter spaceFighter;
    POSITION spaceshipPos = spaceFighter.getPosition();
    Landers lander(spaceshipPos.xPosition, spaceshipPos.yPosition+(SpaceshipWidth/2));
    POSITION landerPos = lander.getPosition();
    collision collideTest;
    EXPECT_TRUE(collideTest.checkCollision(spaceshipPos, landerPos, SpaceshipWidth, SpaceshipHeight, LanderWidth, LanderHeight));
}
//
TEST(collision,TestingCollisionFromTop)
{
    SpaceFighter spaceFighter;
    POSITION spaceshipPos = spaceFighter.getPosition();
    Landers lander(spaceshipPos.xPosition, spaceshipPos.yPosition-(SpaceshipWidth/2));
    POSITION landerPos = lander.getPosition();
    collision collideTest;
    EXPECT_TRUE(collideTest.checkCollision(spaceshipPos, landerPos, SpaceshipWidth, SpaceshipHeight, LanderWidth, LanderHeight));
}
//
TEST(collision,TestingNoCollision)
{
    SpaceFighter spaceFighter;
    POSITION spaceshipPos = spaceFighter.getPosition();
    Landers lander(spaceshipPos.xPosition, (spaceshipPos.yPosition+(SpaceshipWidth))+1);
    POSITION landerPos = lander.getPosition();
    collision collideTest;
    EXPECT_FALSE(collideTest.checkCollision(spaceshipPos, landerPos, SpaceshipWidth, SpaceshipHeight, LanderWidth, LanderHeight));
}


// TEST keyboard constructor
TEST(Keyboard,TestingCorrectInitialisationOfUpMovement)
{
    Keyboard key;
    EXPECT_FALSE(key.isMovingUp());
}

TEST(Keyboard,TestingCorrectInitialisationOfDownMovement)
{
    Keyboard key;
    EXPECT_FALSE(key.isMovingDown());
}

TEST(Keyboard,TestingCorrectInitialisationOfLeftMovement)
{
    Keyboard key;
    EXPECT_FALSE(key.isMovingLeft());
}

TEST(Keyboard,TestingCorrectInitialisationOfRightMovement)
{
    Keyboard key;
    EXPECT_FALSE(key.isMovingRight());
}

// TEST keyboard events
TEST(Keyboard,TestingIfUpWardKeyCanBeSet)
{
    Keyboard key;
    key.handleKeyEvent(sf::Keyboard::Up, true);
    EXPECT_TRUE(key.isMovingUp());
}

TEST(Keyboard,TestingIfDownWardKeyCanBeSet)
{
    Keyboard key;
    key.handleKeyEvent(sf::Keyboard::Down, true);
    EXPECT_TRUE(key.isMovingDown());
}

TEST(Keyboard,TestingIfUpLeftKeyCanBeSetOff)
{
    Keyboard key;
    key.handleKeyEvent(sf::Keyboard::Left, true);
    key.handleKeyEvent(sf::Keyboard::Left, false);
    EXPECT_FALSE(key.isMovingLeft());
}

TEST(Keyboard,TestingIfUpRightKeyCanBeSetOff)
{
    Keyboard key;
    key.handleKeyEvent(sf::Keyboard::Right, true);
    key.handleKeyEvent(sf::Keyboard::Right, false);
    EXPECT_FALSE(key.isMovingRight());
    system("PAUSE"); 
}
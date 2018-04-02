#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>

#include "SpaceFighter.h"
#include "Landers.h"
#include "Common.h"
#include "collision.h"
#include "Missiles.h"
#include "Laser.h"
#include "Display.h"
#include "Create.h"
#include "DetectCollision.h"
#include "Keyboard.h"

using namespace std;

class couldNotLoadFighterFromFile
{
};
/**
 * @class Game
 * @author Moolisa Tlali
 * @author Sheena Philip
 * @date 01/09/2015
 * @file Game.h
 * @brief This class contains the logic of the the game. It is a central game controller that manages ties
          together all objects of the game.
 */
class Game
{
public:
    /**
     * @brief The constructor class initialises the window and the spaceship
     */
    Game();

    /**
     * @brief Function that controls the running of the game as a whole. It poles for keyboard input events and
              uses private member functions to manage game entities updates and manage the display of updates
              to the player.
     */
    void run();

private:
    /**
     * @brief Function that manages the updates of the four entities of the game. It ensures that each entity is
              is updated. These entities are also updated by a collision detection so that they are ready to be
              displayed to the player.
     */
    void update();
    /**
     * @brief Manages the display of game entities to the player by calling the presentation layer class Display.
     */
    void render();
    /**
     * @brief  Updates the spaceship in response to the keyboard input by the player. It performs spaceship logic
               function of how the spaceship moves while limiting it within the screen boundaries. It also comprises of
               a call to create spaceship lasers when a condition of creation of the laser is set.
     */
    void SpaceFighterUpdate();
    /**
     * @brief Just like the spacefighter update, it updates the enemy which in this case is the lander. It comprises of
              of a call to creation class which creates the enemies as the program progresses. It then moves each enemy
              as determined by a random number other private member functions entrusted for this purpose.
     */
    void EnemyUpdate();
    /**
     * @brief This function manages how the enemies shoot their missiles. Its function is to call Create class when
              time interval for creation of the missile is permissible
     */
    void enemyShoot();
    /**
     * @brief This function updates the vector of laser sprites so that the position of the sprites coincide with the
     laser objects. It also erases/kills the lasers when they exit the edge of the screen.
     */
    void LaserUpdate();
    /**
     * @brief Simillar to LaserUpdate this function updates the vector of missile sprites so that the position of the
     spritescoincide with the missiles objects. It also erases/kills the missiles when they exit the edge of the screen.
     */
    void MissilesUpdate();
    /**
     * @brief This function calls detect collission to determines the collission between Lander And Spaceship, Laser
    And Lander and between Missile And SpaceShip.
     */
    void detectCollisions();
    /**
     * @brief Function that obtains the amount of time that has passed since the program started executing. It is uded
    to
    obtain time at different points in the game so that creation of landers and their shooting is timed.
     * @return type double of the time in seconds since the beginning of program execusion.
     */
    double getProcessTime();

    //data members
    double initialTime = 0;
    double enemyMoveTime = 0;
    double time1 = 0;
    double spaceshipFireTime = 0;
    double enemyFireTime = 0;
    double spaceshipFireInterval = 4;
    double enemyMoveInterval = 4;
    double createEnemyInterval = 5;
    double enemyShootInterval = 4;

    int createdEnemiesCounter = 0;
    int destroyedEnemiesCounter = 0;
    int counter = 3;

    int gamestatus = 0;

    // objects
    SpaceFighter player;
    Create creation;
    Keyboard keys;

    // Data members
    //Direction shootDirection;
    bool spaceshipDirectionLeft;
    bool spaceshipShoots;
    // vectors
    vector<Landers> enemyVector{};
    vector<Laser> laserVector{};
    vector<Missiles> missileVector{};
    vector<Direction> laserDirections{};
    vector<int> numberOfLandersVector{};
    // SFML related
    sf::RenderWindow window;
    sf::Texture spaceFighter;
    sf::Texture missile;
    sf::Sprite spriteSpaceship;
    // SFML Vectors
    vector<sf::Sprite> enemySprite{};
    vector<sf::Sprite> laserSpriteVector{};
    vector<sf::Sprite> missileSpriteVector{};
};

#endif
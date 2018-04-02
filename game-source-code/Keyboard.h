#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <SFML/Graphics.hpp>

/**
 * @class Keyboard
 * @author Moolisa Tlali
 * @author Sheena Philip
 * @date 01/10/2015
 * @file Keyboard.h
 * @brief This class handles keybord inputs by the player. These are all related to the player key events. Enemy events are all automatic
 * This class resides on the presentation and makes use of SFML functions.
 */
class Keyboard
{
public:
    /**
     * @brief Initialises data members that represent player keys to boolean false   
     */
    Keyboard();
    /**
     * @brief Poles for a keybord event and when a key is pressed, it calls a handlekeyevent function that will process the event 
     * @param _window is the visual screen as seen by the player
     */
    void processEvents(sf::RenderWindow& _window);
    /**
     * @brief Determines which key has been pressed and sets a relevent boolian data member to true.
     * @param key is the keyboard event that details through the next parameter the state of the relevent key 
     * @param isPressed is parameter that details the state of the pressed key. TRUE implies the key has been
     pressed while FALSE implies the reverse of that. 
     */
    void handleKeyEvent(sf::Keyboard::Key key, bool isPressed);
    /**
     * @brief Function used to return the state of UPWARD key relating to players command to move spaceship upwards.
     * @return boolian TRUE for Moving Up otherwise FALSE
     */
    bool isMovingUp();
    /**
     * @brief Function used to return the state of DOWNWARD key relating to players command to move spaceship downwards.
     * @return boolian TRUE for Moving Down otherwise FALSE
     */
    bool isMovingDown();
    /**
     * @brief Function used to return the state of LEFT key relating to players command to move spaceship to the LEFT.
     * @return boolian TRUE for Moving Left otherwise FALSE
     */
    bool isMovingLeft();
    /**
     * @brief Function used to return the state of RIGHT key relating to players command to move spaceship to the RIGHT.
     * @return boolian TRUE for Moving Right otherwise FALSE
     */
    bool isMovingRight();
    /**
     * @brief Function used to return the state of SPACEBAR key relating to players command to fire a laser.
     * @return boolian TRUE for shooting otherwise FALSE
     */
    bool SpaceshipFires();

private:
    bool spaceshipMovesUp;
    bool spaceshipMovesDown;
    bool spaceshipMovesRight;
    bool spaceshipMovesLeft;
    bool spaceshipShoots;
};

#endif
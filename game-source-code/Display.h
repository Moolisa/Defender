#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include "Common.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

using namespace std;

/**
 * @class couldNotLoadTextFontFromFile
 * @author Moolisa Tlali
 * @author Sheena Philip
 * @date 30/09/2015
 * @file Display.h
 * @brief TException class thrown when font text cannot be loaded from file
 */
class couldNotLoadTextFontFromFile
{
};

/**
 * @class Display
 * @author Moolisa Tlali
 * @author Sheena Philip
 * @date 30/09/2015
 * @file Display.h
 * @brief The purpose of this class is to display all the sprites on the screen
 */
class Display
{

public:
    /**
     * @brief This constructor initialises the font and text that will be displayed
     */
    Display();
    /**
     * @brief This function all the entities of the game and displays them on the window. 
     * @param _window (window where entities will be displayed)
     * @param _spriteSpaceship (The spaceship sprite)
     * @param _enemySprite (The vector containing enemy sprites)
     * @param _laserSpritevector (The vector containing all the lasers)
     * @param _missileSpriteVector (The vector containing all the missile)
     */
    void DrawSprites(sf::RenderWindow& _window,
                     sf::Sprite& _spriteSpaceship,
                     vector<sf::Sprite>& _enemySprite,
                     vector<sf::Sprite>& _laserSpritevector,
                     vector<sf::Sprite>& _missileSpriteVector);
    /**
     * @brief When the hame ends, this function displays a window with relevent message depending on the satus of the game 
     * @param _window (window where entities will be displayed)
     * @param gamestatus (Interger value denoting the staus of the game: 1 means player has won; 2 player loses)
     */
    void EndGame(sf::RenderWindow& _window, int& gamestatus);

private:
    sf::Font font;
    sf::Text text1;
    sf::Text text2;
};

#endif
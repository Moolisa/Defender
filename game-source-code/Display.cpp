#include "Display.h"

Display::Display()
{
    if(!font.loadFromFile("Lobster_1.3.OTF"))
        throw couldNotLoadTextFontFromFile();

    text1.setFont(font);
    text1.setCharacterSize(50);
    text1.setStyle(sf::Text::Bold);
    text1.setColor(sf::Color::Green);
    
    text2.setFont(font);
    text2.setCharacterSize(30);
    text2.setStyle(sf::Text::Bold);
    text2.setColor(sf::Color::Green);
}

void Display::DrawSprites(sf::RenderWindow& _window,
                          sf::Sprite& _spriteSpaceship,
                          vector<sf::Sprite>& _enemySprite,
                          vector<sf::Sprite>& _laserSpriteVector,
                          vector<sf::Sprite>& _missileSpriteVector)
{
    _window.clear();

    _window.draw(_spriteSpaceship);

    for(int i = 0; i < _enemySprite.size(); i++)
        _window.draw(_enemySprite[i]);

    for(int i = 0; i < _laserSpriteVector.size(); i++)
        _window.draw(_laserSpriteVector[i]);

    for(int i = 0; i < _missileSpriteVector.size(); i++)
        _window.draw(_missileSpriteVector[i]);

    _window.display();
    
}

void Display::EndGame(sf::RenderWindow& _window, int& gamestatus)
{
    
    _window.clear();
    text1.setPosition(50, 400);
    text2.setPosition(50, 460);

    if(gamestatus == 1) {
        text1.setString("game over: YOU WIN. ");
        text2.setString("Earth is safe");
    } else if(gamestatus == 0) {
        text1.setString("game over: YOU LOSE. ");
        text2.setString("Earth is in danger");
    }

    _window.draw(text1);
    _window.draw(text2);
    _window.display();

    sf::Clock displayTime;
    sf::Time time2 = sf::seconds(5);
    while(displayTime.getElapsedTime() < time2) {
    }
    _window.close();
}

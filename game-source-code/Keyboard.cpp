#include "Keyboard.h"

Keyboard::Keyboard():
      spaceshipMovesUp{ false }
    , spaceshipMovesDown{ false }
    , spaceshipMovesLeft{ false }
    , spaceshipMovesRight{ false }
    , spaceshipShoots{ false }
    {}
    

void Keyboard::processEvents(sf::RenderWindow& _window)
{
    sf::Event event;

    while(_window.pollEvent(event)) {

        switch(event.type) {

        case sf::Event::KeyPressed:
            handleKeyEvent(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handleKeyEvent(event.key.code, false);
            break;
        case sf::Event::Closed:
            _window.close();
            break;
        }
    }
}

void Keyboard::handleKeyEvent(sf::Keyboard::Key key, bool isPressed)
{

    if(key == sf::Keyboard::Up)
        spaceshipMovesUp = isPressed;
    else if(key == sf::Keyboard::Down)
        spaceshipMovesDown = isPressed;
    else if(key == sf::Keyboard::Left)
        spaceshipMovesLeft = isPressed;
    else if(key == sf::Keyboard::Right)
        spaceshipMovesRight = isPressed;
    else if(key == sf::Keyboard::Space) {
        spaceshipShoots = isPressed;
    }
}

bool Keyboard::isMovingUp()
{
    return spaceshipMovesUp;
}
bool Keyboard::isMovingDown()
{
    return spaceshipMovesDown;
}

bool Keyboard::isMovingLeft()
{
    return spaceshipMovesLeft;
}
    
bool Keyboard::isMovingRight()
{
    return spaceshipMovesRight;
}

bool Keyboard::SpaceshipFires()
{
    return spaceshipShoots;

}
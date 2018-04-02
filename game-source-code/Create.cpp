#include "Create.h"

Create::Create()
{
}

void Create::creatingEnemyVector(vector<Landers>& enemyVector,
                                 vector<sf::Sprite>& enemySprite,
                                 int& createdEnemiesCounter,
                                 vector<int>& numberOfLandersVector)
{
    double difference = getProcessTime() - time1;
    if(enemyVector.size() < 5 && difference > createEnemyInterval && createdEnemiesCounter < 15) {
        createdEnemiesCounter++;
        srand(time(0));
        float enemyXposition = 100 + (rand() % 1400);
        float enemyYposition = 100 + (rand() % 700);
        Landers createdEnemy(enemyXposition, enemyYposition);
        enemyVector.push_back(createdEnemy);

        CreateLanderSprites(enemySprite, enemyVector);
        numberOfLandersVector.push_back(1);
        time1 = getProcessTime();
    }
}

void Create::CreateLanderSprites(vector<sf::Sprite>& enemySprite, vector<Landers>& enemyVector)
{
    sf::Sprite spriteLanders;
    enemy.loadFromFile("lander.png");

    POSITION lastEnemyPosition = enemyVector[enemyVector.size()].getPosition();
    spriteLanders.setOrigin(18, 18);
    spriteLanders.setTexture(enemy);
    spriteLanders.setPosition(lastEnemyPosition.xPosition, lastEnemyPosition.yPosition);
    enemySprite.push_back(spriteLanders);
}

double Create::getProcessTime()
{
    clock_t time = clock();
    return static_cast<double>(time) / CLOCKS_PER_SEC;
}

void Create::createLaser(bool& spaceshipShoots,
                         bool& spaceshipDirectionLeft,
                         double& spaceshipFireInterval,
                         double& spaceshipFireTime,
                         vector<Laser>& laserVector,
                         vector<Direction>& laserDirections,
                         vector<sf::Sprite>& laserSpriteVector,
                         POSITION& playerPosition)
{


    if(spaceshipShoots && spaceshipFireInterval > 0.1) {
        spaceshipFireTime = getProcessTime();

        Laser laser(playerPosition.xPosition, playerPosition.yPosition);
        laserVector.push_back(laser);
        createLaserSprite(laserSpriteVector, playerPosition);

        if(spaceshipDirectionLeft) {
            laserDirections.push_back(Direction::LEFT);
        }

        else
            laserDirections.push_back(Direction::RIGHT);

        //        for(int i = 0; i < laserSpriteVector.size(); i++)
        //            window.draw(laserSpriteVector[i]);
    }
}

void Create::createLaserSprite(vector<sf::Sprite>& laserSpriteVector, POSITION& playerPosition)
{
    bullet.loadFromFile("redbullet.png");
    sf::Sprite laserSprite;

    laserSprite.setOrigin(8, 8);
    laserSprite.setTexture(bullet);
    laserSprite.setPosition(playerPosition.xPosition, playerPosition.yPosition);
    laserSprite.setScale(0.5, 0.5);
    laserSpriteVector.push_back(laserSprite);
}
void Create::createMissiles(POSITION& spaceshipPos,
                            vector<Landers>& enemyVector,
                            vector<Missiles>& missileVector,
                            vector<sf::Sprite>& missileSpriteVector)
{

    for(int i = 0; i < enemyVector.size(); i++) {
        POSITION landerPos = enemyVector[i].getPosition();
        Missiles enemymissile(spaceshipPos, landerPos);
        missileVector.push_back(enemymissile);

        POSITION missilePosition = enemymissile.getPosition();
        createMissilesSprite(missileSpriteVector, missilePosition);
    }
}

void Create::createMissilesSprite(vector<sf::Sprite>& missileSpriteVector, POSITION& missilePosition)
{
    missile.loadFromFile("redbullet.png");
    sf::Sprite missileSprite;

    missileSprite.setOrigin(8, 8);
    missileSprite.setTexture(missile);
    missileSprite.setPosition(missilePosition.xPosition, missilePosition.yPosition);
    missileSprite.setScale(0.5, 0.5);
    missileSpriteVector.push_back(missileSprite);
}
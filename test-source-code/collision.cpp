#include "collision.h"

collision::collision(){};

bool collision::checkCollision(POSITION entity1,
                               POSITION entity2,
                               const float& entity1Width,
                               const float& entity1Height,
                               const float& entity2Width,
                               const float& entity2Height)
{
    if((entity1.xPosition - (entity1Width) / 2) < (entity2.xPosition - (entity2Width) / 2 + entity2Width) &&
       ((entity1.xPosition - (entity1Width) / 2 + entity1Width) > (entity2.xPosition - (entity2Width) / 2)) &&
       (entity1.yPosition - (entity1Height) / 2) < (entity2.yPosition - (entity2Height) / 2 + entity2Height) &&
       ((entity1.yPosition - (entity1Height) / 2 + entity1Height) > (entity2.yPosition - (entity2Height) / 2))) {
        return true;
    }
    return false;
}

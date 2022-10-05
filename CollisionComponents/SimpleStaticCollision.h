#pragma once
#include "BoxCollision.h"


class SimpleStaticCollision: public BoxCollision
{
public:
    SimpleStaticCollision(uint8_t new_layer, uint8_t new_mask, FloatRect new_box, Entity* entity);
    void collisionEvent() override
    {
    }
};

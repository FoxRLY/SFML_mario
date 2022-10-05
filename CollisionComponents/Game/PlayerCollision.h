#pragma once
#include "../BoxCollision.h"


class PlayerCollision: public BoxCollision
{
protected:
    Entity* self;
public:
    PlayerCollision(FloatRect new_box, Entity* entity);
    void collisionEvent() override;
};


#pragma once
#include "../MoveComponent.h"


class StaticMove: virtual public MoveComponent
{
public:
    StaticMove(Entity* entity);
    void moveEvent(float delta) override
    {
    }
};

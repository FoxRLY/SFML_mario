#pragma once
#include "MoveComponent.h"
#include "../Entities/Entity.h"

class CollisionMove: virtual public MoveComponent
{
protected:
public:
    CollisionMove(float new_x_speed, float new_y_speed, Entity* entity, Vector2f new_velocity);
    void moveEvent(float delta) override;
};


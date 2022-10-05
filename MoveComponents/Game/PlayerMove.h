#pragma once
#include "../MoveComponent.h"
#include "../CollisionMove.h"
#include "../InputMove.h"
#include "../GravityMove.h"


class PlayerMove: public CollisionMove, public InputMove, public GravityMove
{
public:
    PlayerMove(float new_x_speed, float new_y_speed, float gravity_force, Entity* entity);
    void moveEvent(float delta) override;
};


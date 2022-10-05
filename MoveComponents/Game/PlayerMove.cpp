#include "PlayerMove.h"
#include <cmath>

void PlayerMove::moveEvent(float delta)
{
    velocity.x *= 0.9;
    GravityMove::moveEvent(delta);
    InputMove::moveEvent(delta);
    CollisionMove::moveEvent(delta);
}

PlayerMove::PlayerMove(float new_x_speed, float new_y_speed, float gravity_force, Entity* entity):
MoveComponent(new_x_speed, new_y_speed, entity, {0,0}),
GravityMove({0,1}, gravity_force, new_x_speed, new_y_speed, entity, {0,0}),
InputMove(new_x_speed, new_y_speed, entity, {0,0}),
CollisionMove(new_x_speed, new_y_speed, entity, {0,0})
{

}
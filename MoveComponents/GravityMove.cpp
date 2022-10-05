#include "GravityMove.h"

GravityMove::GravityMove(Vector2f new_vector, float new_force, float new_x_speed, float new_y_speed, Entity* entity, Vector2f new_velocity = {0,0}):
MoveComponent(new_x_speed, new_y_speed, entity, new_velocity)
{
    gravity_vector = new_vector;
    gravity_force = new_force;
}

void GravityMove::setGravityVector(Vector2f new_vector)
{
    gravity_vector = new_vector;
}

void GravityMove::setGravityForce(float new_force)
{
    gravity_force = new_force;
}

Vector2f GravityMove::getGravityVector()
{
    return gravity_vector;
}

float GravityMove::getGravityForce()
{
    return gravity_force;
}

void GravityMove::moveEvent(float delta)
{
    velocity -= gravity_vector * gravity_force * delta;
}
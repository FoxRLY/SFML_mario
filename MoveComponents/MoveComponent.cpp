#include "MoveComponent.h"

MoveComponent::MoveComponent(float new_x_speed, float new_y_speed, Entity* entity, Vector2f new_velocity = {0,0})
{
    velocity = new_velocity;
    x_speed = new_x_speed;
    y_speed = new_y_speed;
    self = entity;
}

Vector2f MoveComponent::getVelocity()
{
    return velocity;
}

float MoveComponent::getXSpeed()
{
    return x_speed;
}

float MoveComponent::getYSpeed()
{
    return y_speed;
}

void MoveComponent::setVelocity(Vector2f new_velocity)
{
    velocity = new_velocity;
}

void MoveComponent::setXSpeed(float new_speed)
{
    x_speed = new_speed;
}

void MoveComponent::setYSpeed(float new_speed)
{
    y_speed = new_speed;
}
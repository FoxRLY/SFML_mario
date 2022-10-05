#pragma once
#include "MoveComponent.h"

class GravityMove: virtual public MoveComponent
{
protected:
    Vector2f gravity_vector;
    float gravity_force;
public:
    GravityMove(Vector2f new_vector, float new_force, float new_x_speed, float new_y_speed, Entity* entity, Vector2f new_velocity);
    void setGravityVector(Vector2f new_vector);
    void setGravityForce(float new_force);
    Vector2f getGravityVector();
    float getGravityForce();
    void moveEvent(float delta) override;
};



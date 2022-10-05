#pragma once
#include <SFML/Graphics.hpp>
#include "../CollisionComponents/CollisionComponent.h"
#include "../DrawComponents/DrawComponent.h"

using namespace sf;
using namespace std;

class MoveComponent
{
protected:
    Vector2f velocity;
    float x_speed;
    float y_speed;
    Entity* self;
public:
    MoveComponent(float new_x_speed, float new_y_speed, Entity* self, Vector2f new_velocity);
    void setVelocity(Vector2f new_velocity);
    void setXSpeed(float new_speed);
    void setYSpeed(float new_speed);
    Vector2f getVelocity();
    float getXSpeed();
    float getYSpeed();
    virtual void moveEvent(float delta) = 0;
    virtual ~MoveComponent() = default;
};


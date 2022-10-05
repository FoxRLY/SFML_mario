#pragma once
#include "CollisionComponent.h"
#include "../Entities/Entity.h"

using namespace sf;
using namespace std;

class BoxCollision : public CollisionComponent
{
protected:
    FloatRect collision_box;
    Entity* self;
public:
    BoxCollision(uint8_t new_layer, uint8_t new_mask, FloatRect new_box, Entity* entity);
    void collisionEvent() override;
    FloatRect getGlobalBounds() override;
    void move(Vector2f move_vector) override;
    void setGlobalBounds(FloatRect new_box) override;
};


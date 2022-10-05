#pragma once
#include "MoveComponent.h"
#include "../Entities/Entity.h"


class InputMove: virtual public MoveComponent
{
protected:
    Vector2f direction;
    bool jump_hold;
    int jump_count;
    static bool isMouseButtonPressed(Mouse::Button button);
    static bool isKeyPressed(Keyboard::Key key);
public:
    InputMove(float new_x_speed, float new_y_speed, Entity *entity, Vector2f new_velocity);
    void moveEvent(float delta) override;
};


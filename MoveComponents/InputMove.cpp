#include "InputMove.h"
#include <iostream>
#include <cmath>

InputMove::InputMove(float new_x_speed, float new_y_speed, Entity *entity, Vector2f new_velocity = {0,0})
: MoveComponent(new_x_speed, new_y_speed, entity, new_velocity)
{
    jump_hold = false;
    jump_count = 0;
}

bool InputMove::isKeyPressed(Keyboard::Key key)
{
    return Keyboard::isKeyPressed(key);
}

bool InputMove::isMouseButtonPressed(Mouse::Button button)
{
    return Mouse::isButtonPressed(button);
}

void InputMove::moveEvent(float delta)
{
    float right = isKeyPressed(Keyboard::D);
    float left = isKeyPressed((Keyboard::A));
    direction = {(right-left)*(x_speed/5.f) , 0};
    if(isKeyPressed(Keyboard::Space) && self->getCollisionDir() == Dir_bottom)
    {
        direction.y += -std::sqrt(3.0 * 981.0f * y_speed);
    }
    direction.x *= delta;
    velocity += direction;
    velocity.y = std::abs(velocity.y) > y_speed ? y_speed * (velocity.y / std::abs(velocity.y)) : velocity.y;
    velocity.x = std::abs(velocity.x) > x_speed ? x_speed * (velocity.x / std::abs(velocity.x)) : velocity.x;
}
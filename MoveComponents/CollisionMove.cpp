#include "CollisionMove.h"

void CollisionMove::moveEvent(float delta)
{
    uint8_t dir = self->getCollisionDir();
    if((dir & Dir_top && velocity.y < 0) || (dir & Dir_bottom && velocity.y > 0))
    {
        velocity.y = 0;
    }
    if((dir & Dir_left && velocity.x < 0) || (dir & Dir_right && velocity.x > 0))
    {
        velocity.x = 0;
    }

}

CollisionMove::CollisionMove(float new_x_speed, float new_y_speed, Entity *entity, Vector2f new_velocity = {0,0})
: MoveComponent(new_x_speed, new_y_speed, entity, new_velocity)
{
}

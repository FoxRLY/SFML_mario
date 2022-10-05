#include "BoxCollision.h"

BoxCollision::BoxCollision(uint8_t new_layer, uint8_t new_mask, FloatRect new_box, Entity* entity):
CollisionComponent(new_layer, new_mask)
{
    self = entity;
    collision_box = new_box;
}

void BoxCollision::collisionEvent()
{
    resetCollidedEntities();
    resetDirection();
    for(auto entity : Entity::entity_list)
    {
        if(entity == self)
        {
            continue;
        }
        CollisionComponent* check_coll = entity->getCollisionComp();
        if(collision_box.intersects(check_coll->getGlobalBounds()) && maskCheck(check_coll->getLayer()))
        {
            CollisionOccurence new_occurence = {entity, 0};
            float minXDist = collision_box.width / 2.f + check_coll->getGlobalBounds().width/2.f + 0.5;
            float minYDist = collision_box.height / 2.f + check_coll->getGlobalBounds().height/2.f + 0.5;
            float diffX = (collision_box.left + collision_box.width/2.f) - (check_coll->getGlobalBounds().left + check_coll->getGlobalBounds().width/2.f);
            float diffY = (collision_box.top + collision_box.height/2.f) - (check_coll->getGlobalBounds().top + check_coll->getGlobalBounds().height/2.f);
            float depthX = diffX > 0 ? minXDist - diffX : -minXDist - diffX;
            float depthY = diffY > 0 ? minYDist - diffY : -minYDist - diffY;
            if(depthX != 0 && depthY != 0)
            {
                if(std::abs(depthX) < std::abs(depthY))
                {
                    if(depthX > 0)
                    {

                        new_occurence.dir = Dir_left;
                        dir |= Dir_left;
                    }
                    else
                    {
                        new_occurence.dir = Dir_right;
                        dir |= Dir_right;
                    }
                    self->move({depthX,0});
                }
                else
                {
                    if(depthY > 0)
                    {
                        new_occurence.dir = Dir_top;
                        dir |= Dir_top;
                    }
                    else
                    {
                        new_occurence.dir = Dir_bottom;
                        dir |= Dir_bottom;
                    }
                    self->move({0,depthY});
                }
            }
            collided_entities.push_back(new_occurence);
        }
    }
}

void BoxCollision::move(Vector2f move_vector)
{
    collision_box.left += move_vector.x;
    collision_box.top += move_vector.y;
}

FloatRect BoxCollision::getGlobalBounds()
{
    return collision_box;
}

void BoxCollision::setGlobalBounds(FloatRect new_box)
{
    collision_box = new_box;
}
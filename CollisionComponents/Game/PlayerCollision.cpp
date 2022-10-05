#include "PlayerCollision.h"
#include "../../Entities/Player.h"

PlayerCollision::PlayerCollision(FloatRect new_box, Entity* entity):
BoxCollision(Layer_player, Layer_enemy|Layer_coin|Layer_world, new_box, entity)
{
    self = entity;
}

void PlayerCollision::collisionEvent()
{
    BoxCollision::collisionEvent();
    for(auto occurence : collided_entities)
    {
        if(occurence.entity->getCollisionLayer() == Layer_enemy)
        {
            if(occurence.dir == Dir_bottom)
            {
                occurence.entity->destroy(self);
            }
            else
            {
                self->destroy(self);
            }
        }
        if(occurence.entity->getCollisionLayer() == Layer_coin)
        {
            occurence.entity->destroy(self);
            Player::coins++;
        }
    }
}



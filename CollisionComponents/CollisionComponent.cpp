#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(uint8_t new_layer, uint8_t new_mask)
{
    collided_entities = {};
    layer = new_layer;
    mask = new_mask;
    dir = 0;
}

uint8_t CollisionComponent::getLayer()
{
    return layer;
}

void CollisionComponent::setLayer(uint8_t new_layer)
{
    layer = new_layer;
}

uint8_t CollisionComponent::getDirection()
{
    return dir;
}

void CollisionComponent::resetDirection()
{
    dir = 0;
}

void CollisionComponent::resetCollidedEntities()
{
    collided_entities.clear();
}

CollisionOccurence CollisionComponent::isColliding(Entity *check_entity)
{
    for(auto occurance : collided_entities)
    {
        if(occurance.entity == check_entity)
        {
            return occurance;
        }
    }
    return CollisionOccurence{nullptr, 0};
}

void CollisionComponent::setMask(uint8_t new_mask)
{
    mask = new_mask;
}

uint8_t CollisionComponent::getMask()
{
    return mask;
}

bool CollisionComponent::maskCheck(uint8_t collider_layer)
{
    return mask & collider_layer;
}
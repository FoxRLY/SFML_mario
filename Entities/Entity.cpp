#include <algorithm>
#include "Entity.h"


vector<Entity*> Entity::entity_list = {};

Entity::Entity()
{
    collision_comp = nullptr;
    move_comp = nullptr;
    draw_comp = nullptr;
    entity_list.push_back(this);
}

CollisionComponent *Entity::getCollisionComp()
{
    return collision_comp;
}

DrawComponent *Entity::getDrawComp()
{
    return draw_comp;
}

MoveComponent *Entity::getMoveComp()
{
    return move_comp;
}

void Entity::setCollisionComp(CollisionComponent *new_comp)
{
    collision_comp = new_comp;
}

void Entity::setDrawComp(DrawComponent *new_comp)
{
    draw_comp = new_comp;
}

void Entity::setMoveComp(MoveComponent *new_comp)
{
    move_comp = new_comp;
}

uint8_t Entity::getCollisionLayer()
{
    return collision_comp->getLayer();
}

uint8_t Entity::getCollisionDir()
{
    return collision_comp->getDirection();
}

void Entity::move(Vector2f vec)
{
    collision_comp->move(vec);
    draw_comp->move(vec);
}

FloatRect Entity::getGlobalBounds()
{
    if(collision_comp)
    {
        return collision_comp->getGlobalBounds();
    }
    return {};
}

void Entity::setGlobalBounds(FloatRect bounds)
{
    collision_comp->setGlobalBounds(bounds);
    draw_comp->setGlobalBounds(bounds);
}

void Entity::checkEvents(float delta)
{
    move_comp->moveEvent(delta);
    move(move_comp->getVelocity());
    collision_comp->collisionEvent();
    draw_comp->drawEvent();
}

void Entity::destroy(Entity* caller)
{
    delete collision_comp;
    delete move_comp;
    delete draw_comp;
    entity_list.erase(std::remove(entity_list.begin(), entity_list.end(), this), entity_list.end());
}

Entity::~Entity()
{
    Entity::destroy(this);
}


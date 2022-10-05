#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../CollisionComponents/CollisionComponent.h"
#include "../DrawComponents/DrawComponent.h"
#include "../MoveComponents/MoveComponent.h"

class Entity
{
protected:
    CollisionComponent* collision_comp;
    DrawComponent* draw_comp;
    MoveComponent* move_comp;
public:
    static vector<Entity*> entity_list;
    Entity();
    CollisionComponent* getCollisionComp();
    DrawComponent* getDrawComp();
    MoveComponent* getMoveComp();
    void setCollisionComp(CollisionComponent* new_comp);
    void setDrawComp(DrawComponent* new_comp);
    void setMoveComp(MoveComponent* new_comp);
    uint8_t getCollisionLayer();
    uint8_t getCollisionDir();
    FloatRect getGlobalBounds();
    void move(Vector2f vec);
    virtual void setGlobalBounds(FloatRect bounds);
    virtual void checkEvents(float delta);
    virtual void destroy(Entity* caller);
    virtual ~Entity();
};

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Entity;

using namespace sf;
using namespace std;

const uint8_t Layer_world = 0x01;
const uint8_t Layer_player = 0x02;
const uint8_t Layer_enemy = 0x04;
const uint8_t Layer_coin = 0x08;
const uint8_t Layer_stop_area = 0x10;

const uint8_t Dir_top = 0x01;
const uint8_t Dir_bottom = 0x02;
const uint8_t Dir_left = 0x04;
const uint8_t Dir_right = 0x08;

struct CollisionOccurence
{
    Entity* entity;
    uint8_t dir;
};

class CollisionComponent
{
protected:
    vector<CollisionOccurence> collided_entities;   // Список коллизий на данный момент
    uint8_t layer;                                  // Какому слою принадлежит
    uint8_t mask;                                   // С каким слоем взаимодействует
    uint8_t dir;                                    // Какие стороны в коллизии
public:
    CollisionComponent(uint8_t new_layer, uint8_t new_mask);
    uint8_t getLayer();
    uint8_t getMask();
    void setMask(uint8_t new_mask);
    void setLayer(uint8_t new_layer);
    uint8_t getDirection();
    void resetDirection();
    void resetCollidedEntities();
    CollisionOccurence isColliding(Entity* check_entity);
    bool maskCheck(uint8_t collider_layer);
    virtual FloatRect getGlobalBounds() = 0;
    virtual void setGlobalBounds(FloatRect new_box) = 0;
    virtual void collisionEvent() = 0;
    virtual void move(Vector2f move_vector) = 0;
    virtual ~CollisionComponent() = default;
};


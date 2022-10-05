#include "EntityConstructor.h"

Player *EntityConstructor::getPlayer(Texture* new_texture, FloatRect pos_rect, FloatRect sprite_rect, RenderWindow* new_window, float new_x_speed, float new_y_speed, float gravity_force)
{
    auto* new_entity = new Player();
    auto* new_collision = new PlayerCollision(pos_rect, new_entity);
    auto* new_draw = new SpriteComponent(new_texture, sprite_rect, pos_rect, new_window);
    auto* new_move = new PlayerMove(new_x_speed, new_y_speed, gravity_force, new_entity);
    new_entity->setCollisionComp(new_collision);
    new_entity->setDrawComp(new_draw);
    new_entity->setMoveComp(new_move);
    new_entity->setGlobalBounds(pos_rect);
    return new_entity;
}

Tile *EntityConstructor::getTile(Texture* new_texture, FloatRect pos_rect, FloatRect sprite_rect, Vector2f tile_dims, RenderWindow* new_window)
{
    auto* new_entity = new Tile();
    auto* new_collision = new StaticTileCollision(pos_rect, new_entity);
    auto* new_draw = new TileDraw(new_texture, sprite_rect, tile_dims, pos_rect, new_window);
    auto* new_move = new StaticMove(new_entity);
    new_entity->setCollisionComp(new_collision);
    new_entity->setDrawComp(new_draw);
    new_entity->setMoveComp(new_move);
    new_entity->setGlobalBounds(pos_rect);
    return new_entity;
}

Coin *EntityConstructor::getCoin(Texture *new_texture, FloatRect pos_rect, FloatRect sprite_rect, RenderWindow *new_window)
{
    auto* new_entity = new Coin();
    auto* new_collision = new CoinCollision(pos_rect, new_entity);
    auto* new_draw = new SpriteComponent(new_texture, sprite_rect, pos_rect, new_window);
    auto* new_move = new StaticMove(new_entity);
    new_entity->setCollisionComp(new_collision);
    new_entity->setDrawComp(new_draw);
    new_entity->setMoveComp(new_move);
    new_entity->setGlobalBounds(pos_rect);
    return new_entity;
}
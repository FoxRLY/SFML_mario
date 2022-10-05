#pragma once
#include "Entity.h"
#include "Player.h"
#include "Tile.h"
#include "Coin.h"
#include "../CollisionComponents/Game/PlayerCollision.h"
#include "../CollisionComponents/Game/StaticTileCollision.h"
#include "../CollisionComponents/Game/CoinCollision.h"
#include "../DrawComponents/Game/SpriteComponent.h"
#include "../DrawComponents/Game/TileDraw.h"
#include "../MoveComponents/Game/PlayerMove.h"
#include "../MoveComponents/Game/StaticMove.h"


class EntityConstructor
{
public:
    static Player* getPlayer(Texture* new_texture, FloatRect pos_rect, FloatRect sprite_rect, RenderWindow* new_window, float new_x_speed, float new_y_speed, float gravity_force);
    static Tile* getTile(Texture* new_texture, FloatRect pos_rect, FloatRect sprite_rect, Vector2f tile_dims, RenderWindow* new_window);
    static Coin* getCoin(Texture* new_texture, FloatRect pos_rect, FloatRect sprite_rect, RenderWindow* new_window);
};


#include "StaticTileCollision.h"

StaticTileCollision::StaticTileCollision(FloatRect new_box, Entity* entity):
SimpleStaticCollision(Layer_world, Layer_player|Layer_enemy, new_box, entity)
{
}
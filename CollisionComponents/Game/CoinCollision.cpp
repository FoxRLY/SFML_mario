#include "CoinCollision.h"

CoinCollision::CoinCollision(FloatRect new_box, Entity *entity):
SimpleStaticCollision(Layer_coin, Layer_player, new_box, entity)
{
}
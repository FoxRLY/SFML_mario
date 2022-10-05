#include "SimpleStaticCollision.h"

SimpleStaticCollision::SimpleStaticCollision(uint8_t new_layer, uint8_t new_mask, FloatRect new_box, Entity* entity):
BoxCollision(new_layer, new_mask, new_box, entity)
{
}
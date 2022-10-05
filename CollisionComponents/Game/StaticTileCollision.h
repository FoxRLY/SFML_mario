#pragma once
#include "../SimpleStaticCollision.h"

class StaticTileCollision: public SimpleStaticCollision
{
protected:
public:
    StaticTileCollision(FloatRect new_box, Entity* entity);
};


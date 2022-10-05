#pragma once
#include "../SimpleStaticCollision.h"


class CoinCollision: public SimpleStaticCollision
{
public:
    CoinCollision(FloatRect new_box, Entity* entity);
};



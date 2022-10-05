#pragma once
#include "../DrawComponent.h"

class TileDraw: public DrawComponent
{
protected:
    Texture* texture;
    Sprite sprite;
    Vector2f texture_dimensions;
    Vector2f tile_dimensions;
    Vector2f platform_dimensions;
public:
    TileDraw(Texture *new_texture, FloatRect sprite_rect, Vector2f tile_dimensions, FloatRect pos_rect, RenderWindow *new_window);
    void move(Vector2f move_vector) override;
    FloatRect getGlobalBounds() override;
    void drawEvent() override;
    void setGlobalBounds(FloatRect new_box) override;
};


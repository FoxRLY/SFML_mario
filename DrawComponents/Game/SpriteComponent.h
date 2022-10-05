#pragma once
#include "../DrawComponent.h"


class SpriteComponent: public DrawComponent
{
protected:
    Texture* texture;
    Sprite sprite;
public:
    SpriteComponent(Texture* new_texture, FloatRect sprite_rect, FloatRect pos_rect, RenderWindow* new_window);
    void move(Vector2f move_vector) override;
    FloatRect getGlobalBounds() override;
    void drawEvent() override;
    void setGlobalBounds(FloatRect new_box) override;
};


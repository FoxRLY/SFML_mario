#include "TileDraw.h"

TileDraw::TileDraw(Texture *new_texture, FloatRect sprite_rect, Vector2f new_tile_dimensions, FloatRect pos_rect,RenderWindow *new_window):
DrawComponent(new_window)
{
    texture = new_texture;
    texture->setRepeated(true);
    texture_dimensions = {(float)texture->getSize().x, (float)texture->getSize().y};
    tile_dimensions = new_tile_dimensions;
    platform_dimensions = {pos_rect.width, pos_rect.height};

    sprite.setTexture(*texture);
    sprite.setTextureRect({0,0,
                           (int)(texture_dimensions.x * platform_dimensions.x / tile_dimensions.x),
                           (int)(texture_dimensions.y * platform_dimensions.y / tile_dimensions.y)});
    sprite.setPosition(pos_rect.left, pos_rect.top);
    sprite.setScale({(float)tile_dimensions.x/texture_dimensions.x,(float)tile_dimensions.y/texture_dimensions.y});
}

FloatRect TileDraw::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

void TileDraw::move(Vector2f move_vector)
{
    sprite.move(move_vector);
}

void TileDraw::drawEvent()
{
    window->draw(sprite);
}

void TileDraw::setGlobalBounds(FloatRect new_box)
{
    platform_dimensions = {new_box.width, new_box.height};
    sprite.setTextureRect({0,0,
                           (int)(texture_dimensions.x * platform_dimensions.x / tile_dimensions.x),
                           (int)(texture_dimensions.y * platform_dimensions.y / tile_dimensions.y)});
    sprite.setPosition(new_box.left, new_box.top);
    sprite.setScale({(float)tile_dimensions.x/texture_dimensions.x,(float)tile_dimensions.y/texture_dimensions.y});
}
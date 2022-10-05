#include "SpriteComponent.h"


SpriteComponent::SpriteComponent(Texture *new_texture, FloatRect sprite_rect, FloatRect pos_rect,
                                 RenderWindow *new_window): DrawComponent(new_window)
{
    texture = new_texture;
    sprite.setTexture(*texture);
    sprite.setTextureRect(static_cast<IntRect>(sprite_rect));
    sprite.setPosition(pos_rect.left, pos_rect.top);
    sprite.setScale(pos_rect.width/texture->getSize().x, pos_rect.height/texture->getSize().y);
}

FloatRect SpriteComponent::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

void SpriteComponent::move(Vector2f move_vector)
{
    sprite.move(move_vector);
}

void SpriteComponent::drawEvent()
{
    window->draw(sprite);
}

void SpriteComponent::setGlobalBounds(FloatRect new_box)
{
    sprite.setPosition(new_box.left, new_box.top);
    sprite.setScale(new_box.width/texture->getSize().x, new_box.height/texture->getSize().y);
}
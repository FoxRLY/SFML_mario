#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class DrawComponent
{
protected:
    RenderWindow* window;
public:
    DrawComponent(RenderWindow* new_window);
    virtual void move(Vector2f move_vector) = 0;
    virtual FloatRect getGlobalBounds() = 0;
    virtual void setGlobalBounds(FloatRect new_box) = 0;
    virtual void drawEvent() = 0;
    virtual ~DrawComponent() = default;
};

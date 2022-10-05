#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Entities/EntityConstructor.h"

using namespace sf;

Player* initMap(const std::string& map, const Vector2i map_dims, const int tile_size, Texture* player_texture, Texture* tile_texture, Texture* coin_texture, RenderWindow* window)
{
    Player* player;
    for(int i = map_dims.y-1; i >= 0; i--)
    {
        for(int k = map_dims.x-1; k >= 0; k--)
        {
            switch(map[i * map_dims.x + k])
            {
                case '#':
                {
                    EntityConstructor::getTile(tile_texture,
                                               {(float)k*tile_size, (float)i*tile_size, (float)tile_size, (float)tile_size},
                                               {0,0,(float)tile_texture->getSize().x,(float)tile_texture->getSize().y},
                                               {(float)tile_size,(float)tile_size},
                                               window);
                    break;
                }
                case '*':
                {
                    player = EntityConstructor::getPlayer(player_texture, {(float)k*tile_size, (float)i*tile_size, (float)tile_size-1, (float)tile_size-1}, {0,0,920,920}, window, 550,20,-50);
                    break;
                }
                case '0':
                {
                    EntityConstructor::getCoin(coin_texture,
                                               {(float)k*tile_size, (float)i*tile_size, (float)tile_size, (float)tile_size},
                                               {0,0,(float)coin_texture->getSize().x,(float)coin_texture->getSize().y},
                                               window);
                    break;
                }
                default:
                {
                }
            }
        }
    }
    return player;
}

int main()
{
    Font font;
    font.loadFromFile("assets/Font.ttf");

    std::string map;
    Vector2i map_dims = {21,12};
    map += "#                   #";
    map += "#                   #";
    map += "#      0            #";
    map += "#                   #";
    map += "#                   #";
    map += "#     *    0        #";
    map += "#    ### ###        #";
    map += "#          ####     #";
    map += "#               #   #";
    map += "#              #    #";
    map += "#    0        #   0 #";
    map += "#####################";
    RenderWindow window(VideoMode(1000,1000), "My window");
    window.setVerticalSyncEnabled(true);

    Texture player_texture;
    player_texture.loadFromFile("assets/mario.png");

    Texture tile_texture;
    tile_texture.loadFromFile("assets/brick.png");

    Texture coin_texture;
    coin_texture.loadFromFile("assets/coin.png");

    Text coin_counter;
    coin_counter.setFont(font);
    coin_counter.setCharacterSize(20);
    coin_counter.setFillColor(Color::White);
    coin_counter.setPosition(0,0);

    Player* player = initMap(map,map_dims,64,&player_texture,&tile_texture,&coin_texture,&window);

    View player_view;
    player_view = window.getView();
    player_view.setSize({1000,1000});

    Event event;
    Clock delta_clock;
    while(window.isOpen())
    {
        float delta = delta_clock.restart().asSeconds();
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case Event::Closed:
                {
                    window.close();
                    break;
                }
                case Event::Resized:
                {
                    sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                    window.setView(sf::View(visibleArea));
                    break;
                }
            }
        }

        std::string str = "Coins: ";
        str += std::to_string(Player::coins);
        coin_counter.setString(str);

        player_view.setCenter(player->getGlobalBounds().left, player->getGlobalBounds().top);
        window.setView(player_view);
        window.clear();

        for(auto entity: Entity::entity_list)
        {
            entity->checkEvents(delta);
        }
        window.setView(window.getDefaultView());
        window.draw(coin_counter);

        window.display();
    }
}

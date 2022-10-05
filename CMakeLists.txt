cmake_minimum_required(VERSION 3.20)
project(sfml_doodle)

set(CMAKE_CXX_STANDARD 14)

add_executable(sfml_doodle main.cpp Entities/Entity.cpp Entities/Entity.h CollisionComponents/CollisionComponent.cpp CollisionComponents/CollisionComponent.h DrawComponents/DrawComponent.cpp DrawComponents/DrawComponent.h MoveComponents/MoveComponent.cpp MoveComponents/MoveComponent.h CollisionComponents/BoxCollision.cpp CollisionComponents/BoxCollision.h CollisionComponents/Game/PlayerCollision.cpp CollisionComponents/Game/PlayerCollision.h DrawComponents/Game/SpriteComponent.cpp DrawComponents/Game/SpriteComponent.h MoveComponents/GravityMove.cpp MoveComponents/GravityMove.h MoveComponents/InputMove.cpp MoveComponents/InputMove.h MoveComponents/CollisionMove.cpp MoveComponents/CollisionMove.h MoveComponents/Game/PlayerMove.cpp MoveComponents/Game/PlayerMove.h MoveComponents/Game/StaticMove.cpp MoveComponents/Game/StaticMove.h CollisionComponents/SimpleStaticCollision.cpp CollisionComponents/SimpleStaticCollision.h CollisionComponents/Game/StaticTileCollision.cpp CollisionComponents/Game/StaticTileCollision.h Entities/Tile.cpp Entities/Tile.h Entities/Player.cpp Entities/Player.h Entities/EntityConstructor.cpp Entities/EntityConstructor.h DrawComponents/Game/TileDraw.cpp DrawComponents/Game/TileDraw.h Entities/Coin.cpp Entities/Coin.h CollisionComponents/Game/CoinCollision.cpp CollisionComponents/Game/CoinCollision.h)

set(SFML_DIR "c:/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

target_link_libraries(sfml_doodle sfml-graphics sfml-audio sfml-window sfml-system)

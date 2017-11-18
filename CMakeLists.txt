cmake_minimum_required(VERSION 3.7)
project(Gradius)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Model)
add_subdirectory(View)
add_subdirectory(Controller)

set(SOURCE_FILES main.cpp Animation.cpp Animation.h Player.cpp Player.h Model/Ship.cpp Model/Ship.h Model/Obstacle.cpp Model/Obstacle.h Model/Bullet.cpp Model/Bullet.h Model/MovingEntity.cpp Model/MovingEntity.h Model/StaticEntity.cpp Model/StaticEntity.h)
add_executable(Gradius ${SOURCE_FILES} ${VIEW_FILES} ${MODEL_FILES} ${CONTROLLER_FILES})

target_link_libraries(Gradius sfml-graphics sfml-window sfml-system)
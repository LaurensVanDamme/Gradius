cmake_minimum_required(VERSION 3.7)
project(Gradius)

set(CMAKE_CXX_STANDARD 11)

set(MODEL_FILES Model/Model.h Model/Model.cpp Model/Entity.cpp Model/Entity.h Model/Ship.cpp Model/Ship.h Model/Obstacle.cpp Model/Obstacle.h Model/Bullet.cpp Model/Bullet.h Model/MovingEntity.cpp Model/MovingEntity.h Model/StaticEntity.cpp Model/StaticEntity.h Model/Subject.cpp Model/Subject.h)
set(VIEW_FILES View/Entity.cpp View/Entity.h View/Animation.cpp View/Animation.h Controller/Stopwatch.cpp Controller/Stopwatch.h View/Transformation.cpp View/Transformation.h View/View.h View/View.cpp View/Entity.cpp View/Entity.h View/Observer.cpp View/Observer.h)
set(CONTROLLER_FILES Controller/Controller.h Controller/Controller.cpp)

set(SOURCE_FILES main.cpp Player.cpp Player.h)
add_executable(Gradius ${SOURCE_FILES} ${VIEW_FILES} ${MODEL_FILES} ${CONTROLLER_FILES})

target_link_libraries(Gradius sfml-graphics sfml-window sfml-system)
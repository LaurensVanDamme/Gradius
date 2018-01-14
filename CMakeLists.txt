cmake_minimum_required(VERSION 3.5)
project(Gradius)

set(CMAKE_CXX_STANDARD 14)


set(OBSERVER_PATTERN_FILES ObserverPattern/Subject.cpp ObserverPattern/Subject.h
        ObserverPattern/Observer.cpp ObserverPattern/Observer.h
        ObserverPattern/Event.h)

set(MODEL_FILES Model/World.h Model/World.cpp
        Model/Entity.cpp Model/Entity.h
        Model/Ship.cpp Model/Ship.h
        Model/Bullet.cpp Model/Bullet.h
        Model/Obstacle.cpp Model/Obstacle.h
        Model/Border.cpp Model/Border.h
        Model/AIShooter.cpp Model/AIShooter.h Model/PlayerShip.cpp Model/PlayerShip.h Model/AIFollower.cpp Model/AIFollower.h Model/Timestamp.cpp Model/Timestamp.h)

set(VIEW_FILES View/Entity.cpp View/Entity.h
        View/Player.cpp View/Player.h
        View/Animation.cpp View/Animation.h
        View/Transformation.cpp View/Transformation.h
        View/View.h View/View.cpp
        View/Entity.cpp View/Entity.h
        View/Player.cpp View/Player.h)

set(CONTROLLER_FILES Controller/Controller.h Controller/Controller.cpp
        Controller/Stopwatch.cpp Controller/Stopwatch.h)

set(SOURCE_FILES main.cpp Singleton.h)
add_executable(Gradius ${SOURCE_FILES} ${VIEW_FILES} ${MODEL_FILES} ${CONTROLLER_FILES} ${OBSERVER_PATTERN_FILES})

target_link_libraries(Gradius sfml-graphics sfml-window sfml-system)
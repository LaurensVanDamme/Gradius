cmake_minimum_required(VERSION 3.6)
project(Gradius)

set(CMAKE_CXX_STANDARD 14)


set(EVENT_FILES ObserverPattern/Events/Event.cpp ObserverPattern/Events/Event.h
        ObserverPattern/Events/Shot.cpp ObserverPattern/Events/Shot.h
        ObserverPattern/Events/UpdateY.cpp ObserverPattern/Events/UpdateY.h
        ObserverPattern/Events/UpdateX.cpp ObserverPattern/Events/UpdateX.h
        ObserverPattern/Events/Destroyed.cpp ObserverPattern/Events/Destroyed.h ObserverPattern/Events/AddedEntity.cpp ObserverPattern/Events/AddedEntity.h)

set(OBSERVER_PATTERN_FILES ${EVENT_FILES} ObserverPattern/Subject.cpp ObserverPattern/Subject.h
        ObserverPattern/Observer.cpp ObserverPattern/Observer.h )

set(MODEL_FILES Model/Model.h Model/Model.cpp
        Model/Entity.cpp Model/Entity.h
        Model/Ship.cpp Model/Ship.h
        Model/Bullet.cpp Model/Bullet.h
        Model/Obstacle.cpp Model/Obstacle.h
        Model/Border.cpp Model/Border.h
        Model/AIShip.cpp Model/AIShip.h Model/PlayerShip.cpp Model/PlayerShip.h)

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
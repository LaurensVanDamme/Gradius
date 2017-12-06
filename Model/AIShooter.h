//
// Created by laurens on 12/3/17.
//

#ifndef GRADIUS_AISHIP_H
#define GRADIUS_AISHIP_H

#include "Ship.h"

namespace Model {

    class AIShooter: public Ship {
    public:


        AIShooter();

        AIShooter(float x, float y, float width, float height, std::weak_ptr<World> world);


        void update(float time) override ;

    private:
        void checkCoorX() override;

        void checkCoorY() override;

        float lastTimeDown;
        float lastTimeUp;
        float yAcceleration;
        int timesUp;
        int timesDown;
        bool goingDown;
        bool goingUp;

    };

}


#endif //GRADIUS_AISHIP_H

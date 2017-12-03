//
// Created by laurens on 12/3/17.
//

#ifndef GRADIUS_AISHIP_H
#define GRADIUS_AISHIP_H

#include "Ship.h"

namespace Model {

    class AIShip: public Ship {
    public:
        AIShip();

        AIShip(double x, double y, float width, float height, float speed, unsigned int healt, float timePerShot);

        bool moveAndAttack(float time);

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

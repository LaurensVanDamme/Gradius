//
// Created by laurens on 11/27/17.
//

#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H

#include "ScrollingEntity.h"

namespace Model {

    class Obstacle: public ScrollingEntity {
    public:
        Obstacle();

        Obstacle(double x, double y, float height, float width, unsigned int damage);

        void scroll() override;

    private:

        virtual void checkCoorX() override;

    };

}


#endif //GRADIUS_OBSTACLE_H

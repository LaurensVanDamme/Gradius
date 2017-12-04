//
// Created by laurens on 11/27/17.
//

#ifndef GRADIUS_BORDER_H
#define GRADIUS_BORDER_H

#include "Obstacle.h"

namespace Model {

    class Border: public Obstacle {
    public:


        Border();

        Border(float x, float y, float height, float width);

    private:


        void checkCoorX() override;
    };

}



#endif //GRADIUS_BORDER_H

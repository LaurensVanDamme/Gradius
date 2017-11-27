//
// Created by laurens on 11/27/17.
//

#ifndef GRADIUS_BORDER_H
#define GRADIUS_BORDER_H

#include "Obstacle.h"

namespace Model {

    class Border: public Obstacle {
    public:

        void checkCoorX() override;

    private:

    };

}



#endif //GRADIUS_BORDER_H

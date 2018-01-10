//
// Created by laurens on 11/27/17.
//

#ifndef GRADIUS_BORDER_H
#define GRADIUS_BORDER_H

#include "Obstacle.h"

namespace Model {

    class Border: public Obstacle {
    public:

        /**
        * @brief Initialize a Model::Border object
        */
        Border()= default;

        Border(float x, float y, float height, float width);

    private:

        /**
        * @brief Check if the x coordinate is valid and change it if needed
        */
        void checkCoorX() override;
    };

}



#endif //GRADIUS_BORDER_H

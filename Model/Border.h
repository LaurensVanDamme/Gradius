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

        Border(double x, double y, float height, float width);


        const std::string &getType() const override;


        unsigned int getDamage() const override;

    private:


        void checkCoorX() override;
    };

}



#endif //GRADIUS_BORDER_H

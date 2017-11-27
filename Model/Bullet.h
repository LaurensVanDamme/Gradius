//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_BULLET_H
#define GRADIUS_BULLET_H

#include "ScrollingEntity.h"

namespace Model {

    class Bullet : public ScrollingEntity {
    public:

        Bullet();

        Bullet(double x, double y, float height, float width, unsigned int damage, float speed);

        void scroll() override;

    private:

        void checkCoorX() override;
    };

}


#endif //GRADIUS_BULLET_H

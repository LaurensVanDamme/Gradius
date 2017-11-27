//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_STATICENTITY_H
#define GRADIUS_STATICENTITY_H

#include "Entity.h"

namespace Model {

    class ScrollingEntity : public Entity {
    public:
        ScrollingEntity();

        ScrollingEntity(double x, double y, float height, float width, unsigned int damage);

        virtual void scroll()=0;

        unsigned int getDamage() const;

    private:

        virtual void checkCoorX()=0;

        unsigned int damage;

    protected:
        float scrollSpeed;
    };

}


#endif //GRADIUS_STATICENTITY_H

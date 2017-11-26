//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

namespace Model {

    class Ship;
    class Bullet;

    class Model {
    public:
        Ship *getPlayer();

        void setPlayer(double x, double y, float width, float height, float speed, unsigned int healt,
                       Bullet *bullettype = nullptr);

    private:
        Ship *player;

    };

}


#endif //GRADIUS_MODEL_H

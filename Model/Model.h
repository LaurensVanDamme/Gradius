//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include <vector>
using namespace std;

namespace Model {

    class Ship;
    class Bullet;

    class Model {
    public:
        Ship *getPlayer();

        void setPlayer(double x, double y, float width, float height, float speed, unsigned int healt,
                       Bullet *bullettype = nullptr);

        void addBullet(float speed, float timePerShot, unsigned int damage);

        void checkForDestroyed();

        Bullet * getLastBullet() const;

    private:
        Ship *player;
        vector<Bullet*> bullets;
    };

}

#endif //GRADIUS_MODEL_H

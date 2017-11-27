//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include <vector>
using namespace std;

namespace Model {

    class Ship;
    class ScrollingEntity;

    class Model {  // Vergeet deconstructor ni!!!
    public:
        Ship *getPlayer();

        void setPlayer(double x, double y, float width, float height, float speed, unsigned int healt,
                       float timePerShot);

        ScrollingEntity* addBullet(unsigned int damage, float speed);

        ScrollingEntity* addBorder();

        bool checkForDestroyed();

        void updateWorld(float totalTime);



    private:
        Ship *player;
        vector<ScrollingEntity*> scrollingEntities;
    };

}

#endif //GRADIUS_MODEL_H

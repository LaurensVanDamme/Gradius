//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

namespace Model {

    class Ship;

    class Model {
    public:
        Ship *getPlayer();

        void setPlayer(Ship *player);

    private:
        Ship *player;

    };

}


#endif //GRADIUS_MODEL_H

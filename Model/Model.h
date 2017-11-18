//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

class Ship;

class Model {
public:

private:
    Ship* player;
public:
    Ship *getPlayer();

    void setPlayer(Ship *player);
};


#endif //GRADIUS_MODEL_H

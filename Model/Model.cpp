//
// Created by laurens on 11/18/17.
//

#include "Model.h"

Ship *Model::getPlayer() {
    return player;
}

void Model::setPlayer(Ship *player) {
    Model::player = player;
}

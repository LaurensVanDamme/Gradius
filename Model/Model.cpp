//
// Created by laurens on 11/18/17.
//

#include "Model.h"

Model::Ship *Model::Model::getPlayer() {
    return player;
}

void Model::Model::setPlayer(Ship *player) {
    this->player = player;
}

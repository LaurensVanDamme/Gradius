//
// Created by laurens on 11/23/17.
//

#include "Observer.h"

Observer::Observer() {

}

Observer::Observer(std::weak_ptr<Model::Entity> subject): subject(subject) {

}

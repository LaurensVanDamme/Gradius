//
// Created by laurens on 11/23/17.
//

#ifndef GRADIUS_OBSERVER_H
#define GRADIUS_OBSERVER_H

#include "../Model/Entity.h"
#include <memory>

class Subject;

class Observer {
public:
    Observer();
    Observer(std::weak_ptr<Model::Entity> subject);

    virtual void updateXCoor()=0;

    virtual void updateYCoor()=0;

    virtual void updateDestroyed()=0;

protected:
    std::weak_ptr<Model::Entity> subject;
};


#endif //GRADIUS_OBSERVER_H

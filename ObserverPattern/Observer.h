//
// Created by laurens on 11/23/17.
//

#ifndef GRADIUS_OBSERVER_H
#define GRADIUS_OBSERVER_H

#include "Event.h"
#include <memory>

namespace OP { // Observer Pattern

    class Subject;

    class Observer: public std::enable_shared_from_this<Observer> {
    public:
        Observer();

        Observer(std::weak_ptr<Subject> subject);

        virtual void update(Event& event)=0;

    protected:
        std::weak_ptr<Subject> subject;
    };

}


#endif //GRADIUS_OBSERVER_H

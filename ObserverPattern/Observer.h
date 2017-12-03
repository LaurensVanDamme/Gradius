//
// Created by laurens on 11/23/17.
//

#ifndef GRADIUS_OBSERVER_H
#define GRADIUS_OBSERVER_H

#include "Events/Event.h"
#include <memory>

namespace OP { // Observer Pattern

    class Subject;

    class Observer {
    public:
        Observer();

        Observer(std::weak_ptr<Subject> subject);

        virtual void update(std::shared_ptr<Event::Event> event)=0;

    protected:
        std::weak_ptr<Subject> subject;
    };

}


#endif //GRADIUS_OBSERVER_H

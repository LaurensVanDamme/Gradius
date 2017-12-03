//
// Created by laurens on 11/23/17.
//

#ifndef GRADIUS_SUBJECT_H
#define GRADIUS_SUBJECT_H

#include "Events/Event.h"
#include <memory>
#include <vector>

namespace OP {  // Observer Pattern

    class Observer;

    class Subject {
    public:
        Subject();

        void attach(std::weak_ptr<Observer> observer);

        void notify(std::shared_ptr<Event::Event> event) const;

        virtual ~Subject();

    private:
        std::vector<std::weak_ptr<Observer>> observers;
    };

}


#endif //GRADIUS_SUBJECT_H

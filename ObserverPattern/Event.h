//
// Created by laurens on 12/3/17.
// Based on the events of SFML
//

#ifndef GRADIUS_EVENT_H
#define GRADIUS_EVENT_H

#include <memory>

namespace Model {
    class Entity;
}

namespace OP {

    class Event {
    public:

        ////////////////////////////////////////////////////////////
        /// \brief Added item event parameters (AddedEntity)
        ///
        ////////////////////////////////////////////////////////////
        struct AddingEntityEvent {
            std::shared_ptr<Model::Entity> entity;
        };

        ////////////////////////////////////////////////////////////
        /// \brief Enumeration of the different types of events
        ///
        ////////////////////////////////////////////////////////////
        enum EventType {
            UpdateX,        ///< The subject requested to update the x coordinate
            UpdateY,        ///< The subject requested to update the y coordinate
            Destroyed,      ///< The subject notified that he is destroyed
            AddedEntity     ///< The subject requested to create an view entity
        };

        EventType type; ///< Type of the event

        union {
            AddingEntityEvent addedEntity;      ///< Added item event parameters (Event::AddedEntity)
        };

        Event(Event::EventType type): type(type), addedEntity{} {}

        virtual ~Event() {}
    };

}


#endif //GRADIUS_EVENT_H

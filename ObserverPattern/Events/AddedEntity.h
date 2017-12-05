//
// Created by laurens on 12/3/17.
//

#ifndef GRADIUS_ADDEDENTITY_H
#define GRADIUS_ADDEDENTITY_H

#include "../Event.h"
#include <memory>

namespace OP {

    class Subject;

    namespace Event {

        class AddedEntity: public Event {
        public:
            AddedEntity();

            AddedEntity(const std::shared_ptr<Subject> &entity);

            const std::shared_ptr<Subject> getEntity() const;

        private:
            std::shared_ptr<Subject> entity;
        };

    }

}


#endif //GRADIUS_ADDEDENTITY_H

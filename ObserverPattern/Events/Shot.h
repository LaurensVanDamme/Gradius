//
// Created by laurens on 12/3/17.
//

#ifndef GRADIUS_EVENTSHOT_H
#define GRADIUS_EVENTSHOT_H

#include "Event.h"

namespace OP {

    namespace Event {

        class Shot : public Event {
        public:
            Shot();

            Shot(float x, float y, bool AI);

            float getX() const;

            float getY() const;

            bool isAI() const;

        private:
            float x;
            float y;
            bool AI;
        };

    }

}


#endif //GRADIUS_EVENTSHOT_H

//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H

#include <ctime>
#include "../Singleton.h"

namespace Ctrl {

    class Stopwatch: public Singleton<Stopwatch> {
        friend class Singleton<Stopwatch>;
    private:
        Stopwatch();

    public:
/**
\n    Updates the totalTime etc and returns if the program can do another tick
*/
        bool updateAndCheck();

/**
\n    Returns the totalTickTime before the substraction of timePerTick
*/
        float getTotalTickTime() const;

/**
\n    Returns the totalTime the program is running
*/
        float getTotalTime() const;

    private:
        float timePerTick = 0.030; // Seconds per tick/frame
        float deltaTime;
        float totalTickTime;
        float totalTime;
        float formalTotalTickTime;
        std::clock_t lastTime;
    };

}


#endif //GRADIUS_STOPWATCH_H

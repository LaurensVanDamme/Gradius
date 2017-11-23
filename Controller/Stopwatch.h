//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H

#include <ctime>

namespace Ctrl {

    class Stopwatch {
    private:
        Stopwatch();

    public:
/**
\n    Creates or returns the only stopwatch (singleton)
*/
        static Stopwatch *getStopwatch();

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
        static Stopwatch *instance;

        float timePerTick = 0.030;
        float deltaTime;
        float totalTickTime;
        float totalTime;
        float formalTotalTickTime;
        std::clock_t lastTime;
    };

}


#endif //GRADIUS_STOPWATCH_H

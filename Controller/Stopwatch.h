//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H

#include "../Singleton.h"
#include <ctime>

namespace Ctrl {

    class Stopwatch: public Singleton<Stopwatch> {
        friend class Singleton<Stopwatch>;
    private:
        Stopwatch();

    public:
/**
* @brief Updates the stopwatch and returns if the program can continue
*/
        bool updateAndCheck();

/**
* @brief Returns the totalTickTime before the subtraction of timePerTick
*/
        float getTotalFrameTime() const;

/**
* @brief Returns the totalTime the program is running
*/
        float getTotalTime() const;

    private:
        float timePerFrame = 0.030; // Seconds per tick/frame
        float deltaTime;
        float totalFrameTime;
        float totalTime;
        float formalTotalFrameTime;
        std::clock_t lastTime;
    };

}


#endif //GRADIUS_STOPWATCH_H

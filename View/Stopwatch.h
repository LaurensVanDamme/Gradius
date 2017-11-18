//
// Created by laurens on 11/18/17.
//

#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H


class Stopwatch {
public:
/**
\n    Updates te the time this machine need per tick
*/
    void updateTimePerTick(float timePerTick);

/**
\n    Returns the time this machine needs per tick
*/
    float getTimePerTick();

private:
    float timePerTick;
};


#endif //GRADIUS_STOPWATCH_H

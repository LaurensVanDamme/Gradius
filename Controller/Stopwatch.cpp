//
// Created by laurens on 11/18/17.
//

#include "Stopwatch.h"

Stopwatch* Stopwatch::instance = nullptr;

Stopwatch::Stopwatch() {
    lastTime = std::clock();
    totalTime = 0;
}

bool Stopwatch::updateAndCheck() {
    deltaTime = float(clock() - lastTime) / CLOCKS_PER_SEC;  // Get the amount of seconds for the last while loop
    lastTime = clock();
    totalTime += deltaTime; // Add the deltaTime to the totalTime
    formalTotalTime = totalTime;
    // If totalTime s bigger then timePerTick we can proceed with the program so it returns 1
    if (totalTime < timePerTick){
        return false;
    } else {
        totalTime -= timePerTick;  // Reset the totalTime
        return true;
    }
}

Stopwatch *Stopwatch::getStopwatch() {  // Make sure that there can only be one stopwatch
    if (!instance){
        Stopwatch::instance = new Stopwatch;
    }
    return Stopwatch::instance;
}

float Stopwatch::getTotalTime() {
    return formalTotalTime;
}

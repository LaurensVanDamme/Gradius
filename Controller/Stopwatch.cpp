//
// Created by laurens on 11/18/17.
//

#include "Stopwatch.h"

Ctrl::Stopwatch* Ctrl::Stopwatch::instance = nullptr;

Ctrl::Stopwatch::Stopwatch() {
    lastTime = std::clock();
    totalTime = 0;
}

bool Ctrl::Stopwatch::updateAndCheck() {
    deltaTime = float(clock() - lastTime) / CLOCKS_PER_SEC;  // Get the amount of seconds for the last while loop
    lastTime = clock();
    totalTime += deltaTime; // Add the deltaTime to the totalTime
    totalTickTime += deltaTime;
    formalTotalTickTime = totalTickTime;
    // If totalTime s bigger then timePerTick we can proceed with the program so it returns 1
    if (totalTickTime < timePerTick){
        return false;
    } else {
        totalTickTime -= timePerTick;  // Reset the totalTime
        return true;
    }
}

Ctrl::Stopwatch* Ctrl::Stopwatch::getStopwatch() {  // Make sure that there can only be one stopwatch
    if (!instance){
        Stopwatch::instance = new Stopwatch;
    }
    return Stopwatch::instance;
}

float Ctrl::Stopwatch::getTotalTickTime() const{
    return formalTotalTickTime;
}

float Ctrl::Stopwatch::getTotalTime() const {
    return totalTime;
}

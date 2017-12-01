//
// Created by laurens on 11/18/17.
//

#include "Stopwatch.h"

Ctrl::Stopwatch::Stopwatch() {
    lastTime = std::clock();
    totalTime = 0;
}

bool Ctrl::Stopwatch::updateAndCheck() {
    float deltaTime = float(clock() - lastTime) / CLOCKS_PER_SEC;  // Get the amount of seconds for the last while loop
    lastTime = clock();
    totalTime += deltaTime; // Add the deltaTime to the totalTime
    totalFrameTime += deltaTime;
    formalTotalFrameTime = totalFrameTime;
    // If totalTime is bigger than timePerFrame we can proceed with the program so it returns 1
    if (totalFrameTime < timePerFrame){
        return false;
    } else {
        totalFrameTime -= timePerFrame;  // Reset the totalFrameTime
        return true;
    }
}

float Ctrl::Stopwatch::getTotalFrameTime() const{
    return formalTotalFrameTime;
}

float Ctrl::Stopwatch::getTotalTime() const {
    return totalTime;
}

//
// Created by laurens on 11/15/17.
// Based on: https://www.youtube.com/watch?v=kAZVbPF6N4Q
//

#include "Animation.h"

View::Animation::Animation(std::shared_ptr<sf::Texture> texture, sf::Vector2u imageCount, float switchtime):
        imageCount(imageCount), switchTime(switchtime) {
    this->totalTime = 0.0;  // Initialize the time at 0 sec
    currentImage.x = 0;  // Always start with the first image
    // Calculate the height and width for the rectangle that is to be displayed
    uvRect.width = texture->getSize().x / (float)(imageCount.x);
    uvRect.height = texture->getSize().y / (float)(imageCount.y);
}

void View::Animation::update(unsigned int row, float deltaTime) {
    currentImage.y = row;  // Specify which row of animation will be used
    totalTime += deltaTime;  // Make sure the animation goes everywhere at the same speed
    // If it's time to switch to the next picture
    if  (totalTime >= switchTime){
        totalTime -= switchTime; // Reset the totalTime
        currentImage.x++;  // Take the next picture in the row
        // If it tries to take a picture that is outside the texture
        if (currentImage.x >= imageCount.x){
            currentImage.x = 0;  // Take the first picture again
        }
    }
    // Put the picture in the rectangle that will be displayed
    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}

const sf::IntRect &View::Animation::getUvRect() const {
    return uvRect;
}

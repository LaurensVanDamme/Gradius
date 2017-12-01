//
// Created by laurens on 11/15/17.
// Based on: https://www.youtube.com/watch?v=kAZVbPF6N4Q
//

#ifndef GRADIUS_ANIMATION_H
#define GRADIUS_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace View {

    class Animation {
    public:
        Animation();

        Animation(sf::Texture& texture, sf::Vector2u imageCount, float switchtime);

        void update(unsigned int row, float deltaTime);

    public:
        sf::IntRect uvRect;
    private:
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        float totalTime;
        float switchTime;
    };

}


#endif //GRADIUS_ANIMATION_H

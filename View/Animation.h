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

    /**
    * @brief Initialize an View::Animation object
    */
        Animation();

        Animation(std::shared_ptr<sf::Texture> texture, sf::Vector2u imageCount, float switchtime);

    /**
    * @brief Returns the uvRect variable
    */
        const sf::IntRect &getUvRect() const;

    /**
    * @brief Updates the animation
    */
        void update(unsigned int row, float deltaTime);

    private:
        sf::IntRect uvRect;
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        float totalTime;
        float switchTime;
    };

}


#endif //GRADIUS_ANIMATION_H

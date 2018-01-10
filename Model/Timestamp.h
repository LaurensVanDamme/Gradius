//
// Created by laurens on 1/2/18.
//

#ifndef GRADIUS_TIMESTAMP_H
#define GRADIUS_TIMESTAMP_H

#include <vector>
#include <string>

namespace Model {
    class Timestamp {
    public:

        /**
        * @brief Initialize a Model::Timestamp object
        */
        Timestamp()= default;

        Timestamp(float time, std::vector<std::string>& types, std::vector<std::vector<float>>& numbers);

        /**
        * @brief Returns the time when the timestamp must be added to the world
        */
        float getTime() const;

        /**
        * @brief Returns the vector with the types of the entities
        */
        const std::vector<std::string> &getTypes() const;

        /**
        * @brief Returns the vector with the vectors which contain the numbers needed to create the entities
        */
        const std::vector<std::vector<float>> &getNumbers() const;

    private:
        float time{};
        std::vector<std::string> types;
        std::vector<std::vector<float>> numbers;
    };

}

#endif //GRADIUS_TIMESTAMP_H

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
        Timestamp()= default;
        Timestamp(float time, std::vector<std::string>& types, std::vector<std::vector<float>>& numbers);

        float getTime() const;

        const std::vector<std::string> &getTypes() const;

        const std::vector<std::vector<float>> &getNumbers() const;

    private:
        float time;
        std::vector<std::string> types;
        std::vector<std::vector<float>> numbers;
    };

}

#endif //GRADIUS_TIMESTAMP_H

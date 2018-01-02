//
// Created by laurens on 1/2/18.
//

#include "Timestamp.h"

Model::Timestamp::Timestamp(float time, std::vector<std::string>& types, std::vector<std::vector<float>>& numbers):
        time(time), types(types), numbers(numbers) {

}

float Model::Timestamp::getTime() const {
    return time;
}

const std::vector<std::string> &Model::Timestamp::getTypes() const {
    return types;
}

const std::vector<std::vector<float>> &Model::Timestamp::getNumbers() const {
    return numbers;
}

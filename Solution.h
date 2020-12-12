//
// Created by Tim on 18.11.2020.
//
#include <iostream>
#include <vector>
#include <ctime>
#include <string>

#ifndef GA_FOLDING_SOLUTION_H
#define GA_FOLDING_SOLUTION_H

enum direction {
    LEFT, UP, RIGHT, DOWN
};
enum polarityStatus {
    HYDROPHILIC, HYDROPHOBIC, NONE
};

class Solution {
public:
    explicit Solution(int inLength);

    explicit Solution(std::string inputString);

    int chainLength;
    std::vector<direction> directions;
    std::vector<polarityStatus> polarity;
private:
};

#endif //GA_FOLDING_SOLUTION_H

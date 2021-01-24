//
// Created by Tim on 18.11.2020.
//
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <array>
#include <random>
#include <iomanip>

#ifndef GA_FOLDING_SOLUTION_H
#define GA_FOLDING_SOLUTION_H
#define gridType std::array<std::array<polarityStatus, 28>, 28>

using namespace std;

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

    float computeFitness();

    int chainLength;
    std::vector<direction> directions;
    std::vector<polarityStatus> polarity;
private:
};

#endif //GA_FOLDING_SOLUTION_H

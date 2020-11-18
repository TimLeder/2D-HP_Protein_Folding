//
// Created by Tim on 18.11.2020.
//
#include <iostream>
#include <vector>
#include <ctime>
#ifndef GA_FOLDING_SOLUTION_H
#define GA_FOLDING_SOLUTION_H

enum direction {LEFT, UP, RIGHT, DOWN};
enum polarityStatus {HYDROPHILIC, HYDROPHOBIC, NONE};

class Solution{
public:
    Solution() {
        //populate with random directions
        srand(time(0));
        for(int i = 0; i < chainLength; i++)
        {
            directions.push_back(static_cast<direction>(rand() % 4));
            polarity.push_back(static_cast<polarityStatus>(rand() % 2));
        }
    };
    int chainLength = 32;
    std::vector<direction> directions;
    std::vector<polarityStatus> polarity;
private:
};

#endif //GA_FOLDING_SOLUTION_H

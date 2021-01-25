//
// Created by Tim on 18.11.2020.
//
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <array>
#include <random>
#include <algorithm>
#include <iomanip>
#include <windows.h>
#include <fstream>

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
    explicit Solution();
    explicit Solution(int inLength);
    explicit Solution(std::string inputString);

    float computeFitness();
    void printSolution();
    int getOverlap();
    void mutateSolution(float mutF);

    bool operator> (const Solution &s1) const {
        return this->slFitness > s1.slFitness;
    }

    bool operator< (const Solution &s1) const {
        return this->slFitness < s1.slFitness;
    }

    int chainLength;
    std::vector<direction> directions;
    std::vector<polarityStatus> polarity;
    float slFitness;
    int slOverlaps;
private:
};

#endif //GA_FOLDING_SOLUTION_H

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
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include "bitmap_image.hpp"
#include <iterator>
#include <fstream>

#ifndef GA_FOLDING_SOLUTION_H
#define GA_FOLDING_SOLUTION_H
#define gridType std::array<std::array<polarityStatus, 32>, 32>
#define indexGridType std::array<std::array<int, 32>, 32>

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
    void renderSolution(int);
    int getOverlap();
    void mutateSolution(float mutF);
    void cross(Solution, int);
    vector<direction> split(vector<direction>, int);

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

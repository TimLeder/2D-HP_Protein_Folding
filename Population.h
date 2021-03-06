//
// Created by Tim on 11.12.2020.
//
#include <vector>
#include "Solution.h"
#include <array>

#ifndef GA_FOLDING_POPULATION_H
#define GA_FOLDING_POPULATION_H

class Population {
public:
    explicit Population(int, string);

    float computePopFitness();
    Population fpSelect();
    Population tournamentSelectI(int k);
    Population tournamentSelectF(float t);
    void printBestSolution();
    void drawBestSolution(int);
    float averageFitness();
    Solution bestSolution();
    void mutatePop(float mutF);
    void crossoverPop(float crossF);

    std::vector<Solution> populationVector;
    int populationSize;
    float populationFitness;
private:
};

#endif //GA_FOLDING_POPULATION_H

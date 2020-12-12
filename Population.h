//
// Created by Tim on 11.12.2020.
//
#include <vector>
#include "Solution.h"

#ifndef GA_FOLDING_POPULATION_H
#define GA_FOLDING_POPULATION_H

class Population {
public:
    explicit Population(int);

    std::vector<Solution> populationVector;
    int populationSize;
private:
};

#endif //GA_FOLDING_POPULATION_H

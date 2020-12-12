//
// Created by Tim on 11.12.2020.
//

#include "Population.h"
#include "Solution.h"

Population::Population(int inPopSize) {
    populationSize = inPopSize;
    for (auto i = 0; i < populationSize; i++) {
        populationVector.push_back(Solution("11010101011110100010001000010001000101111010101011"));
    }
}


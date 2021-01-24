//
// Created by Tim on 11.12.2020.
//

#include "Population.h"
#include "Solution.h"

Population::Population(int inPopSize) {
    populationSize = inPopSize;
    for (auto i = 0; i < populationSize; i++) {
        populationVector.emplace_back("11010101011110100010001000010001000101111010101011");
    }
    for(int i = 0; i < populationVector.size(); i++) {
        populationVector[i].computeFitness();
    }
}

float Population::computePopFitness() {
    float totalPopFitness;
    for(unsigned i = 0; i < populationVector.size(); i++) {
        totalPopFitness = totalPopFitness + populationVector[i].computeFitness();
    }
    populationFitness = totalPopFitness;
    cout << endl << "Total Population Fitness: " << totalPopFitness << endl;
    for(unsigned i = 0; i < populationVector.size(); i++) {
        cout << "Solution " << i << ": " << populationVector[i].computeFitness() / totalPopFitness << " | " << populationVector[i].computeFitness() << endl;
    }
}

Population Population::select() {
    /*std::vector<Solution> populationCopy = populationVector;
    std::vector<Solution> newPopulationVector = populationVector;
    auto rand_num = static_cast<float>(rand() / static_cast <float> (RAND_MAX/populationFitness));
    cout << rand_num;
    int select;
    for(int j = 0; j < populationVector.size(); j++) {
        for(int i = 0; i < populationVector.size(); i++) {
            if(rand_num < populationVector[i].computeFitness()) {
                select = i;
            }
            rand_num = rand_num - populationVector[i].computeFitness();
        }
        newPopulationVector[j] = populationVector[select];
    }
    populationVector = newPopulationVector;

    }*/
    return *this;
}

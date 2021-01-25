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
        cout << "Solution " << i << ": " << populationVector[i].computeFitness() / totalPopFitness
        << " | " << populationVector[i].computeFitness() << endl;
    }
}

Population Population::fpSelect() {
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
        newPopulationVector[j] = populationVector[fpSelect];
    }
    populationVector = newPopulationVector;

    }*/
    vector<float>weightVector;
    for(unsigned i = 0; i < populationVector.size(); i++) {
        weightVector.push_back(populationVector[i].computeFitness() / populationFitness);
    }
    vector<Solution>copyPopulationVector = populationVector;
    default_random_engine rdGen;
    discrete_distribution<int>distribution(weightVector.begin(), weightVector.end());
    for(unsigned i = 0; i < populationVector.size(); i++) {
        int rndSelect = distribution(rdGen);
        populationVector[i] = copyPopulationVector[rndSelect];
    }
    return *this;
}

void Population::printBestSolution() {
    auto printThis = max_element(begin(populationVector), end(populationVector));
    printThis->printSolution();
}

void Population::mutatePop(float mutF) {
    for(unsigned i = 0; i < populationVector.size(); i++) {
        populationVector[i].mutateSolution(mutF);
    }
}

float Population::averageFitness() {
    return populationFitness / static_cast<float>(populationSize);
}

Solution Population::bestSolution() {
    auto best = max_element(begin(populationVector), end(populationVector));
    return *best;
}

void Population::crossoverPop(float crossF) {
    float rndFloat = static_cast<float> (rand()) / static_cast<float>(RAND_MAX);
    if (rndFloat < crossF) {
        int crossCandidate1 = rand() % populationVector.size();
        int crossCandidate2 = rand() % populationVector.size();
        int crossIndex = rand() % populationVector[crossCandidate1].directions.size();

        populationVector[crossCandidate1].cross(populationVector[crossCandidate2], crossIndex);
    }
}

Population Population::tournamentSelect() {
    return Population(0);
}

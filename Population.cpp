//
// Created by Tim on 11.12.2020.
//

#include "Population.h"
#include "Solution.h"

Population::Population(int inPopSize, string input_string) {
    populationSize = inPopSize;
    for (auto i = 0; i < populationSize; i++) {
        populationVector.emplace_back(input_string);
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
    /*cout << endl << "Total Population Fitness: " << totalPopFitness << endl;
    for(unsigned i = 0; i < populationVector.size(); i++) {
        cout << "Solution " << i << ": " << populationVector[i].computeFitness() / totalPopFitness
        << " | " << populationVector[i].computeFitness() << endl;
    }*/
    return populationFitness;
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

Population Population::tournamentSelectI(int k) {

    vector<Solution>oldPopVector = populationVector;
    for(unsigned i = 0; i < populationVector.size(); i++) { //Für jedes Element im neuen Vektor
        vector<Solution>tournamentVector;
        for(int j = 0; j < k; j++) { //Wähle K Elemente aus altem Vektor aus
            tournamentVector.push_back(oldPopVector[rand() % oldPopVector.size()]);
        }
        float rndFloat = static_cast<float> (rand()) / static_cast<float>(RAND_MAX);
        Solution winner;
        for(int j = 0; j < tournamentVector.size(); j++) {
            if(rndFloat < tournamentVector[j].computeFitness() && winner.computeFitness() < tournamentVector[j].computeFitness()) {
                winner = tournamentVector[j];
            }
        }
        populationVector[i] = winner;
    }

    return *this;
}

void Population::drawBestSolution(int in) {
    auto printThis = max_element(begin(populationVector), end(populationVector));
    printThis->renderSolution(in);
}

Population Population::tournamentSelectF(float t) {
    const int COMPETITORS = 2;
    vector<Solution>oldPopVector = populationVector;
    for(unsigned i = 0; i < populationVector.size(); i++) { //Für jedes Element im neuen Vektor
        vector<Solution>tournamentVector;
        for(int j = 0; j < COMPETITORS; j++) { //Wähle 2 Elemente aus altem Vektor aus
            tournamentVector.push_back(oldPopVector[rand() % oldPopVector.size()]);
        }
        float rndFloat = static_cast<float> (rand()) / static_cast<float>(RAND_MAX);
        Solution winner;

        if(rndFloat < t) {
            //kandidat mit besserer fitness gewinnt
            winner = *max_element(begin(tournamentVector), end(tournamentVector));
        }
        else {
            //kandidat mit schlechtere fitness gewinnt
            winner = *min_element(begin(tournamentVector), end(tournamentVector));
        }

        populationVector[i] = winner;
    }

    return *this;
}

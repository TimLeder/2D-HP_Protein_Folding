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
        cout << populationVector[i].computeFitness();
    }
}

/*float Population::computePopFitness(gridType grid, int chainLength) {
    for(unsigned j = 0; j < populationVector.size(); j++) {
        int countHydrophilic = 0;
        int countHydrophobic = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int k = 0; k < grid.size(); k++) {
                switch (grid[i][k]) {
                    case HYDROPHILIC: {
                        countHydrophilic++;
                        break;
                    }
                    case HYDROPHOBIC: {
                        countHydrophobic++;
                        break;
                    }
                }
            }
        }
        int totalAcids = countHydrophilic + countHydrophobic;
        int overlaps = chainLength - totalAcids;
        int contacts = 0;

        for (int i = 0; i < grid.size() - 1; i++) {
            for (int k = 0; k < grid.size() - 1; k++) {
                if (grid[i][k] == HYDROPHOBIC) {
                    if (grid[i][k + 1] == HYDROPHOBIC) {
                        contacts++;
                    }
                    if (grid[i + 1][k] == HYDROPHOBIC) {
                        contacts++;
                    }
                }
            }
        }
        int weightedOverlaps = overlaps / 5;
        float output = contacts - weightedOverlaps;
        if (output < 0)
            output = 0;
        populationVector[j].solutionFitness = output;
    }
}*/
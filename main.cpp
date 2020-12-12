#include <iostream>
#include "Solution.h"
#include "Population.h"
#include <array>
#include <iomanip>

#define gridType array<array<polarityStatus, 28>, 28>

const int MAXGENERATIONS = 100;

using namespace std;

float computeFitness(gridType grid, int chainLength);

stringstream printGrid(gridType grid);

int main() {
    int generation = 0;
    gridType grid{};
    //Solution test = Solution(32);
    Solution test = Solution("11010101011110100010001000010001000101111010101011");

    int currentX = grid.size() / 2;
    int currentY = grid.size() / 2;

    for (int i = 0; i < grid.size(); i++) {
        for (int k = 0; k < grid.size(); k++) {
            grid[i][k] = NONE;
        }
    }

    for (int i = 0; i < test.chainLength; i++) {
        switch (test.directions[i]) {
            case LEFT: {
                currentX--;
                break;
            }
            case UP: {
                currentY++;
                break;
            }
            case RIGHT: {
                currentX++;
                break;
            }
            case DOWN: {
                currentY--;
                break;
            }
        }
        grid[currentX][currentY] = test.polarity[i];
    }

    cout << printGrid(grid).str() << endl;
    cout << computeFitness(grid, test.chainLength) << setprecision(4) << endl;

}

stringstream printGrid(gridType inGrid) {
    stringstream outstream;
    for (int i = 0; i < inGrid.size(); i++) {
        for (int k = 0; k < inGrid.size(); k++) {
            switch (inGrid[i][k]) {
                case HYDROPHILIC: {
                    outstream << "[+] ";
                    break;
                }
                case HYDROPHOBIC: {
                    outstream << "[-] ";
                    break;
                }
                case NONE: {
                    outstream << "[ ] ";
                    break;
                }
            }
        }
    }
    return outstream;
}

float computeFitness(gridType grid, int chainLength) {
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
    return output;
}
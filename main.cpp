#include <iostream>
#include "Solution.h"
#include <array>

using namespace std;

float computeFitness(array<array<polarityStatus, 32>, 32> grid, int chainLength);

int main() {
    array<array<polarityStatus, 32>, 32> grid;
    Solution test = Solution();

    int currentX = grid.size() / 2;
    int currentY = grid.size() / 2;

    for(int i = 0; i < grid.size(); i++){
        for(int k = 0; k < grid.size(); k++) {
            grid[i][k] = NONE;
        }
    }

    for(int i = 0; i < test.chainLength; i++) {
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

    cout << "\n";
    for(int i = 0; i < grid.size(); i++){
        for(int k = 0; k < grid.size(); k++) {
            switch (grid[i][k]) {
                case HYDROPHILIC: {
                    cout << "[+] ";
                    break;
                }
                case HYDROPHOBIC: {
                    cout << "[-] ";
                    break;
                }
                case NONE: {
                    cout << "[ ] ";
                    break;
                }
            }
        }
        cout << "\n";
    }

    cout << computeFitness(grid, test.chainLength);

}

float computeFitness(array<array<polarityStatus, 32>, 32> grid, int chainLength) {
    int countHydrophilic = 0;
    int countHydrophobic = 0;
    for(int i = 0; i < grid.size(); i++) {
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

    for(int i = 0; i < grid.size()-1; i++) {
        for (int k = 0; k < grid.size()-1; k++) {
            if(grid[i][k] == HYDROPHOBIC) {
                if(grid[i][k+1] == HYDROPHOBIC) {
                    contacts++;
                }
                if(grid[i+1][k] == HYDROPHOBIC) {
                    contacts++;
                }
            }
        }
    }
    int weightedOverlaps = overlaps * 5;
    float output = contacts - overlaps;
    if(output < 0)
        output = 0;
    return output;
}
//
// Created by Tim on 18.11.2020.
//
#include "Solution.h"

Solution::Solution(int inLength) {
    //populate with random directions
    chainLength = inLength;
    for (int i = 0; i < chainLength; i++) {
        directions.push_back(static_cast<direction>(rand() % 4));
        polarity.push_back(static_cast<polarityStatus>(rand() % 2));
    }
};

Solution::Solution(std::string inputString) {
    //populate with parameter string
    chainLength = inputString.length();
    for (int i = 0; i < chainLength; i++) {
        directions.push_back(static_cast<direction>(rand() % 4));
        switch (inputString[i]) {
            case '0':
                polarity.push_back(HYDROPHILIC);
                break;
            case '1':
                polarity.push_back(HYDROPHOBIC);
                break;
            default:
                std::cout << "Invalid character in input string\n";
                exit(EXIT_FAILURE);
        }
    }
}

float Solution::computeFitness() {
    gridType grid{};

    int currentX = grid.size() / 2;
    int currentY = grid.size() / 2;

    for (int i = 0; i < grid.size(); i++) {
        for (int k = 0; k < grid.size(); k++) {
            grid[i][k] = NONE;
        }
    }

    for (int i = 0; i < chainLength; i++) {
        switch (directions[i]) {
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
        grid[currentX][currentY] = polarity[i];
    }

    /*cout << "\n";
    for (int i = 0; i < grid.size(); i++) {
        for (int k = 0; k < grid.size(); k++) {
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
    }*/

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
    float overlaps = chainLength - totalAcids;
    float contacts = 0;

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
    float weightedOverlaps = overlaps + 1;
    float output = contacts / weightedOverlaps;
    if (output < 0)
        output = 0;
    //cout << "FITNESS: " << output << endl;
    return output;
}
//
// Created by Tim on 18.11.2020.
//
#include "Solution.h"

Solution::Solution(int inLength) {
    //populate with random directions
    chainLength = inLength;
    srand(time(0));
    for (int i = 0; i < chainLength; i++) {
        directions.push_back(static_cast<direction>(rand() % 4));
        polarity.push_back(static_cast<polarityStatus>(rand() % 2));
    }
};

Solution::Solution(std::string inputString) {
    //populate with parameter string
    chainLength = inputString.length();
    srand(time(0));
    for (int i = 0; i < chainLength; i++) {
        directions.push_back(static_cast<direction>(rand() % 4));
        switch (inputString[i]) {
            case '0':
                polarity.
                        push_back(HYDROPHILIC);
                break;
            case '1':
                polarity.
                        push_back(HYDROPHOBIC);
                break;
            default:
                std::cout << "Invalid character in input string\n";
                exit(EXIT_FAILURE);
        }
    }
}
//
// Created by nordi on 5/5/2022.
//

#include <vector>
#include "findNotVisited.h"
#include "CONSTANTS.h"

int findNotVisited(std::vector<bool> &visitedList) {
    for (int i = 0; i < visitedList.size(); i++) {
        if (!visitedList[i])
            return i;//found an invalid node
    }
    return CONSTANTS::ALL_VISITED;
}
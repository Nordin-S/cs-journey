//
// Created by nordi on 5/4/2022.
//

#include <vector>
#include "dfs.h"
#include "CONSTANTS.h"

void dfs(int givenNode, std::vector<bool> &isVisited, std::vector<std::vector<double>> matrix) {
    isVisited[givenNode] = true;
    //can all nodes be reached from a given node
    for (int i = 0; i < isVisited.size(); i++) {
        if (matrix[givenNode][i] != CONSTANTS::NO_EDGE && !isVisited[i])
            dfs(i, isVisited, matrix);
    }
}
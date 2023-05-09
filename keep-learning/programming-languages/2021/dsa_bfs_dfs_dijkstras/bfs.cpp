//
// Created by nordi on 5/5/2022.
//

#include "bfs.h"
#include "CONSTANTS.h"

void bfs(std::queue<int> q, std::vector<bool> &isVisited, std::vector<std::vector<double>> matrix) {
    if (q.empty())
        return;

    int currentNode = q.front();
    q.pop();

    // add every edge of current node that has a weight, and it's destination is not visited to que
    // and let the pulsating begin
    for (int i = 0; i < isVisited.size(); i++) {
        if (matrix[currentNode][i] != CONSTANTS::NO_EDGE && !isVisited[i]) {
            isVisited[i] = true;
            q.push(i);
        }
    }
    bfs(q, isVisited, matrix);
}

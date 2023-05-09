//
// Created by nordi on 5/4/2022.
//
#include "adjToMatrix.h"
#include "CONSTANTS.h"

std::vector<std::vector<double>> adjToMatrix(adjacency_list_t adjEdgeList) {
    std::size_t numberOfNodes = adjEdgeList.first.size();
    std::vector<double> adjEdgesWeights(numberOfNodes, CONSTANTS::NO_EDGE); // if a weight is -1 then there is no edge between them
    std::vector<std::vector<double>> matrix(numberOfNodes, adjEdgesWeights);

    for (int currentNode = 0; currentNode < numberOfNodes; currentNode++) {
        for (auto edge: adjEdgeList.second) {
            if (edge.n1 == currentNode)
                matrix[currentNode][edge.n2] = edge.weight;
        }
    }
    return matrix;
}
//
// Created by nordi on 5/5/2022.
//

#include <vector>
#include <iostream>
#include <cfloat>
#include "dijkstras.h"
#include "reader.h"
#include "CONSTANTS.h"

int minDistance(std::vector<double> dist, std::vector<bool> visited) {
    double minDist = DBL_MAX;
    int minimumsIndex;

    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i] && dist[i] <= minDist) {
            minDist = dist[i];
            minimumsIndex = i;
        }
    }
    return minimumsIndex;
}

route_list_t dijkstras(std::vector<std::vector<double>> matrix, int src, const adjacency_list_t &adjList) {
    std::vector<double> dist(matrix.size(), DBL_MAX);
    std::vector<bool> visited(matrix.size(), false);
    std::vector<int> backtrace(matrix.size(), CONSTANTS::NO_PARENT);
    dist[src] = 0.0f;   // setting source vertex dist to 0

    for (int i = 0; i < matrix.size(); i++) {
        int minDist = minDistance(dist, visited);
        visited[minDist] = true;
        for (int n = 0; n < matrix.size(); n++) {
            // updating the dist of neighbouring vertex
            if (matrix[minDist][n] != CONSTANTS::NO_EDGE && !visited[n] && dist[minDist] + matrix[minDist][n] < dist[n]) {
                dist[n] = dist[minDist] + matrix[minDist][n];
                backtrace[n] = minDist;
            }
        }
    }
    return {dist, backtrace};
}

std::string routeInfo(std::vector<int> route, int index) {
    if (route[index] == CONSTANTS::NO_PARENT)
        return std::to_string(index);
    return (routeInfo(route, route[index]) + " -> " + std::to_string(index));
}
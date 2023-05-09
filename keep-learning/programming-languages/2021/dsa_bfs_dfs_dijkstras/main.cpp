#include <iostream>
#include <queue>
#include "reader.h"
#include "adjToMatrix.h"
#include "dfs.h"
#include "findNotVisited.h"
#include "bfs.h"
#include "dijkstras.h"
#include "CONSTANTS.h"

int main() {
    // node 19 makes the graph incoherent, this was fixed by simply adding and edge from 3 to 19
    const std::string INVALID_GRAPH_AT = "%s: invalid graph at node: %i \n";
    const std::string VALID_GRAPH = "%s: valid graph \n";
    const std::string ROUTE_DISTANCE = "Route distance between %s node %i and %s node %i: %.2f\n";
    const std::string ROUTE_INFO = "Route information: %s \n";
    const std::string DIVIDER = "-------------------------------------------------------";
    int isValid = CONSTANTS::ALL_VISITED;

    // parse file content into adjacency list, and create a matrix with it
    adjacency_list_t adjList = parse_file("../edges.txt");
    std::vector<std::vector<double>> matrix = adjToMatrix(adjList);

    std::vector<bool> isVisitedNodes(matrix.size(), false);
    // using dfs, can EVERY node in the graph be reached from ANY node in the graph
    for (int currentNode = 0; currentNode < matrix.size(); currentNode++) {
        dfs(currentNode, isVisitedNodes, matrix);

        if ((isValid = findNotVisited(isVisitedNodes)) != CONSTANTS::ALL_VISITED)
            break;
        std::fill(isVisitedNodes.begin(), isVisitedNodes.end(), false);
    }
    if (isValid == CONSTANTS::ALL_VISITED)
//        std::cout << "DFS: valid graph" << std::endl;
        printf(VALID_GRAPH.c_str(), "DFS", isValid);
    else
//        std::cout << "DFS: invalid graph at node: " << isValid << std::endl;
        printf(INVALID_GRAPH_AT.c_str(), "DFS", isValid);

    //reset container
    std::fill(isVisitedNodes.begin(), isVisitedNodes.end(), false);
    std::queue<int> q;

    // using bfs, can EVERY node in the graph be reached from ANY node in the graph
    for (int currentNode = 0; currentNode < matrix.size(); currentNode++) {
        isVisitedNodes[currentNode] = true;
        q.push(currentNode);
        bfs(q, isVisitedNodes, matrix);

        if ((isValid = findNotVisited(isVisitedNodes)) != CONSTANTS::ALL_VISITED)
            break;

        //reset container
        std::fill(isVisitedNodes.begin(), isVisitedNodes.end(), false);
    }

    if (isValid != CONSTANTS::ALL_VISITED)
        printf(INVALID_GRAPH_AT.c_str(), "BFS", isValid);
    else {
        printf(VALID_GRAPH.c_str(), "BFS", isValid);
        std::cout << DIVIDER << std::endl;

        std::pair<std::vector<double>, std::vector<int>> route;
        route = dijkstras(matrix, 24, adjList);
        printf(ROUTE_DISTANCE.c_str(), adjList.first[24].c_str(), 24, adjList.first[37].c_str(), 37, route.first[37]);
        printf(ROUTE_INFO.c_str(), routeInfo(route.second, 37).c_str());

        std::cout << DIVIDER << std::endl;

        route = dijkstras(matrix, 46, adjList);
        printf(ROUTE_DISTANCE.c_str(), adjList.first[46].c_str(), 46, adjList.first[47].c_str(), 47, route.first[47]);
        printf(ROUTE_INFO.c_str(), routeInfo(route.second, 47).c_str());

        std::cout << DIVIDER << std::endl;

        route = dijkstras(matrix, 20, adjList);
        printf(ROUTE_DISTANCE.c_str(), adjList.first[20].c_str(), 20, adjList.first[19].c_str(), 19, route.first[19]);
        printf(ROUTE_INFO.c_str(), routeInfo(route.second, 19).c_str());
    }

    return 0;
}
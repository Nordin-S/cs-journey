//
// Created by nordi on 5/5/2022.
//

#ifndef LABORATION01_DIJKSTRAS_H
#define LABORATION01_DIJKSTRAS_H

#include "reader.h"

using route_list_t = std::pair<std::vector<double>, std::vector<int>>;

route_list_t dijkstras(std::vector<std::vector<double>>, int, const adjacency_list_t&);

std::string routeInfo(std::vector<int>, int);

#endif //LABORATION01_DIJKSTRAS_H

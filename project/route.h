#ifndef ROUTE_H
#define ROUTE_H

#include <vector>

#include "places.h"

/**
 * @brief Find and return any route from start to dest.
 * 
 * @param start 
 * @param dest 
 * @return std::vector<int> A vector of the ids of each place along the route.
 * If a route exists, `start->id()` should be the first element of the vector,
 * and `dest->id()` should be the last element of the vector. If no route is
 * possible, return an empty vector.
 */
std::vector<int> find_route(Place *start, Place *dest);

#endif

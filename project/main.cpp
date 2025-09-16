#include "places.h"
#include "route.h"

#include <unordered_set>
#include <vector>
#include <fstream>
#include <iostream>

int main() {
    std::vector<Place *> v;

    for (int i = 0; i < 26; i++) {
        if (i < 8) {
            v.push_back(new GasStation(i));
        } else if (i < 16) {
            v.push_back(new TollGate(i, i * 2 - 5));
        } else {
            v.push_back(new Place(i));
        }
    }

    std::fstream input("data.txt");

    std::string line;
    while (std::getline(input, line)) {
        int i = line[0] - 'A';
        int j = line[2] - 'A';
        v[i]->add_adj(v[j]);
        v[j]->add_adj(v[i]);
    }

    // We will print a route for every pair of places
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            auto route = find_route(v[i], v[j]);
            if (route.empty()) {
                std::cout << "No route from " << i << " to " << j << std::endl;
                continue;
            }
            for (int k = 0; k < route.size() - 1; k++) {
                std::cout << route[k] << " -> ";
            }
            std::cout << route.back() << std::endl;
        }
    }

    for (Place *p : v) {
        delete p;
    }
}

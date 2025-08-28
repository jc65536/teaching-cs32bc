#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "router.h"
#include "cart.h"
#include "search.h"
#include "product.h"

int main() {
    std::vector<Product> catalog;
    std::ifstream reader("catalog.csv");
    std::string line;
    while (std::getline(reader, line)) {
        std::vector<std::string> parts;

        int i = 0;
        for (int k = 0; k < 4; k++) {
            if (line[i] == '"') {
                i++;
                int j = line.find('"', i);
                parts.push_back(line.substr(i, j - i));
                i = j + 2;
            } else {
                int j = line.find(',', i);
                parts.push_back(line.substr(i, j - i));
                i = j + 1;
            }
        }

        int id = std::stoi(parts[0]);
        std::string name = parts[1];
        int price = std::stoi(parts[2]);
        int quantity = std::stoi(parts[3]);

        catalog.push_back({id, name, price, quantity});
    }

    SearchEngine search(&catalog);
    Cart cart(&catalog);
    Router router(&search, &cart);
    std::string path;
    while (std::getline(std::cin, path)) {
        std::cout << router.handle(path) << std::endl;
    }
}

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <format>

struct Product {
    int id;
    std::string name;
    int price;
    int quantity;

    std::string to_string() {
        return std::format("{}. {} [${}] (x{})", id, name, double(price) / 100, quantity);
    }
};

#endif

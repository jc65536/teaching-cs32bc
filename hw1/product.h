#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <sstream>

struct Product {
    int id;
    std::string name;
    int price;
    int quantity;

    std::string to_string() {
        std::stringstream ss;
        ss << id << ". " << name << " [$" << double(price) / 100 << "] (x" << quantity << ")";
        return ss.str();
    }
};

#endif

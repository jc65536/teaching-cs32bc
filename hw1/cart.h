#ifndef CART_H
#define CART_H

#include <vector>
#include "product.h"

class Cart {
    const std::vector<Product> *catalog_ptr;
    std::vector<int> items;

public:
    Cart(const std::vector<Product> *catalog_ptr);

    void add_item(int id);

    std::vector<Product> list_items();

    void clear();

    /**
     * @brief Calculate the total of all items in cart, with a 10% tax applied
     * 
     * @return The total in cents
     */
    int calculate_checkout_total();
};

#endif

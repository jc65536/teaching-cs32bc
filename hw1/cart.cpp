#include "cart.h"

Cart::Cart(const std::vector<Product> *catalog_ptr) {
    // TODO: Complete the constructor implementation
    // RM_START
    this->catalog_ptr = catalog_ptr;
    // RM_END
}

void Cart::add_item(int id) {
    // TODO: Complete the add_item function
    // RM_START
    items.push_back(id);
    // RM_END
}

std::vector<Product> Cart::list_items() {
    // TODO: Complete the list_items function
    // RM_START
    std::vector<Product> ans;
    for (int i : items) {
        for (const Product &p : *catalog_ptr) {
            if (p.id == i) {
                ans.push_back(p);
            }
        }
    }
    return ans;
    // RM_END
}

void Cart::clear() {
    // TODO: Complete the clear function
    // RM_START
    items.clear();
    // RM_END
}

int Cart::calculate_checkout_total() {
    // TODO: Complete the calculate_checkout_total function
    // RM_START
    int total = 0;
    for (int i : items) {
        for (const Product &p : *catalog_ptr) {
            if (p.id == i) {
                total += p.price;
            }
        }
    }

    return int(total * 1.1);
    // RM_END
}

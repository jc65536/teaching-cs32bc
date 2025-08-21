#include "cart.h"

Cart::Cart(const std::vector<Product> *catalog_ptr) {
    this->catalog_ptr = catalog_ptr;
}

void Cart::add_item(int id) {
    items.push_back(id);
}

std::vector<Product> Cart::list_items() {
    std::vector<Product> ans;
    for (int i : items) {
        for (const Product &p : *catalog_ptr) {
            if (p.id == i) {
                ans.push_back(p);
            }
        }
    }
    return ans;
}

void Cart::clear() {
    items.clear();
}

int Cart::calculate_checkout_total() {
    int total = 0;
    for (int i : items) {
        for (const Product &p : *catalog_ptr) {
            if (p.id == i) {
                total += p.price;
            }
        }
    }

    return int(total * 1.1);
}

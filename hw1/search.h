#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <string>
#include "product.h"

class SearchEngine {
    const std::vector<Product> *catalog_ptr;

public:
    SearchEngine(const std::vector<Product> *catalog_ptr);
    
    /**
     * @brief Returns a vector of Products that satisfy the search conditions
     * 
     * @param query
     * The product name must contain this as a substring (case insensitive)
     * 
     * @param min_price
     * The product price must not be lower than min_price
     * 
     * @param max_price
     * The product price must not be higher than max_price
     * 
     * @return std::vector<Product> 
     */
    std::vector<Product> query(std::string query, int min_price, int max_price);
};

#endif

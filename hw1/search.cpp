#include "search.h"

SearchEngine::SearchEngine(const std::vector<Product> *catalog_ptr) {
    // TODO: Complete the constructor implementation
    // RM_START
    this->catalog_ptr = catalog_ptr;
    // RM_END
}

std::vector<Product> SearchEngine::query(std::string query, int min_price, int max_price) {
    // TODO: Complete the query function
    // RM_START
    std::vector<Product> ans;
    for (const Product &p : *catalog_ptr) {
        if (p.price < min_price || max_price < p.price) {
            continue;
        }

        for (int i = 0; i + query.size() < p.name.size(); i++) {
            bool found = true;
            for (int j = 0; j < query.size(); j++) {
                char c1 = std::tolower(p.name[i + j]);
                char c2 = std::tolower(query[j]);
                if (c1 != c2) {
                    found = false;
                    break;
                }
            }

            if (found) {
                ans.push_back(p);
                break;
            }
        }
    }

    return ans;
    // RM_END
}

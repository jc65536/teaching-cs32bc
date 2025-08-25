#include "router.h"

Router::Router(SearchEngine *search, Cart *cart) {
    // TODO: Complete the constructor implementation
    // RM_START
    this->search = search;
    this->cart = cart;
    // RM_END
}
// RM_START
std::vector<std::vector<std::string>> get_params(std::string query) {
    query.push_back('&');
    std::vector<std::vector<std::string>> ans;
    while (!query.empty()) {
        int i = query.find('&');
        std::string first_pair = query.substr(0, i);
        query = query.substr(i + 1);

        int j = first_pair.find('=');
        std::string key = first_pair.substr(0, j);
        std::string val = first_pair.substr(j + 1);
        ans.push_back({key, val});
    }
    return ans;
}
// RM_END

std::string Router::handle(std::string path) {
    // TODO: Complete the handle function
    // RM_START
    if (path == "/") {
        return "Welcome to the online cafe :)\n";
    } else if (path.starts_with("/search")) {
        std::string query;
        int min_price = 0;
        int max_price = INT32_MAX;
        std::string order_by;

        if (path.size() >= 8) {
            auto params = get_params(path.substr(8));

            for (auto v : params) {
                std::string key = v[0];
                std::string val = v[1];

                if (key == "query") {
                    query = val;
                } else if (key == "min_price") {
                    min_price = std::stoi(val);
                } else if (key == "max_price") {
                    max_price = std::stoi(val);
                } else if (key == "order_by") {
                    order_by = val;
                }
            }
        }

        auto results = search->query(query, min_price, max_price, order_by);
        std::string response;
        for (auto &p : results) {
            response.append(p.to_string() + "\n");
        }
        return response;
    } else if (path.starts_with("/cart")) {
        if (path.starts_with("/cart/add/")) {
            int id = std::stoi(path.substr(10));
            cart->add_item(id);
            return std::format("Added item {}\n", id);
        } else if (path.starts_with("/cart/clear")) {
            cart->clear();
            return "Cleared cart\n";
        } else if (path.starts_with("/cart/checkout")) {
            return std::format("Your total is: ${}\n", cart->calculate_checkout_total() / 100.0);
        } else {
            auto items = cart->list_items();
            std::string response;
            for (auto &p : items) {
                response.append(p.to_string() + "\n");
            }
            return response;
        }
    } else {
        return "404 Not Found\n";
    }
    // RM_END
}

#include "router.h"

Router::Router(SearchEngine *search, Cart *cart) {
    // TODO: Complete the constructor implementation
    // RM_BEGIN
    this->search = search;
    this->cart = cart;
    // RM_END
}
// RM_BEGIN
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

bool startswith(const std::string &a, const std::string &b) {
    if (a.size() < b.size()) {
        return false;
    }

    for (int i = 0; i < b.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}
// RM_END

std::string Router::handle(std::string path) {
    // TODO: Complete the handle function
    // RM_BEGIN
    if (path == "/") {
        return "Welcome to the online cafe :)\n";
    } else if (startswith(path, "/search")) {
        std::string query;
        int min_price = 0;
        int max_price = 1000000;

        if (path.size() >= 8) {
            auto params = get_params(path.substr(8));

            for (auto v : params) {
                std::string key = v[0];
                std::string val = v[1];

                if (key == "query") {
                    query = val;
                } else if (key == "min_price") {
                    min_price = std::stof(val) * 100;
                } else if (key == "max_price") {
                    max_price = std::stof(val) * 100;
                }
            }
        }

        auto results = search->query(query, min_price, max_price);
        std::string response;
        for (auto &p : results) {
            response.append(p.to_string() + "\n");
        }
        return response;
    } else if (startswith(path, "/cart")) {
        std::stringstream ss;
        if (startswith(path, "/cart/add")) {
            int id = std::stoi(path.substr(10));
            cart->add_item(id);
            ss << "Added item " << id << std::endl;
            return ss.str();
        } else if (startswith(path, "/cart/clear")) {
            cart->clear();
            return "Cleared cart\n";
        } else if (startswith(path, "/cart/checkout")) {
            ss << "Your total is: $" << cart->calculate_checkout_total() / 100.0 << std::endl;
            return ss.str();
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

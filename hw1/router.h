#ifndef ROUTER_H
#define ROUTER_H

#include <string>
#include "search.h"
#include "cart.h"

class Router {
    SearchEngine *search;
    Cart *cart;

public:
    Router(SearchEngine *search, Cart *cart);
    std::string handle(std::string path);
};

#endif

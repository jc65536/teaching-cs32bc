#include <iostream>
#include <string>
#include <vector>

struct Topping {
    Topping(std::string name) {
        std::cout << "As long as it's not pineapple" << std::endl;
    }
};

struct Sauce {
    Sauce(std::string name) {
        std::cout << "It's " << name << " sauce" << std::endl;
    }
};

struct Crust {
    Crust(int thickness) {
        std::cout << "Thick or thin" << std::endl;
    }
};

struct Pizza {
    Pizza(int slices, std::string sauce_name) : sauce(sauce_name), crust(1) {
        this->toppings.push_back(Topping("olives"));
        std::cout << "Your pizza is ready" << std::endl;
    }

    std::vector<Topping> toppings;
    Sauce sauce;
    Crust crust;
};

int main() {
    Pizza p = Pizza(4, "pesto");
}

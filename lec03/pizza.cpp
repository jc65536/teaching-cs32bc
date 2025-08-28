#include <vector>
#include <string>
#include <iostream>

struct Topping {
    Topping(std::string name) {
        std::cout << "As long as it's not pineapple" << std::endl;
    }
};

struct Sauce {
    Sauce() {
        std::cout << "It's sauce" << std::endl;
    }
};

struct Crust {
    Crust() {
        std::cout << "Thick or thin" << std::endl;
    }
};

struct Pizza {
    std::vector<Topping> toppings;
    Sauce sauce;

    Pizza(int slices) {
        this->toppings.push_back(Topping("olives"));
        std::cout << "Your pizza is ready" << std::endl;
    }

    Crust crust;
};

int main() {
    for (int i = 0; i < 10; i++) {
        Pizza p = Pizza(4);
    }
}

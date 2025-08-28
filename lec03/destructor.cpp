#include <vector>
#include <string>
#include <iostream>

struct MyVector {
    int *data;

    /*
        MyVector(5)

        data
         |
        [g  g  g  g  g]
     */

    void do_something() {
        // ...
    }

    MyVector(int size) {
        data = new int[size];
    }

    // tilde
    ~MyVector() {
    }
};

void make_a_lot_of_vectors() {
    MyVector v(1000000);
    for (int i = 0; i < 100000; i++) {
        v.do_something();
    }

    v.~MyVector();
    // ...
    std::cout << "Created 100000 vectors of 1000000 ints each" << std::endl;
}

int main() {
    make_a_lot_of_vectors();
    std::string tmp;
    std::cin >> tmp;
}

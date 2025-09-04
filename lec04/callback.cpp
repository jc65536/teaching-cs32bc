#include <iostream>
#include <chrono>
#include <thread>

void delay(int n, void (*callback)(void)) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
    callback();
}

void message() {
    std::cout << "Hello World!" << std::endl;
}

void farewell() {
    std::cout << "Bye World!" << std::endl;
}

void function(int x) {
    std::cout << "Bye World!" << std::endl;
}

void f(const int *p) {

}

void g(int *p) {

}

int main() {
    void (*p)(int *) = f;
}

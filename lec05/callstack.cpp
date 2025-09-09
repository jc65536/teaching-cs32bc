#include <iostream>

void func2();
int main();

void func1() {
    long long x = 23232323;
    long long y = 11001100;
    func2();
}

void func2() {
    long long z = 87654321;

    // Points to z
    long long *p = &z;

    std::cout << "Address of main: " << (long long) main << std::endl;
    std::cout << "Address of func1: " << (long long) func1 << std::endl;
    // We're printing out p[0] (which should be z)
    for (int i = 0; i < 11; i++) {
        std::cout << p[i] << std::endl;
    }
}

int main() {
    long long w = 12345678;
    func1();
}

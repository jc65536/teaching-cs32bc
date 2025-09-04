#include <iostream>

void f(int arr[]) {
    std::cout << arr[2] << std::endl;
    std::cout << sizeof(arr) << std::endl;
}

int main() {
    int a[4] = {1, 2, 3, 4};
    int *b = a;
    int (*c)[4] = &a;

    std::cout << *(a + 2) << std::endl;
    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(b) << std::endl;

    f(a + 1);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}

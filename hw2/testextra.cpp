#include "list.h"
#include "dlist.h"

double f(int n) {
    return n / 2.0;
}

int main() {
    List<int> list;

    List<double> list2 = list.append(0).append(1).append(2).map(f);
    list2.print();
}

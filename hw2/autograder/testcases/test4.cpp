#include "list.h"
#include "dlist.h"

int main() {
    DList<int> list;

    list.append(0).append(1).append(2).append(3);

    auto n = list.index(1);

    list.insert_after(n, 4);
    list.insert_before(n, 5);
    n->value = 6;
    list.print();
}

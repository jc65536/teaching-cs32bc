#include "list.h"

int main() {
    List<int> l;

    l.cons(1).cons(2).cons(3).index(2).insert_after(4);
}

#ifndef DLIST_H
#define DLIST_H

/*******************************************************************************
 * Doubly-linked list
 */

template <typename T>
class DList {
    struct Node {
        T value;
        Node *prev;
        Node *next;
    };

    Node *head;
    Node *tail;

public:
    using iterator = Node *;

    DList();

    void insert_before(iterator it, T value);
    void insert_after(iterator it, T value);

    T remove(iterator it);

    // Return *this
    DList &cons(T value);

    // Return *this
    DList &append(T value);
};

#endif

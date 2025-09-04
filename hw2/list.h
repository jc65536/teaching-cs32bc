#ifndef LIST_H
#define LIST_H

/*******************************************************************************
 * Singly-linked list
 */

template <typename T>
class List {
    struct Node {
        T value;
        Node *next;
    };

    Node *head;
    Node *tail;

public:
    using iterator = Node *;

    List();

    void insert_after(iterator it, T value);

    // Return *this
    List &cons(T value);

    // Return *this
    List &append(T value);
};

#endif

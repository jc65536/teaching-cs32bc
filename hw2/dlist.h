#ifndef DLIST_H
#define DLIST_H

/*******************************************************************************
 * Doubly-linked list
 */

template <typename T>
class DList {
    class Node {
        T value;
        Node *prev;
        Node *next;

        T get() const;
        void set(T value);

    public:
        void insert_before(T value);
        void insert_after(T value);
        T remove(iterator it);
    };

    Node *head;
    Node *tail;

public:
    DList();

    // Return *this
    DList &cons(T value);

    // Return *this
    DList &append(T value);

    Node &index(int i);
};

#endif

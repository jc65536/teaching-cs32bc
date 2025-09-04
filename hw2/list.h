#ifndef LIST_H
#define LIST_H

/*******************************************************************************
 * Singly-linked list
 */

template <typename T>
class List {
    class Node {
        T value;
        Node *next;

    public:
        T get() const;
        void set(T value);

        void insert_after(T value);
    };

    Node *head;
    Node *tail;

public:
    using iterator = Node *;

    List();

    // Return *this
    List &cons(T value);

    // Return *this
    List &append(T value);

    Node &index(int i);
};

#endif

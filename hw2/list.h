#ifndef LIST_H
#define LIST_H

#include <iostream>

/*******************************************************************************
 * Singly-linked list
 */

template <typename T>
class List {
public:
    class Node {
        Node *next;

        // The constructor is private because we only want `Node` and `List`
        // methods to be able to construct new nodes. Users (e.g. test1.cpp)
        // should not be able to construct their own nodes.
        Node(T value, Node *next) {
            // TODO
            // RM_BEGIN
            this->value = value;
            this->next = next;
            // RM_END
        };

    public:
        T value;

        // This allows us to access `Node` private members from `List`
        friend class List;
    };

private:
    Node *head;
    Node *tail;

public:
    List() {
        // TODO
        // RM_BEGIN
        head = tail = nullptr;
        // RM_END
    };

    bool empty() const {
        return head == nullptr && tail == nullptr;
    }

    /**
     * @brief Insert a new node holding `value` before the head. That new node
     * becomes the new head. Side note: "cons" is a term borrowed from Lisp.
     *
     * @param value
     * @return List& Return `*this` so we can chain method calls
     */
    List &cons(T value) {
        // TODO
        // RM_BEGIN
        if (head) {
            head = new Node(value, head);
        } else {
            head = tail = new Node(value, nullptr);
        }
        // RM_END
        return *this;
    }

    /**
     * @brief Insert a new node holding `value` after the tail. That new node
     * becomes the new tail.
     *
     * @param value
     * @return List& Return `*this` so we can chain method calls
     */
    List &append(T value) {
        // TODO
        // RM_BEGIN
        auto n = new Node(value, nullptr);
        if (tail) {
            tail->next = n;
            tail = n;
        } else {
            head = tail = n;
        }
        // RM_END
        return *this;
    }

    /**
     * @brief Create a new node holding `value`, then insert it before node `n`.
     * Be sure to update `head` accordingly if needed. The behavior is undefined
     * if `n` does not point to a node in this list.
     * 
     * Hint: you can use `cons` in this method
     * 
     * @param n 
     * @param value 
     */
    void insert_before(Node *n, T value) {
        // TODO
        // RM_BEGIN
        if (n == head) {
            cons(value);
            return;
        }

        Node *m = head;
        while (m->next != n) {
            m = m->next;
        }

        m->next = new Node(value, n);
        // RM_END
    }

    /**
     * @brief Create a new node holding `value`, then insert it after node `n`.
     * Be sure to update `tail` accordingly if needed. The behavior is undefined
     * if `n` does not point to a node in this list.
     * 
     * Hint: you can use `cons` in this method
     * 
     * @param n 
     * @param value 
     */
    void insert_after(Node *n, T value) {
        // TODO
        // RM_BEGIN
        if (n == tail) {
            append(value);
        } else {
            n->next = new Node(value, n->next);
        }
        // RM_END
    }

    /**
     * @brief Remove node `n`. Be sure to update `head` and `tail` accordingly
     * if needed. Do not cause a memory leak. The behavior is undefined if `n`
     * does not point to a node in this list.
     * 
     * @param n 
     */
    void remove(Node *n) {
        // TODO
        // RM_BEGIN
        if (head == tail) {
            head = tail = nullptr;
        } else if (n == head) {
            head = n->next;
        } else {
            Node *m = head;
            while (m->next != n) {
                m = m->next;
            }
            m->next = n->next;
            if (n == tail) {
                tail = m;
            }
        }

        delete n;
    }

    /**
     * @brief Return a pointer to the `i`th node in this list. If `i` is out of
     * bounds, return `nullptr`.
     * 
     * @param i 
     * @return Node* 
     */
    Node *index(int i) {
        // TODO
        // RM_BEGIN
        if (i < 0) {
            return nullptr;
        }

        Node *n = head;

        while (n != nullptr && i > 0) {
            n = n->next;
            i--;
        }

        return n;
        // RM_END
    }

    ~List() {
        // TODO
        // RM_BEGIN
        // RM_END
    }

    /**
     * @brief Extra credit: Given a function `f` that takes an input of type `T`
     * and returns an output of type `U`, apply `f` to each value in this list,
     * create a new list containing the outputs of `f`, and return the new list.
     * 
     * @param f
     * @return List<U>
     */
    template<typename U>
    List<U> map(U (*f)(T)) {
        List<U> mapped;
        // RM_BEGIN
        Node *n = head;
        while (n != nullptr) {
            mapped.append(f(n->value));
            n = n->next;
        }
        // RM_END
        return mapped;
    }

    void print() {
        if (empty()) {
            std::cout << "<empty list>" << std::endl;
            return;
        }

        for (Node *n = head; n != tail; n = n->next) {
            std::cout << n->value << " -> ";
        }

        std::cout << tail->value << std::endl;
    }
};

#endif

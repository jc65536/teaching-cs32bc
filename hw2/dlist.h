#ifndef DLIST_H
#define DLIST_H

#include <iostream>

/*******************************************************************************
 * Doubly-linked list
 */

template <typename T>
class DList {
public:
    class Node {
        Node *prev;
        Node *next;

        Node(T value, Node *prev, Node *next) {
            // TODO
            // RM_BEGIN
            this->value = value;
            this->prev = prev;
            this->next = next;
            // RM_END
        }

    public:
        T value;
        friend class DList;
    };

private:
    Node *head;
    Node *tail;

public:
    DList() {
        // TODO
        // RM_BEGIN
        head = tail = nullptr;
        // RM_END
    }

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
    DList &cons(T value) {
        // TODO
        // RM_BEGIN
        if (head) {
            head = new Node(value, nullptr, head);
        } else {
            head = tail = new Node(value, nullptr, nullptr);
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
    DList &append(T value) {
        // TODO
        // RM_BEGIN
        if (tail) {
            auto n = new Node(value, tail, nullptr);
            tail->next = n;
            tail = n;
        } else {
            head = tail = new Node(value, nullptr, nullptr);
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
        } else {
            auto m = new Node(value, n->prev, n);
            n->prev->next = m;
            n->prev = m;
        }
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
            auto m = new Node(value, n, n->next);
            n->next->prev = m;
            n->next = m;
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
            head->prev = nullptr;
        } else if (n == tail) {
            tail = n->prev;
            tail->next = nullptr;
        } else {
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }

        delete n;
        // RM_END
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

    ~DList() {
        // TODO
        // RM_BEGIN
        Node *n = head;
        while (n != nullptr) {
            Node *next = n->next;
            delete n;
            n = next;
        }
        // RM_END
    }

    void print() {
        if (empty()) {
            std::cout << "<empty list>" << std::endl;
            return;
        }

        for (Node *n = head; n != tail; n = n->next) {
            std::cout << n->value << " <-> ";
        }

        std::cout << tail->value << std::endl;
    }
};

#endif

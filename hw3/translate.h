#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <string>
#include <vector>
// RM_BEGIN
#include <stack>
class Binop;
// RM_END

class Node {
public:
    // Pure virtual function
    virtual std::string to_infix() const = 0;
    // RM_BEGIN
    virtual int precedence() const = 0;
    // RM_END
};

class BinOp : public Node {
    std::string op; // The operation, i.e. "+", "-", "*", or "/"
    Node *left;
    Node *right;

public:
    BinOp(std::string op, Node *left, Node *right) : op(op), left(left), right(right) {
    }

    std::string to_infix() const override {
        // TODO
        // RM_BEGIN
        std::string s;
        if (left->precedence() >= precedence()) {
            s = left->to_infix();
        } else {
            s = "(" + left->to_infix() + ")";
        }
        s += op;
        if (right->precedence() > precedence()) {
            s += right->to_infix();
        } else if (right->precedence() == precedence()) {
            if (op == "+" || op == "*") {
                s += right->to_infix();
            } else {
                s += "(" + right->to_infix() + ")";
            }
        } else {
            s += "(" + right->to_infix() + ")";
        }
        return s;
        // RM_END
    }
    // RM_BEGIN
    int precedence() const override {
        if (op == "+" || op == "-") {
            return 1;
        } else {
            return 2;
        }
    }
    // RM_END
};

class Num : public Node {
    int value;

public:
    Num(int value) : value(value) {
    }

    std::string to_infix() const override {
        // TODO
        // RM_BEGIN
        return std::to_string(value);
        // RM_END
    }
    // RM_BEGIN
    int precedence() const override {
        return 3;
    }
    // RM_END
};

Node *parse(const std::vector<std::string> &tokens) {
    // TODO
    // RM_BEGIN
    std::stack<Node *> s;
    for (auto t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            Node *a = s.top();
            s.pop();
            Node *b = s.top();
            s.pop();
            s.push(new BinOp(t, b, a));
        } else {
            s.push(new Num(std::stoi(t)));
        }
    }
    return s.top();
    // RM_END
}

#endif

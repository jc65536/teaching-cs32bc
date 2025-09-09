#include "translate.h"
#include <iostream>

struct TestCase {
    std::string input;
    std::string expected;

    void run(int i) {
        std::vector<std::string> tokens;
        size_t pos_start = 0, pos_end;
        std::string token;

        while ((pos_end = input.find(" ", pos_start)) != std::string::npos) {
            token = input.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + 1;
            tokens.push_back(token);
        }
        tokens.push_back(input.substr(pos_start));

        Node *n = parse(tokens);
        auto infix = n->to_infix();

        if (infix == expected) {
            std::cout << "Testcase " << i << " passed" << std::endl;
        } else {
            std::cout << "Testcase " << i << " failed" << std::endl;
            std::cout << "Expected: " << expected << std::endl;
            std::cout << "Result: " << infix << std::endl;
        }
    }
};

std::vector<TestCase> testcases = {
    {"1 2 + 3 4 5 - * /", "(1+2)/(3*(4-5))"},
    {"1", "1"},
    {"1 2 + 3 4 - 5 6 + 7 8 - + + +", "1+2+3-4+5+6+7-8"},
};

int main() {
    for (int i = 0; i < testcases.size(); i++) {
        testcases[i].run(i);
    }
}

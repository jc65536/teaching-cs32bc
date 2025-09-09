# CS 32 Bootcamp Homework 3

## Overview

In this homework, we will implement postfix notation to infix notation
translation (the opposite of the algorithm in the lecture notes). We will
achieve this translation in 2 parts:

1. Parse the input to an abstract syntax tree
2. Format the abstract syntax tree into infix notation

Feel free to use the standard `stack` and `queue` data structures, and define
any helper functions you need.

## Abstract syntax tree

An abstract syntax tree (AST) represents the expression in a tree data structure:

```txt
(1 + 2) * 3

      *
     / \
    +   3
   / \
  1   2
```

It's unambiguous and does not rely on order of operation rules like PEMDAS or
parentheses. Note that there are two types of nodes: one which represents a
binary operation (`BinOp`) and one which represents a number (`Num`).

## Input format

The input will be a vector of strings. Each string in the vector will either be
a nonnegative integer, or one of four binary operations: `+`, `-`, `*`, or `/`.
It is in **postfix** notation, e.g. `{"1", "2", "+", "3", "*"}`.

## Output format

The output will be a *single* string in infix notation, e.g. `(1+2)*3`. Do not
use spaces. Do not use parentheses where not required by PEMDAS. E.g. an output
of `((1+(2))*3)` will not be accepted, even though the expression is correct,
because it has extraneous parentheses around the `2` and around the entire
expression.

## Todo

- Implement `parse` in `translate.h`
- Implement the `to_infix` methods in `translate.h`
- Use `make test` to test your program
- Use `make submission` to create a submission zip file

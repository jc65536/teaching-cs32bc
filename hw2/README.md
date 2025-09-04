# CS 32 Bootcamp Homework 2

## Overview

In homework 2, you will implement linked list data structures in C++. You will
create both a singly linked list (`list.h`) and a doubly linked list
(`dlist.h`). The program will let you insert, remove, and traverse linked lists.

## Skills tested
- Pointers and dynamic memory
- Singly and doubly linked lists
- Constructors and destructors
- C++ class templates, members, and methods

## Homework Logistics

**Due date: Monday 9/8 11:59 p.m. PT**

The files you need to edit are `dlist.cpp` and `list.cpp`. Follow the comments
in these files to implement the missing functions.

### Building the program

We will use Makefiles to automate project tasks.

There is no main executable. Instead, you can use `make test` to build and run
each `test*.cpp`.

Other `make` commands:
- `make clean`: Delete compiled files. Use this to try a clean build if you're
  running into compilation issues.
- `make submission`: Create the submission zip file

### Submitting
Run `make submission` and submit `submission.zip` to Gradescope.

## Homework instructions

See the header files for specific instructions. Implement all
methods/constructors/destructors marked by `// TODO`. Feel free to add helper
functions if needed.

Note that your implementation must not leak memory. Memory leaks will not crash
your program, and the provided test cases will pass just fine. However, for the
autograder, we will use a tool called Valgrind to catch these errors.

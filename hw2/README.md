# CS 32 Bootcamp Homework 2


## Overview

In homework 2, you will implement linked list data structures in C++. You will
create both a singly linked list (`list.h`) and a doubly linked list (`dlist.h`).
The program will let you insert, remove, and traverse linked lists.

## Skills tested
- Pointers and dynamic memory
- Singly and doubly linked lists
- Constructors and destructors
- C++ class templates, members, and methods

## Homework Logistics

**Due date: Saturday 9/6 11:59 p.m. PT**

The files you need to edit are `dlist.cpp` and `list.cpp`. Follow the comments in these files to implement the missing
functions.

### Building the program

We will use Makefiles to automate project tasks.

To build the project, open the homework directory in the terminal and type
`make`. Then you can run the program with `./main`:

Other `make` commands:
- `make clean`: Delete compiled files. Use this to try a clean build if you're
  running into compilation issues.
- `make submission`: Create the submission zip file
- `make test`: Run testcases

### Submitting
Run `make submission` and submit `submission.zip` to Gradescope.

## Homwqork instructions

You will implement two linked list data structures.

### Singly-linked list methods (`list.cpp`)

#### `cons(T value)`
Prepend value to the head. Return `*this`.

#### Example:
```cpp
List<int> myList;
myList.cons(10);          // myList: 10
myList.cons(5).cons(7);   // myList: 7 -> 5 -> 10
```
#### `append(T value)`
Append value to the tail. Return `*this`. 

#### Example: using the same `myList`
```cpp
myList.append(4);       // myList: 7 -> 5 -> 10 -> 4
```

#### `insert_after(iterator it, T value)`
Insert `value` after the given node at `it`.

#### Example: using the same `myList`
```cpp
List<int>::iterator iter = myList.head;
myList.insert_after(iter, 12);      // myList: 7 -> 12 -> 5 -> 10 -> 4
```
NOTE: remember to update head and tail pointers correctly in each method

### Doubly-linked list (`dllist.h`)

`cons()`, `append()`, and `insert_after()` are all similar to Singly-linked list implementation.

#### `cons(T value)`
Prepend value to the head. Return `*this`.

#### Example:
```cpp
DList<int> myDList;
myDList.cons(10);          // myDList: 10
myDList.cons(5).cons(7);   // myDList: 7 <-> 5 <-> 10
```
#### `append(T value)`
Append value to the tail. Return `*this`.
#### Example: 
```cpp
myDList.append(4);       // myDList: 7 <-> 5 <-> 10 <-> 4
```
#### `insert_after(iterator it, T value)`
Insert `value` after the given node.

#### Example:
```cpp
DList<int>::iterator iter = myDList.head;    // points to node at head which has value 7
myDList.insert_after(iter, 12);              // myDList: 7 <-> 12 <-> 5 <-> 10 <-> 4
```

#### `insert_before(iterator it, T value)`
Insert `value` before the given node.

#### Example: 
```cpp
DList<int>::iterator iter2 = myDList.tail;  // points to node at tail which has value 4
myDList.insert_before(iter2, 11);     // myDList: 7 <-> 12 <-> 5 <-> 10 <-> 11 <-> 4.
```

#### `remove(iterator it)`
Remove the given node and return its value.  

#### Example
```cpp
myDList.remove(iter);      // myDList: 12 <-> 5 <-> 11 <-> 10 <-> 4. iter pointed at node with value 7
```

### Extra credit
- **Merge**: create a merge function `List<T> merge(const List<T>& other) const;` Assume lists are sorted, merge two sorted lists into one new sorted
  list (do not modify the originals).

#### Example:
```cpp
List<int> list1;
list1.cons(5).cons(3).cons(1);      // list1: 1 -> 3 -> 5
List<int> list2;
list2.cons(6).cons(4).cons(2);      // list2: 2 -> 4 -> 6
List<int> mergedList = list1.merge(list2);  // mergedList: 1 -> 2 -> 3 -> 4 -> 5 -> 6
// list1 and list2 are unchanged
```
- **Map**: create a map function `List<int> map(Func f) const;` Apply a function `f : int → int` to each element and return a new
  list.

#### Example:
```cpp
List<int> list;
list.cons(3).cons(2).cons(1);  // list: 1 -> 2 -> 3
int square(int x) {
    return x * x;
}
List<int> squared = list.map(square);   // squared: 1 -> 4 -> 9
```


# CS 32 Bootcamp Homework 1

## Overview

In homework 1, you will implement the backend for an online cafe. The C++
program will take queries from stdin one line at a time, and write responses to
stdout.

## Project structure

The files to edit are `cart.cpp`, `router.cpp`, and `search.cpp`. Follow the
comments in these files to implement the relevant functions.

## Skills tested
- String manipulation
- Conditionals
- Loops
- C++ class constructors, members, and methods

## Testing

A simple HTTP server is provided in `serve.py`. Run `python serve.py`, then go
to `http://localhost:8000` to access the web app. `serve.py` will automatically
compile and run your C++ program to do the actual backend work.

If for any reason you can't run the Python script, you can always test the C++
program on the command line as follows:
```
[jason@tiramisu hw1]$ make  # Build the program
g++ -std=c++20   -c -o main.o main.cpp
g++ -std=c++20   -c -o router.o router.cpp
g++ -std=c++20   -c -o search.o search.cpp
g++ -std=c++20   -c -o cart.o cart.cpp
g++ -std=c++20 main.o router.o search.o cart.o -o main
[jason@tiramisu hw1]$ ./main  # Run the program and manually enter queries on stdin
/search?query=coffee
1008. Drip Coffee (Medium Roast, 12oz) [$2.75] (x30)
1009. Pour Over Coffee (Single Origin) [$6] (x8)
1021. Iced Coffee (16oz, Black) [$3.25] (x32)
1025. Blended Coffee (Coffee & Cream, 16oz) [$5.75] (x11)

/cart/add/1008
Added item 1008

/cart/add/1009
Added item 1009

/cart
1008. Drip Coffee (Medium Roast, 12oz) [$2.75] (x30)
1009. Pour Over Coffee (Single Origin) [$6] (x8)

/cart/checkout
Your total is: $9.62

```

# CS 32 Bootcamp Homework 1

## Overview

In homework 1, you will implement the backend for an online cafe. The C++
program will take queries from stdin one line at a time, and write responses to
stdout.

## Skills tested
- String manipulation
- Conditionals
- Loops
- C++ class constructors, members, and methods

## Homework logistics

**Due date: Saturday 8/30 11:59 p.m. PT**

The files you need to edit are `cart.cpp`, `router.cpp`, `search.cpp`, and
`report.txt`. Follow the comments in these files to implement the missing
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

## Homework instructions

A web backend receives *requests* and issues *responses*. For this assignment, a
request will simply be a URL path, and a response will be a string ending with a
newline.

A URL path looks like a file path, but it can also have path or query
parameters. Query parameters always begin with a `?`, are in the form `key=val`,
and are always separated by a `&`. The order of query parameters does not
matter.
```
/cart/add/10
          └┘ path parameter

/search?min_price=10&max_price=100&order_by=price
       └────────────────────────────────────────┘
       query parameters
```

You will implement a shopping cart in `cart.cpp` and a search engine in
`search.cpp`. See these files for the functions you need to implement and their
requirements. You may define helper functions as you need.

In `router.cpp`, you will implement a router which will parse requests, call the
relevant cart/search functions, and return a response. The rest of this section
will specify the endpoints (predefined requests and behaviors) which your router
must handle. Remember: Each response is a single string ending with `\n`!

### `/cart`
Return the items in the cart in any order. Each item must be on its own line and serialized using [`Product::to_string`](./product.h#L13).

#### Example 
```
Request: /cart
Response:
1001. Espresso (Double Shot) [$3] (x20)
1002. Americano (12oz) [$3.5] (x18)
1001. Espresso (Double Shot) [$3] (x20)
```

### `/cart/add/[id]`
Add the item with ID `id` to the cart. Then return the string "Added item
`id`\n". `id` is always an integer. The behavior can be undefined if the
specified item does not exist.

#### Example
```
Request: /cart/add/1001
Response:
Added item 1001
```

### `/cart/clear`
Remove all items from the cart. Then return the string "Cleared cart\n".

#### Example
```
Request: /cart/clear
Response:
Cleared cart
```

### `/cart/checkout`
Calculate the total cost of all items in the cart, add a 10% tax, then return
the string "Your total is: $(total)\n". Although prices are represented
internally in cents, your return value should be a decimal in dollars. No need
to add trailing zeroes (i.e. "$7.5" is fine).

#### Example
```
Request: /cart/checkout
Response:
Your total is: $7.15
```

### `/search`
Possible query parameters: `query` (string), `min_price` (float), `max_price` (float)

If there are no query parameters, return all items in the catalog in any order. Each item must be on its own line and serialized using [`Product::to_string`](./product.h#L13).

If `min_price` is set, all items returned must have a price greater than
or equal to `min_price`. Note that `min_price` is a decimal in dollars, while
the prices in code are in cents.

If `max_price` is set, all items returned must have a price greater than or
equal to `min_price`. Note that `min_price` is a decimal in dollars, while the
prices in code are in cents.

If `query` is set, all items returned must contain `query` as a substring in its
name. This is case insensitive, so if `query` is "abc", then the product "ABCDE"
should be returned.

## Testing

### Provided testcases
Some testcases are provided in the `testcases` directory. Use `make test` to run
all testcases.

### For fun

A simple HTTP server is provided in `serve.py`. Run `python serve.py`, then go
to `http://localhost:8000` to access the web app. `serve.py` will automatically
compile and run your C++ program to serve as the backend.

If for any reason you can't run the Python script, you can always test the C++
program on the command line as follows:
- Build the program
```
[jason@tiramisu hw1]$ make
g++ -std=c++20   -c -o main.o main.cpp
g++ -std=c++20   -c -o router.o router.cpp
g++ -std=c++20   -c -o search.o search.cpp
g++ -std=c++20   -c -o cart.o cart.cpp
g++ -std=c++20 main.o router.o search.o cart.o -o main
```
- Run the program and manually enter queries on stdin
```
[jason@tiramisu hw1]$ ./main
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

## Feedback
If you have any questions or concerns about the homework, please feel free to
reach out on Discord!

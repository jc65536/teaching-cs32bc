# CS 32 Bootcamp Project

## Overview

You're making a route planner for your next road trip. The basic task is: given
a graph of places, we want to find a route between place A and place B.

However, there are some contraints. Your car can hold at most 10 gallons of gas,
and travelling between two adjacent places consumes 3 gallons (you should really
consider getting a better car). Fortunately, some places are gas stations where
you can refill your tank for $5 per gallon. Whenever you visit a gas station,
you always try to completely refill your gas tank, unless you don't have enough
money, in which case you spend the rest of your money on gas. The gas stations
do not sell fractional gallons of gas, so if you have less than $5, then you
can't refill. There are also toll gates which charge a fee for when you arrive
at them. Your budget is $100.

## Project overview

- Implement `find_route` in `route.cpp` (see `route.h` for more information)
- You may add any methods or member variables to the classes in `places.h` to
  complete the project (you should not change or delete existing behavior)
- Compare your output to `expected.txt`. The only requirement is that your find
*some* path if a path exists (so if the paths are different, you won't lose
points).

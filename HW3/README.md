# HW3 – Filter Integer Iterator

This project implements a custom iterator in C++ that traverses only the elements of a container which satisfy a specific condition (a unary predicate).  
In this example, the iterator is used to print only even numbers from a vector of integers.

---
- The class `filter_integer_iterator` iterates over an integer array and skips elements that do not satisfy the given predicate.
- The class `filter_integer_iterator_builder` is a helper that provides `begin()` and `end()` functions for range-like iteration.

The condition (predicate) is a function pointer — for example:

The condition can be bool dividable_by_4(int num) {return n%4 == 0;}

---
or
bool is_even(int num) { return num % 2 == 0; }

like in the written code.



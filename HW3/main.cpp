#include <iostream>
#include <vector>
#include "iterator/filter_integer_iterator.h"
#include "iterator/reverse_array_iterator.h"
#include "iterator/circular_int_iterator.h"

bool is_even(int x) { return x % 2 == 0; }

int main() {
    // ---------- 1. Filter ----------
    std::vector<int> nums = {1,2,3,4,5,6};
    auto evens = filter_integer_iterator_builder(nums.data(), nums.size(), is_even);

    std::cout << "Even: ";
    for (auto it = evens.begin(); it != evens.end(); ++it)
        std::cout << *it << ' ';
    std::cout << "\n\n";

    // ---------- 2. Reverse ----------
    int arr[] = {10,20,30,40,50};
    reverse_array_iterator rev_begin(arr+4);
    reverse_array_iterator rev_end(arr-1);

    std::cout << "Reverse: ";
    for (auto it = rev_begin; it != rev_end; ++it)
        std::cout << *it << ' ';
    std::cout << "\n\n";

    // ---------- 3. Circular ----------
    std::vector<int> numbers = {10, 20, 30};
    circular_int_iterator_builder circular(numbers);

    std::cout << "Circular (7 items): ";
    int count = 0;
    auto cit = circular.begin();
    auto sentinel = circular.end();
    for (; cit != sentinel && count < 7; ++cit, ++count) {
        std::cout << *cit << ' ';
    }
    std::cout << "\n";
    return 0;
}
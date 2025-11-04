#pragma once
#include <vector>

class circular_iterator {
    std::vector<int>* vec;
    size_t idx;

public:
    explicit circular_iterator(std::vector<int>& v, size_t start = 0)
        : vec(&v), idx(start) {}

    int& operator*() const { return (*vec)[idx]; }

    circular_iterator& operator++() {
        ++idx;
        if (idx == vec->size()) idx = 0;
        return *this;
    }

    bool operator!=(const struct circular_iterator_sentinel&) const { return true; }
};

// Sentinel type
struct circular_iterator_sentinel {};

// Allow sentinel != iterator
inline bool operator!=(circular_iterator_sentinel, const circular_iterator&) {
    return true;
}

class circular_int_iterator_builder {
    std::vector<int>* vec;
public:
    explicit circular_int_iterator_builder(std::vector<int>& v) : vec(&v) {}

    circular_iterator begin() { return circular_iterator(*vec); }
    circular_iterator_sentinel end() { return circular_iterator_sentinel(); }
};

#pragma once

class reverse_array_iterator {
    int* ptr;

public:
    explicit reverse_array_iterator(int* p) : ptr(p) {}

    int& operator*() const { return *ptr; }
    reverse_array_iterator& operator++() {
        --ptr;
        return *this;
    }

    reverse_array_iterator operator++(int) {
        reverse_array_iterator tmp = *this;
        --ptr;
        return tmp;
    }

    bool operator!=(const reverse_array_iterator& other) const {
        return ptr != other.ptr;
    }
};
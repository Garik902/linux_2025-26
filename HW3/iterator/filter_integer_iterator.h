#pragma once

class filter_integer_iterator {
    int* current;
    int* end;
    bool (*predicate)(int);

    void advance_to_valid() {
        while (current != end && !predicate(*current)) {
            ++current;
        }
    }

public:
    filter_integer_iterator(int* start, int* end, bool (*pred)(int))
        : current(start), end(end), predicate(pred) {
        advance_to_valid();
    }

    int& operator*() const { return *current; }

    filter_integer_iterator& operator++() {
        ++current;
        advance_to_valid();
        return *this;
    }

    bool operator!=(const filter_integer_iterator& other) const {
        return current != other.current;
    }
};

class filter_integer_iterator_builder {
    int* data;
    size_t size;
    bool (*predicate)(int);

public:
    filter_integer_iterator_builder(int* data, size_t size, bool (*pred)(int))
        : data(data), size(size), predicate(pred) {}

    filter_integer_iterator begin() {
        return filter_integer_iterator(data, data + size, predicate);
    }

    filter_integer_iterator end() {
        return filter_integer_iterator(data + size, data + size, predicate);
    }
};
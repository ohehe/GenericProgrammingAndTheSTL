//
// Created by lingran_lab_win7 on 2017/8/16.
//

#ifndef GENERICPROGRAMMINGANDTHESTL_LINEITERATOR_H
#define GENERICPROGRAMMINGANDTHESTL_LINEITERATOR_H

#include "../normalheader.h"

class LineIterator {
protected:
    istream *in;
    string line;
    bool is_valid;

    void Read() {
        if (*in) {
            getline(*in, line);
        }
        is_valid = (*in) ? true : false;
    }

public:
    typedef input_iterator_tag iterator_category;
    typedef string value_type;
    typedef ptrdiff_t difference_type;
    typedef const string *pointer;
    typedef const string &reference;

    LineIterator() : in(&cin), is_valid(false) {};

    LineIterator(istream &s) : in(&s) {
        Read();
    }

    reference operator*() const { return line; }

    pointer operator->() const { return &line; }

    LineIterator operator++() {
        Read();
        return *this;
    }

    LineIterator operator++(int) {
        LineIterator tmp = *this;
        Read();
        return tmp;
    }

    bool operator==(const LineIterator &i) const {
        return (in == i.in && is_valid == i.is_valid) ||
               (is_valid == false && i.is_valid == false);
    }

    bool operator!=(const LineIterator &i) const {
        return !(*this == i);
    }
};


#endif //GENERICPROGRAMMINGANDTHESTL_LINEITERATOR_H

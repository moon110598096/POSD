#pragma once
// you should define a template class or type `ForwardIterator`
#include "iterator.h"
#include "../shape.h"
#include <list>
#include <iterator>
#include <iostream>
template<class ForwardIterator>
class CompoundIterator : public Iterator{
    private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;

public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end) {
        _begin=begin;
        _end=end;
        _current=_begin;
    }

    void first() override {
        _current=_begin;
    }

    Shape* currentItem() const override {
        if(isDone())
            throw "exception";
        return *_current;
    }

    void next() override {
        if(isDone())
            throw "exception";
        _current++;
    }

    bool isDone() const override {
        return _current==_end;
     }
};
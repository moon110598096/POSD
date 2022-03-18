#pragma once
#include "iterator.h"
#include "../shape.h"
class NullIterator : public Iterator {
public:
    void first() override { 
        throw "exception";
    }

    Shape* currentItem() const override {
        throw "exception";
     }

    void next() override {
        throw "exception";
     }

    bool isDone() const override { 
        return true;
    }
};
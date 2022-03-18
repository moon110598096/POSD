#pragma once
#include "shape.h"
#include "iterator/null_iterator.h"
#include "visitor/shape_visitor.h"
#include <exception>

class Rectangle : public Shape {
public: 
    Rectangle(double length, double width) { 
            if(length <=0 || width <=0)
                throw "number should be positive";
            _length = length;
            _width = width;
        }

    double area() const {
        return _length * _width;
     }

    double perimeter() const { 
        return _length *2 + _width*2;
    }
    
    std::string info() const { 
            std::stringstream ss;
            ss<<std::setprecision(2)<< std::fixed <<_length;
            std::string str=ss.str();
            str="Rectangle (" +str + " ";
            ss.str("");
            ss<<std::setprecision(2)<< std::fixed <<_width;
            str+=ss.str()+")";
            return str;
    }
    void accept(ShapeVisitor* visitor) override {
        visitor->visitRectangle(this);
    }
    Iterator* createIterator() override {
        return new NullIterator();
     }
    void addShape(Shape* shape){
        throw "exception";
    }
    void deleteShape(Shape* shape) { 
        throw "exception";
    }

private:
    double _length;
    double _width;
};
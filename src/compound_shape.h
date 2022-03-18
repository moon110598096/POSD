#pragma once
#include "iterator/iterator.h"
#include "iterator/compound_iterator.h"
#include "shape.h"
#include <string>
#include <list>
#include <iostream>
class ShapeVisitor;
class ShapeInfoVisitor;
class CompoundShape : public Shape {
    public:
        ~CompoundShape() {
            for(auto tmp : _shape)
                delete tmp;
        }

        double area() const override {
            double _area=0.0;
            for(Shape* _obj : _shape)
                _area+=_obj->area();
            return _area;
        }

        double perimeter() const override { 
            double _perimeter=0;
            for(Shape* _obj:_shape)
                _perimeter+=_obj->perimeter();
            return _perimeter;
        }

        std::string info() const override {
            return "CompoundShape";
        }
        void accept(ShapeVisitor* visitor) override {
            visitor->visitCompoundShape(this);
        }
        Iterator* createIterator() override {
            return new CompoundIterator<std::list<Shape*>::iterator> (_shape.begin(),_shape.end());
         }

        void addShape(Shape* shape) override {
            _shape.push_back(shape);
        }

        void deleteShape(Shape* shape) override {
            _shape.remove(shape);
            for (Shape* s : _shape){
                Iterator* it=s->createIterator();
                if(!it->isDone())
                    s->deleteShape(shape);
                delete it;
            }
        }
    private:
        std::list<Shape*> _shape;
};


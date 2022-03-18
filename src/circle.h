#pragma once
#include <cmath>
#include <sstream>
#include <iomanip>
#include "shape.h"
#include "iterator/null_iterator.h"
#include "visitor/shape_visitor.h"
class Circle: public Shape {
    public:
        Circle(double radius): _radius(radius){
            if(radius <=0 )
                throw "radius should be positive";
        }

        double area() const {
            return pow(_radius, 2) * M_PI;
        }
        
        double perimeter() const {
            return 2*_radius*M_PI;            
        }
        
        std::string info() const{
            std::stringstream ss;
            ss<<std::setprecision(2)<< std::fixed <<_radius;
            std::string str=ss.str();
            str="Circle (" +str + ")";
            return str;
        }

        void accept(ShapeVisitor* visitor) override {
             visitor->visitCircle(this);
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
        double _radius;
};

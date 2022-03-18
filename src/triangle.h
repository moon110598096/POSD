#pragma once
#include "two_dimensional_vector.h"
#include "shape.h"
#include "iterator/null_iterator.h"
#include "visitor/shape_visitor.h"
#include <exception>
class Triangle: public Shape {
public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2):_vec1(vec1),_vec2(vec2){ 
            /*if(vec1.dot(vec2)==0){
                throw "2 vector don't perpendicular";
            }*/
            if(vec1.cross(vec2)==0){
                throw "Incorrect value";
            }
    }

    double area() const {
        return abs((_vec1.cross(_vec2))/2);
    }

    double perimeter() const {
       double a=pow((pow(_vec1.x(),2)+pow(_vec1.y(),2)),0.5);
       double b=pow((pow(_vec2.x(),2)+pow(_vec2.y(),2)),0.5);
       double c=pow((pow(_vec1.x()-_vec2.x(),2)+pow(_vec1.y()-_vec2.y(),2)),0.5);
       return a+b+c;
     }

    std::string info() const {
            std::stringstream ss;
            ss<<std::setprecision(2)<< std::fixed <<_vec1.x();
            std::string str=ss.str();
            str="Triangle ([" +str + ",";
            ss.str("");
            ss<<std::setprecision(2)<< std::fixed <<_vec1.y();
            str+=ss.str()+"] [";
            
            ss.str("");
            ss<<std::setprecision(2)<< std::fixed <<_vec2.x();
            str+=ss.str()+",";

            ss.str("");
            ss<<std::setprecision(2)<< std::fixed <<_vec2.y();
            str+=ss.str()+"])";

            return str;
    }
    void accept(ShapeVisitor* visitor) override {
        visitor->visitTriangle(this);
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
    TwoDimensionalVector _vec1;
    TwoDimensionalVector _vec2;
};

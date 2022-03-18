#pragma once
#include "../circle.h"
#include "../compound_shape.h"
#include "../two_dimensional_vector.h"
#include "../rectangle.h"
#include "../triangle.h"
#include <stack>

class ShapeBuilder {
    public:
        static ShapeBuilder* getInstance() {
            static ShapeBuilder instance;
            return &instance;
        }

        ~ShapeBuilder() {
            reset();
        }

        void buildCircle(double radius) {
            shapeStack.push(new Circle(radius));
        }

        void buildRectangle(double length, double width) {
            shapeStack.push(new Rectangle(length, width));
        }

        void buildTriangle(double x1, double y1, double x2, double y2) {
            TwoDimensionalVector v1 = TwoDimensionalVector(x1,y1);
            TwoDimensionalVector v2 = TwoDimensionalVector(x2,y2);
            shapeStack.push(new Triangle(v1,v2));
        }

        void buildCompoundBegin() {
            shapeStack.push(new CompoundShape());
        }

        void buildCompoundEnd() {
            std::list<Shape*> components;
            while(typeid(*shapeStack.top()) != typeid(CompoundShape) || 
                (!shapeStack.top()->createIterator()->isDone() &&
                typeid(*shapeStack.top()) == typeid(CompoundShape))){
                components.push_back(shapeStack.top());
                shapeStack.pop();
            }
            Shape* compound = shapeStack.top();
            for(auto it = components.rbegin() ; it != components.rend() ; it++){
                compound->addShape(*it);
            }

        }

        Shape* getShape() {
            if (shapeStack.empty())
                throw "error" ;

            Shape* shape = shapeStack.top();
            shapeStack.pop();
            return shape;
        }

        void reset(){
            while(!shapeStack.empty()){
                Shape* shape = shapeStack.top();
                shapeStack.pop();
                delete shape;
            }
        }

    private:
        std::stack<Shape*> shapeStack;
        ShapeBuilder(){};
};
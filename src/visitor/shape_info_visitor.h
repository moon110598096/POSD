#pragma once

#include <string>
#include "../circle.h"
#include "../compound_shape.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "./shape_visitor.h"
#include "../iterator/iterator.h"

class ShapeInfoVisitor : public ShapeVisitor {
    public:
        void visitCircle(Circle* circle) {
            result+=createSpace(depth)+circle->info();
            result+='\n';
        }
        void visitRectangle(Rectangle* rectangle) {
            result+=createSpace(depth)+rectangle->info();
            result+='\n';
        }
        void visitTriangle(Triangle* triangle) {
            result+=createSpace(depth)+triangle->info();
            result+='\n';
        }
        void visitCompoundShape(CompoundShape* compoundShape) {
            
            result+=createSpace(depth)+"CompoundShape {\n";
            Iterator* it=compoundShape->createIterator();
            while(!it->isDone()){
                ShapeInfoVisitor _visitor;
                _visitor.addDepth(depth+1);
                it->currentItem()->accept(&_visitor);
                it->next();
                result+=_visitor.getResult();
            }
            result+=createSpace(depth)+"}\n";
        }
        void addDepth(int n){
            depth+=n;
        }
        std::string getResult() {
            return result;
        }

    private:
        int depth = 0;
        std::string result = "";

        std::string createSpace(int d){
            std::string tmp="";
            for(int i=0;i<d*2;i++){
                tmp+=' ';                
            }
            return tmp;
        }
};
#include "../shape.h"
#include "../circle.h"
#include "shape_builder.h"
#include "scanner.h"
#include <string>
#include <iostream>
#include <fstream>

class ShapeParser{
public:
    // `filePath` is a relative path of makefile
    ShapeParser(std::string filePath) {
        std::string _s="";
        std::ifstream ifs(filePath);
        if (!ifs.is_open()) 
            std::cout << "error\n";
        else{
            std::stringstream ss;
            ss << ifs.rdbuf();
            std::string str(ss.str());
            _s= str;
        }
        ifs.close();
        _scanner=new Scanner(_s);

        _builder=ShapeBuilder::getInstance();
    }

    ~ShapeParser() {
        delete _scanner;
    }

    void parse() {
        while(!_scanner->isDone()){
            std::string token = _scanner->next();
            if(token == "Circle"){
                _builder->buildCircle(_scanner->nextDouble());
            }
            else if(token == "Rectangle"){
                double n1=_scanner->nextDouble();
                double n2=_scanner->nextDouble();
                _builder->buildRectangle(n1,n2);
            }
            else if(token == "Triangle"){
                double x1=_scanner->nextDouble();
                double y1=_scanner->nextDouble();
                double x2=_scanner->nextDouble();
                double y2=_scanner->nextDouble();
                _builder->buildTriangle(x1,y1,x2,y2);
            }else if(token == "CompoundShape"){
                _builder->buildCompoundBegin();
            }else if(token == "}"){
                _builder->buildCompoundEnd();
            }
        }
    }

    Shape* getShape() {
        Shape* _shape= _builder->getShape();
        _builder->reset();
        return _shape;
    }
private:
    ShapeBuilder* _builder;
    Scanner* _scanner;
};

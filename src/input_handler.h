#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "./builder/shape_builder.h"
#include "./builder/shape_parser.h"
#include "./visitor/shape_info_visitor.h"
#include "./compound_shape.h"

class InputHandler {
   public:
    void handle();

   private:
    void printEditorInstructions();
    void handleEditorInstructions(int instruction);
    void save();
    void addCircle();
    void addRectangle();
    void addTriangle();
    void printCompoundInstructions();
    void handleCompoundInstructions(int instruction);
    void addCompound();
    void showMsg();
    void showInvalidArgument();
    std::string getOutPutInfo();
    ShapeBuilder* builder = ShapeBuilder::getInstance();
    bool isContinued = true;
};
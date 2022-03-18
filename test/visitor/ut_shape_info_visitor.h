#pragma once
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/compound_shape.h"
#include "../../src/visitor/shape_info_visitor.h"

TEST(CaseVisitorInfo, visitCompound) {
    Shape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.1));
    cs1->addShape(new Rectangle(3.14 ,4));
    Shape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(12.34567));
    cs2->addShape(cs1);
    ShapeInfoVisitor visitor;
    cs2->accept(&visitor);
    ASSERT_EQ(visitor.getResult(),"CompoundShape {\n  Circle (12.35)\n  CompoundShape {\n    Circle (1.10)\n    Rectangle (3.14 4.00)\n  }\n}\n");
}

TEST(CaseVisitorInfo, visitCircle) {
    Shape* c = new Circle(12.34567);
    ShapeInfoVisitor visitor;
    c->accept(&visitor);
    ASSERT_EQ(visitor.getResult(),"Circle (12.35)\n");
}

TEST(CaseVisitorInfo, visitRectangle) {
    Shape* r = new Rectangle(3.14 ,4);
    ShapeInfoVisitor visitor;
    r->accept(&visitor);
    ASSERT_EQ(visitor.getResult(),"Rectangle (3.14 4.00)\n");
}

TEST(CaseVisitorInfo, visitTriangle) {
    TwoDimensionalVector a(3.0,12.43);
    TwoDimensionalVector b(17.57,-4.0);
    Shape* t = new Triangle (a,b);
    ShapeInfoVisitor visitor;
    t->accept(&visitor);
    ASSERT_EQ(visitor.getResult(),"Triangle ([3.00,12.43] [17.57,-4.00])\n");
}

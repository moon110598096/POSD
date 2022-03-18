#pragma once
#include "../src/circle.h"
#include "../src/shape.h"
TEST(CaseCircle, area) {
    Circle c(10.0);
    ASSERT_NEAR(314.159, c.area(), 0.001);
}
TEST(CaseCircle, perimeter){
    Circle c(5.0);
    ASSERT_NEAR(31.415,c.perimeter(), 0.001);
}

TEST(CaseCircle, info){
    Circle c(5.0);
    ASSERT_EQ("Circle (5.00)",c.info());
}
TEST(CaseCircle,inputValue){
    EXPECT_ANY_THROW(Circle c(0));
    EXPECT_ANY_THROW(Circle c(-5));
    EXPECT_ANY_THROW(Circle c(-123));
}
TEST(CaseCircle, TestNullIteratorIsDone) {
    Circle c(10.0);
    ASSERT_TRUE(c.createIterator()->isDone());
}

TEST(CaseCircle, AddShapeShouldThrowException) {
    Circle c(10.0);
    EXPECT_ANY_THROW(c.addShape(new Circle(5.0)));
}

TEST(CaseCircle, DeleteShapeShouldThrowException) {
    Circle c(10.0);
    EXPECT_ANY_THROW(c.deleteShape(new Circle(5.0)));
}

TEST(CaseCircle, type){
    Shape* c=new Circle(5.0);
    ASSERT_EQ(typeid(c),typeid(Shape*));
    delete c;
}

TEST(CaseCircle, testarea){
    Shape* r = new Circle(12.34567);
    ASSERT_NEAR(r->area(),478.8276273855213,0.001);
}
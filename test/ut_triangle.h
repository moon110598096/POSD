#pragma once
#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"
TEST(CaseTriangle, area) {
    TwoDimensionalVector a(3.0,12.0);
    TwoDimensionalVector b(6.0,5.0);
    Triangle r(a,b);
    ASSERT_NEAR(28.5, r.area(), 0.001);
}
TEST(CaseTriangle, perimeter){
    TwoDimensionalVector a(3.0,12.0);
    TwoDimensionalVector b(17.0,4.0);
    Triangle r(a,b);
    ASSERT_NEAR(45.95,r.perimeter(), 0.01);
}
TEST(CaseTriangle, info){
    TwoDimensionalVector a(3.0,12.43);
    TwoDimensionalVector b(17.57,-4.0);
    Triangle r(a,b);
    ASSERT_EQ("Triangle ([3.00,12.43] [17.57,-4.00])",r.info());
}
TEST(CaseTriangle,inputValue){
    TwoDimensionalVector a(3.0,4.0);
    TwoDimensionalVector b(3.0,4.0);
    EXPECT_ANY_THROW(Triangle t(a,b));
}
TEST(CaseTriangle, TestNullIterator) {
    TwoDimensionalVector a(3.0,12.43);
    TwoDimensionalVector b(17.57,-4.0);
    Triangle r(a,b);
    ASSERT_TRUE(r.createIterator()->isDone());
}
TEST(CaseTriangle, AddShouldThrowException) {
    TwoDimensionalVector a(3.0,12.43);
    TwoDimensionalVector b(17.57,-4.0);
    Triangle r(a,b);
    EXPECT_ANY_THROW(r.addShape(new Triangle(a,b)));
}
TEST(CaseTriangle, DeleteShapeShouldThrowException) {
    TwoDimensionalVector a(3.0,12.43);
    TwoDimensionalVector b(17.57,-4.0);
    Triangle r(a,b);
    EXPECT_ANY_THROW(r.deleteShape(new Triangle(a,b)));
}
TEST(CaseTriangle, type){
    TwoDimensionalVector a(3.0,12.43);
    TwoDimensionalVector b(17.57,-4.0);
    Shape* r=new Triangle(a,b);
    ASSERT_EQ(typeid(r),typeid(Shape*));
    delete r;
}
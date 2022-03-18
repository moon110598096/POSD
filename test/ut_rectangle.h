#pragma once
#include "../src/rectangle.h"
TEST(CaseRectangle, area) {
    Rectangle r(10.0,5.0);
    ASSERT_NEAR(50.00, r.area(), 0.001);
}
TEST(CaseRectangle, perimeter){
    Rectangle r(10.0,5.0);
    ASSERT_NEAR(30,r.perimeter(), 0.001);
}
TEST(CaseRectangle, info){
    Rectangle r(10.0,5.0);
    ASSERT_EQ("Rectangle (10.00 5.00)",r.info());
}
TEST(CaseRectangle,inputValue){
    EXPECT_ANY_THROW(Rectangle r(-5,5));
    EXPECT_ANY_THROW(Rectangle r(-5,-5));
    EXPECT_ANY_THROW(Rectangle r(5,-5));
    EXPECT_ANY_THROW(Rectangle r(0,-5));
    EXPECT_ANY_THROW(Rectangle r(-5,0));
    EXPECT_ANY_THROW(Rectangle r(0,5));
    EXPECT_ANY_THROW(Rectangle r(5,0));
}
TEST(CaseRectangle, TestNullIteratorIsDone) {
    Rectangle r(10.0,20.0);
    ASSERT_TRUE(r.createIterator()->isDone());
}
TEST(CaseRectangle, AddShouldThrowException) {
    Rectangle r(10.0,20.0);
    EXPECT_ANY_THROW(r.addShape(new Rectangle(5.0,1.0)));
}
TEST(CaseRectangle, DeleteShapeShouldThrowException) {
    Rectangle r(10.0,180.0);
    EXPECT_ANY_THROW(r.deleteShape(new Rectangle(5.0,15.0)));
}
TEST(CaseRectangle, type){
    Shape* r=new Rectangle(5.0,15.0);
    ASSERT_EQ(typeid(r),typeid(Shape*));
}
TEST(CaseRectangle, testarea){
    Shape* r = new Rectangle(3.14,4.0);
     ASSERT_NEAR(r->area(),12.56,0.001);
}

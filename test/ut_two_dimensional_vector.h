#pragma once
#include "../src/two_dimensional_vector.h"

TEST(CaseTwoDimensionalVector, x) {
    TwoDimensionalVector r(10.0,5.0);
    ASSERT_NEAR(10.0,r.x(),0.001);
}
TEST(CaseTwoDimensionalVector, y){
    TwoDimensionalVector r(10.0,5.0);
    ASSERT_NEAR(5.0,r.y(),0.001);
}
TEST(CaseTwoDimensionalVector, length){
    TwoDimensionalVector r(3.0,4.0);
    ASSERT_NEAR(5.0,r.length(),0.001);
}

TEST(CaseTwoDimensionalVector, dot){
    TwoDimensionalVector r(10.0,5.0);
    TwoDimensionalVector x(10.0,5.0);
    ASSERT_NEAR(r.dot(x),125.0,0.001);
}
TEST(CaseTwoDimensionalVector, cross){
    TwoDimensionalVector r(10.0,5.0);
    TwoDimensionalVector x(11.0,4.0);
    ASSERT_NEAR(r.cross(x),-15.0,0.001);

}
TEST(CaseTwoDimensionalVector, substract){
    TwoDimensionalVector r(10.0,5.0);
    TwoDimensionalVector s(11.0,4.0);
    ASSERT_NEAR(r.subtract(s).x(),-1.0,0.001);
    ASSERT_NEAR(r.subtract(s).y(),1,0.001);
}
TEST(CaseTwoDimensionalVector, info){
    TwoDimensionalVector r(10.0,5.0);
    ASSERT_EQ(r.info(),"[10.00,5.00]");
}
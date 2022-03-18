#include "../../src/shape.h"
#include "../../src/two_dimensional_vector.h"
#include "../../src/builder/shape_builder.h"

class CaseBuilder : public ::testing::Test {
protected:
    const double delta = 0.001;
    ShapeBuilder* builder = ShapeBuilder::getInstance();

    void SetUp() override {
        
    }

    void TearDown() override {
    }
};

TEST_F(CaseBuilder, BuildCircle) {
    double radius = 1.0;

    builder->buildCircle(radius);
    Shape* result = builder->getShape();

    ASSERT_NEAR(1*1*M_PI, result->area(), delta);
}

TEST_F(CaseBuilder, BuildRectangle) {
    builder->buildRectangle(4.0,3.0);

    Shape* result = builder->getShape();

    ASSERT_NEAR(12.0, result->area(), delta);
}
TEST_F(CaseBuilder, BuildTriangle) {
    TwoDimensionalVector v1(3,0);
    TwoDimensionalVector v2(0,4);
    builder->buildTriangle(v1.x(), v1.y(), v2.x(), v2.y());
    Shape* result = builder->getShape();

    ASSERT_NEAR(6.0, result->area(), delta);
}

TEST_F(CaseBuilder, BuildEmptyCompound) {
    builder->buildCompoundBegin();
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();

    ASSERT_NEAR(0, result->area(), delta);
}

TEST_F(CaseBuilder, BuildCompound) {
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildCircle(2.0);
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();

    ASSERT_NEAR(1*1*M_PI + 2*2*M_PI, result->area(), delta);
}

TEST_F(CaseBuilder, BuildComplexCompound){
    builder->buildCompoundBegin();
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildCircle(2.0);
    builder->buildCompoundEnd();
    builder->buildRectangle(3.0,15.0);
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();

    ASSERT_NEAR(1*1*M_PI + 2*2*M_PI, result->createIterator()->currentItem()->area(), delta);
}

TEST_F(CaseBuilder, BuildgetInstance){

    ShapeBuilder* testBuilder = ShapeBuilder::getInstance();
    ASSERT_TRUE(typeid(testBuilder)==typeid(builder));

}
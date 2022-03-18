#include "../../src/builder/shape_parser.h"
#include "../../src/shape.h"

TEST(CasePaser, Circle) {
    std::string input = "test/data/circle.txt";
    ShapeParser* parser = new ShapeParser(input);
    parser->parse();
    Shape* result = parser->getShape();
    ASSERT_NEAR(1*1*M_PI, result->area(), 0.01);
}
TEST(CasePaser, ComplexCompound) {
    std::string input = "test/data/complex_compound.txt";
    ShapeParser* parser = new ShapeParser(input);
    parser->parse();
    Shape* result = parser->getShape();
    ASSERT_NEAR(43.4, result->area(), 0.01);
}
TEST(CasePaser, EmptyCompound) {
    std::string input = "test/data/empty_compound.txt";
    ShapeParser* parser = new ShapeParser(input);
    parser->parse();
    Shape* result = parser->getShape();
    ASSERT_NEAR(0, result->area(), 0.01);
}
TEST(CasePaser, Rectangle) {
    std::string input = "test/data/rectangle.txt";
    ShapeParser* parser = new ShapeParser(input);
    parser->parse();
    Shape* result = parser->getShape();
    ASSERT_NEAR(12.56, result->area(), 0.01);
}
TEST(CasePaser, SimpleCompound) {
    std::string input = "test/data/simple_compound.txt";
    ShapeParser* parser = new ShapeParser(input);
    parser->parse();
    Shape* result = parser->getShape();
    ASSERT_NEAR(21.7, result->area(), 0.01);
}
TEST(CasePaser, Triangle) {
    std::string input = "test/data/triangle.txt";
    ShapeParser* parser = new ShapeParser(input);
    parser->parse();
    Shape* result = parser->getShape();
    ASSERT_NEAR(6, result->area(), 0.01);
}

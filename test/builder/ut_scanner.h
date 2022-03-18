#include "../../src/builder/scanner.h"
#include <stack>
TEST(ScannerTest, next) {
    std::string input = "Circle (1.0)";
    Scanner scanner(input);
    std::string a = scanner.next();
    std::string b = scanner.next();                  
    double e = scanner.nextDouble();
    std::string c = scanner.next();
    ASSERT_EQ("Circle", a);
    ASSERT_EQ("(", b);
    ASSERT_EQ(")", c);
    ASSERT_NEAR(1.0,e,0.0);
}
TEST(ScannerTest, ScanCircleCorrectly) {
    std::string input = "I Circle eee ,tt{t3.14159a";
    Scanner scanner(input);
    std::string first = scanner.next();      
    std::string second = scanner.next(); 
    std::string QQ = scanner.next(); 
    double third = scanner.nextDouble();     
    ASSERT_EQ("Circle", first);
    ASSERT_EQ(",", second);
    ASSERT_EQ("{", QQ);
    ASSERT_NEAR(3.14159,third,0.0);
}

TEST(ScannerTest, ScanIllegalWordShouldIgnore) {
    std::string input = "asdlkgjl;kjdfnk{11223344l;asdf;as aslkdafjl; knqw ";
    Scanner scanner(input);
    scanner.next();
    double third = scanner.nextDouble();     
    ASSERT_NEAR(11223344,third,0.0);
}

TEST(ScannerTest, emptyCs) {
    std::string input = "CompoundShape {}";
    Scanner scanner(input);
    ASSERT_EQ("CompoundShape", scanner.next());
    ASSERT_EQ("{", scanner.next());
    ASSERT_EQ("}", scanner.next());
}

TEST(ScannerTest, compound) {
    std::stack<std::string> t;
    std::stack<double> num;
    std::string input = "CompoundShape {\n  Circle (1.0)\n  Triangle ([3,0] [0,4])\n  CompoundShape {\n    Circle (1.0)\n    Rectangle (3.14 4.00)\n    Triangle ([3,0] [0,4])\n  }\n  Rectangle (3.14 4.00)\n}\n";
    Scanner scanner(input);
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    num.push(scanner.nextDouble());
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    num.push(scanner.nextDouble());
    t.push(scanner.next());
    num.push(scanner.nextDouble());
    t.push(scanner.next());
    t.push(scanner.next());
    num.push(scanner.nextDouble());
    t.push(scanner.next());
    num.push(scanner.nextDouble());
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    num.push(scanner.nextDouble());
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    num.push(scanner.nextDouble());
    num.push(scanner.nextDouble());
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    num.push(scanner.nextDouble());
    t.push(scanner.next());
    num.push(scanner.nextDouble());
    t.push(scanner.next());
    t.push(scanner.next());
    num.push(scanner.nextDouble());
    t.push(scanner.next());
    num.push(scanner.nextDouble());
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    t.push(scanner.next());
    num.push(scanner.nextDouble());
    num.push(scanner.nextDouble());
    t.push(scanner.next());
    t.push(scanner.next());
    ASSERT_EQ("}", t.top());
    ASSERT_NEAR(4,num.top(),0.0);
    num.pop();
    ASSERT_NEAR(3.14,num.top(),0.0);
    num.pop();
    ASSERT_TRUE(scanner.isDone());
}
#pragma once
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/compound_shape.h"

TEST(CaseCompoundShape, Area) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(2.0);
    Shape* r = new Rectangle(5.0,10.0);
    Shape* cs=new CompoundShape();
    cs->addShape(c1);
    cs->addShape(c2);
    cs->addShape(r);
    ASSERT_NEAR(cs->area(),65.70,0.01);
    delete cs;
}
TEST(CaseCompoundShape, Area2) {
    Shape* c1 = new Circle(12.34567);
    Shape* r = new Rectangle(3.14,4);
    Shape* cs=new CompoundShape();
    cs->addShape(c1);
    cs->addShape(r);
    ASSERT_NEAR(cs->area(),491.38762793266164,0.001);

    cs->deleteShape(r);
    ASSERT_NEAR(cs->area(),478.827223,0.001);
    delete cs;
}

TEST(CaseCompoundShape, Perimeter) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(2.0);
    Shape* r = new Rectangle(5.0,10.0);
    Shape* cs=new CompoundShape();
    cs->addShape(c1);
    cs->addShape(c2);
    cs->addShape(r);
    ASSERT_NEAR(cs->perimeter(), 12.56+ 6.28+30.0,0.01);
    delete cs;
}

TEST(CaseCompoundShape, Iterator) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(2.0);
    Shape* r = new Rectangle(5.0,10.0);
    Shape* cs=new CompoundShape();
    cs->addShape(c1);
    cs->addShape(c2);
    cs->addShape(r);

    Iterator* it =cs->createIterator();

    it->first();
    EXPECT_EQ(c1, it->currentItem());

    it->next();
    EXPECT_EQ(c2, it->currentItem());

    it->next();
    EXPECT_EQ(r, it->currentItem());

    it->next();
    EXPECT_TRUE(it->isDone());
    delete cs;
}

// TEST(CaseCompoundShape, info) {
//     Shape* c1 = new Circle(1.45234);
//     Shape* c2 = new Circle(195.9285);
//     Shape* r = new Rectangle(2.465,52.911);
//     Shape* cs=new CompoundShape();
//     cs->addShape(c1);
//     cs->addShape(c2);
//     cs->addShape(r);
//     Shape* c3 = new Circle(3.14159);
//     Shape* c4 = new Circle(87.87);
//     Shape* cs2=new CompoundShape();
//     cs2->addShape(c3);
//     cs2->addShape(c4);
//     cs2->addShape(cs);
//     std::string ans="CompoundShape\n{\nCircle (3.14)\nCircle (87.87)\nCompoundShape\n{\nCircle (1.45)\nCircle (195.93)\nRectangle (2.46 52.91)\n}\n}";
//     ASSERT_EQ(cs2->info(),ans);
//     delete cs2;
// }

// TEST(CaseCompoundShape, info2) {
//     Shape* c1 = new Circle (1.1);
//     Shape* r = new Rectangle (3.14,4.1);
//     Shape* cs=new CompoundShape();
//     cs->addShape(c1);
//     cs->addShape(r);
//     std::string ans="CompoundShape\n{\nCircle (1.10)\nRectangle (3.14 4.10)\n}";
//     ASSERT_EQ(cs->info(),ans); 
//     delete cs;
// }

// TEST(CaseCompoundShape, DeleteShape) {
//     Shape* c1 = new Circle(1.0);
//     Shape* c2 = new Circle(2.0);
//     Shape* r = new Rectangle(5.0,10.0);
//     Shape* cs=new CompoundShape();
//     cs->addShape(c1);
//     cs->addShape(c2);
//     cs->addShape(r);
//     std::string str1=cs->info();
//     cs->deleteShape(c2);
//     std::string str2=cs->info();    
//     ASSERT_NE(str1,str2);
//     delete cs;

// }



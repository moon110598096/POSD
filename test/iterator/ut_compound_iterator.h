#pragma once
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/compound_shape.h"
#include "../../src/visitor/shape_info_visitor.h"

TEST(CaseCompoundIterator, CompoundIteratorIsAIterator){
    Shape* cs=new CompoundShape();
    Iterator* it =cs->createIterator();
    ASSERT_EQ(typeid(it),typeid(Iterator*));
    delete cs;
    delete it;
}

TEST(CaseNullIterator, FirstNoException) {
    Shape* cs=new CompoundShape();
    Iterator* it =cs->createIterator();
    EXPECT_NO_THROW(it->first());
    delete it;
}

TEST(CaseCompoundIterator, currentItemAndNext){
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(2.0);
    Shape* r = new Rectangle(5.0,10.0);
    std::list<Shape*> shapeList;
    shapeList.push_back(c1);
    shapeList.push_back(c2);
    shapeList.push_back(r);
    Iterator * cit=new CompoundIterator<std::list<Shape*>::iterator>(shapeList.begin(), shapeList.end());
    ASSERT_EQ(cit->currentItem(),c1);
    cit->next();
    ASSERT_EQ(cit->currentItem(),c2);
    cit->next();
    ASSERT_EQ(cit->currentItem(),r);
    cit->next();

    delete cit;
}

TEST(CaseCompoundIterator, isDone){
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(2.0);
    Shape* r = new Rectangle(5.0,10.0);
    std::list<Shape*> shapeList;
    shapeList.push_back(c1);
    shapeList.push_back(c2);
    shapeList.push_back(r);
    Iterator * cit=new CompoundIterator<std::list<Shape*>::iterator>(shapeList.begin(), shapeList.end());
    ASSERT_FALSE(cit->isDone());
    cit->next();
    ASSERT_FALSE(cit->isDone());
    cit->next();
    ASSERT_FALSE(cit->isDone());
    cit->next();
    ASSERT_TRUE(cit->isDone());
    delete cit;
}


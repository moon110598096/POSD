#pragma once
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/compound_shape.h"
#include "../../src/visitor/shape_info_visitor.h"

//Null Iterator Test
TEST(CaseNullIterator, NullIteratorType) {
    Iterator * Nit=new NullIterator();
    ASSERT_TRUE(typeid(*Nit)==typeid(NullIterator));
    delete Nit;
}
TEST(CaseNullIterator, FirstException) {
    Iterator * Nit=new NullIterator();
    EXPECT_ANY_THROW(Nit->first());
    delete Nit;
}
TEST(CaseNullIterator, CurrentItemException) {
    Iterator * Nit=new NullIterator();
    EXPECT_ANY_THROW(Nit->currentItem());
    delete Nit;
}
TEST(CaseNullIterator, NextException) {
    Iterator * Nit=new NullIterator();
    EXPECT_ANY_THROW(Nit->next());
    delete Nit;
}
TEST(CaseNullIterator, isDone) {
    Iterator * Nit=new NullIterator();
    ASSERT_TRUE(Nit->isDone());
    delete Nit;
}

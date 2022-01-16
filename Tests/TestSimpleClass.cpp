#include <gtest/gtest.h>
#include <SimpleClass.h>

TEST(SimpleClassTest, TestOne) 
{
    SimpleClass simple;
    EXPECT_EQ(simple.GetNumber(), 10);
}
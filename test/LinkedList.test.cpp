#include "../src/lib/LinkedList/LinkedList.h"
#include "../src/lib/LinkedList/LinkedList.cpp"
#include "gtest/gtest.h"

TEST(LinkedListTest, EmptyListTest) {
    LinkedList<int> ll;

    stringstream ss;
    ss << ll;
    string actual = ss.str();

    string expected = "NULL";

    EXPECT_TRUE(expected == actual);
}

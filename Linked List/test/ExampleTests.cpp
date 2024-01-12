#include "gtest/gtest.h"
#include "../LinkedList.hpp"
#include "../Node.hpp"
// #include "TheTestBrick.hpp"


TEST(LinkedListTest, AppendAndSize_small) {
    LinkedList <int> GQ; // Change the object name from 'list' to 'GQ'
    EXPECT_TRUE(GQ.isEmpty());
    EXPECT_EQ(GQ.size(), 0);

    GQ.append(1);
    GQ.append(2);
    GQ.append(3);
    GQ.append(3);
    GQ.append(3);

    EXPECT_FALSE(GQ.isEmpty());
    EXPECT_EQ(GQ.size(), 5);
}
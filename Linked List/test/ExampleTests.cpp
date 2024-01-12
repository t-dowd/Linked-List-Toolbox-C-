#include "gtest/gtest.h"
#include "../LinkedList.hpp"
#include "../Node.hpp"
#include "TheTestBrick.hpp"
#include <cstdlib>
#include <ctime>

TEST(LinkedListTest, Append_Int_small) {
    LinkedList <int> GQ; 
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

TEST(LinkedListTest, Append_ints_large){

    
    LinkedList <int> GQ; 
    EXPECT_TRUE(GQ.isEmpty());
    EXPECT_EQ(GQ.size(), 0);
    
    srand(static_cast<unsigned>(time(nullptr)));
    int sizeoflist = (rand() % 100) + 20;
    int a,b,c;

    for (int i = 0; i < sizeoflist; ++i) {
        int value = (i == 5) ? a = rand() % 1000 : (i == 10) ? b = rand() % 1000 : (i == 20) ? c = rand() % 1000 : rand() % 1000;
        GQ.append(value);
    }

    EXPECT_FALSE(GQ.isEmpty());
    EXPECT_EQ(GQ.size(), sizeoflist);
    EXPECT_EQ(a,GQ.get(5));
    EXPECT_EQ(b,GQ.get(10));
    EXPECT_EQ(c,GQ.get(20));

}

TEST(LinkedListTest,THROWING_BRICKS_small_no_risk){

    LinkedList <TestBrick<int>> GQ;
    std::vector<TestBrick<int>> a_quaint_wall_of_bricks;

    EXPECT_TRUE(GQ.isEmpty());
    EXPECT_EQ(GQ.size(), 0);

    for (int i = 0; i < 10; i++){
        TestBrick <int> dave;
        GQ.append(dave);
    }

    EXPECT_FALSE(GQ.isEmpty());
    EXPECT_EQ(GQ.size(), 10);
}
TEST(LinkedListTest,THROWING_BRICKS_small_MIXED_no_risk){
 //Do rest later
}

TEST(LinkedListTest,THROWING_BRICKS_LARGE_no_risk){
 // See late
}
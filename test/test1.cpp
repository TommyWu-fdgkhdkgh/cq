#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cq.h"

TEST(testCq, returnSize) {
    // cq<int> newcq(10);
    cq<int> newcq = cq<int>(10);
    EXPECT_EQ(newcq.getSize(), 10);
}

TEST(testCq, setSize) {
    cq<int> newcq = cq<int>(10);
    newcq.setSize(20);
    EXPECT_EQ(newcq.getSize(), 20);
}

TEST(testCq, getNumOfElements) {
    cq<int> newcq = cq<int>(10);
    EXPECT_EQ(newcq.getNumOfElements(), 0);

    newcq.enQueue(10);
    EXPECT_EQ(newcq.getNumOfElements(), 1);

    newcq.enQueue(20);
    EXPECT_EQ(newcq.getNumOfElements(), 2);

    newcq.popQueue();
    EXPECT_EQ(newcq.getNumOfElements(), 1);

    newcq.popQueue();
    EXPECT_EQ(newcq.getNumOfElements(), 0);
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

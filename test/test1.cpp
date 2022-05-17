#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cq.h"

TEST(testCq, defaultInit) {
    cq<int> newcq;
    EXPECT_EQ(newcq.getSize(), 0);
    EXPECT_EQ(newcq.getNumOfElements(), 0);
}

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

TEST(testCq, enQueueAndPopQueue) {
    cq<int> newcq = cq<int>(5);
    newcq.enQueueFromHead(10);
    EXPECT_EQ(newcq.getNumOfElements(), 1);
    newcq.enQueueFromHead(20);
    EXPECT_EQ(newcq.getNumOfElements(), 2);
    newcq.enQueue(30);
    EXPECT_EQ(newcq.getNumOfElements(), 3);
    newcq.enQueue(40);
    EXPECT_EQ(newcq.getNumOfElements(), 4);
    newcq.enQueueFromHead(50);
    EXPECT_EQ(newcq.getNumOfElements(), 5);
    
    int res;
    res = newcq.popQueue();
    EXPECT_EQ(newcq.getNumOfElements(), 4);
    EXPECT_EQ(res, 50);

    res = newcq.popQueue();
    EXPECT_EQ(newcq.getNumOfElements(), 3);
    EXPECT_EQ(res, 20);

    res = newcq.popQueue();
    EXPECT_EQ(newcq.getNumOfElements(), 2);
    EXPECT_EQ(res, 10);

    res = newcq.popQueue();
    EXPECT_EQ(newcq.getNumOfElements(), 1);
    EXPECT_EQ(res, 30);

    res = newcq.popQueue();
    EXPECT_EQ(newcq.getNumOfElements(), 0);
    EXPECT_EQ(res, 40);
}

TEST(testCq, enQueueAndPopQueueAndPeek) {
    cq<int> newcq = cq<int>(5);
    int res;
    newcq.enQueueFromHead(10);
    EXPECT_EQ(newcq.peekQueue(), 10); 
    EXPECT_EQ(newcq.getNumOfElements(), 1);
    newcq.enQueueFromHead(20);
    EXPECT_EQ(newcq.peekQueue(), 20); 
    EXPECT_EQ(newcq.getNumOfElements(), 2);
    newcq.enQueue(30);
    EXPECT_EQ(newcq.peekQueue(), 20); 
    EXPECT_EQ(newcq.getNumOfElements(), 3);
    newcq.enQueue(40);
    EXPECT_EQ(newcq.peekQueue(), 20); 
    EXPECT_EQ(newcq.getNumOfElements(), 4);
    newcq.enQueueFromHead(50);
    EXPECT_EQ(newcq.peekQueue(), 50); 
    EXPECT_EQ(newcq.getNumOfElements(), 5);
    
    res = newcq.popQueue();
    EXPECT_EQ(newcq.getNumOfElements(), 4);
    EXPECT_EQ(res, 50);
    EXPECT_EQ(newcq.peekQueue(), 20); 

    res = newcq.popQueue();
    EXPECT_EQ(newcq.getNumOfElements(), 3);
    EXPECT_EQ(res, 20);
    EXPECT_EQ(newcq.peekQueue(), 10); 

    res = newcq.popQueue();
    EXPECT_EQ(newcq.getNumOfElements(), 2);
    EXPECT_EQ(res, 10);
    EXPECT_EQ(newcq.peekQueue(), 30);
 
    res = newcq.popQueue();
    EXPECT_EQ(newcq.getNumOfElements(), 1);
    EXPECT_EQ(res, 30);
    EXPECT_EQ(newcq.peekQueue(), 40);

    res = newcq.popQueue();
    EXPECT_EQ(newcq.getNumOfElements(), 0);
    EXPECT_EQ(res, 40);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}









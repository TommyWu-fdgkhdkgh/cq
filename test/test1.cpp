#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cq.h"

TEST(simpleTest, returnSize) {
    // cq<int> newcq(10);
    cq<int> newcq = cq<int>(10);
    EXPECT_EQ(newcq.getSize(), 10);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#include <iostream>
//#include "../include/Queue.h"
/*#include "../include/Stack.h"
#include "../include/Task.h"
#include "../include/ForwardList.h"*/
#include <gtest/gtest.h>

//перетащила main

TEST(MainAppTest, ShouldSeeAllTests) {
    EXPECT_TRUE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
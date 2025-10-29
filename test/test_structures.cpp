#include <gtest/gtest.h>
#include "Stack.h"
#include "Queue.h"
#include "Task.h"

TEST(StackTest, Basic) {
    Stack<int> stack;
    EXPECT_TRUE(stack.empty());
    
    stack.push(1);
    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.top(), 1);
}

TEST(QueueTest, Basic) {
    Queue<int> queue;
    EXPECT_TRUE(queue.empty());
    
    queue.push(1);
    EXPECT_FALSE(queue.empty());
    EXPECT_EQ(queue.front(), 1);
}

TEST(BracketTest, Valid) {
    EXPECT_TRUE(BracketChecker::check("()"));
    EXPECT_TRUE(BracketChecker::check("()[]{}"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
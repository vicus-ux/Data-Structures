#include <gtest/gtest.h>
#include "Stack.h"
#include "Queue.h"
#include "Task.h"

// Тесты для Stack
TEST(StackTest, IsEmptyOnCreation) {
    Stack<int> stack;
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, PushAndTop) {
    Stack<int> stack;
    stack.push(42);
    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.top(), 42);
}

TEST(StackTest, MultiplePush) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    EXPECT_EQ(stack.size(), 3);
    EXPECT_EQ(stack.top(), 3);
}

TEST(StackTest, Pop) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    
    stack.pop();
    EXPECT_EQ(stack.top(), 1);
    EXPECT_EQ(stack.size(), 1);
    
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(StackTest, PopEmptyThrows) {
    Stack<int> stack;
    EXPECT_THROW(stack.pop(), std::out_of_range);
}

TEST(StackTest, TopEmptyThrows) {
    Stack<int> stack;
    EXPECT_THROW(stack.top(), std::out_of_range);
}

TEST(StackTest, Clear) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    stack.clear();
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}

// Тесты для Queue
TEST(QueueTest, IsEmptyOnCreation) {
    Queue<int> queue;
    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);
}

TEST(QueueTest, PushAndFront) {
    Queue<int> queue;
    queue.push(42);
    EXPECT_FALSE(queue.empty());
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(queue.front(), 42);
}

TEST(QueueTest, MultiplePush) {
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    EXPECT_EQ(queue.size(), 3);
    EXPECT_EQ(queue.front(), 1);  
    EXPECT_EQ(queue.back(), 3);   
}

TEST(QueueTest, Pop) {
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    queue.pop();
    EXPECT_EQ(queue.front(), 2);
    EXPECT_EQ(queue.size(), 2);
    
    queue.pop();
    EXPECT_EQ(queue.front(), 3);
    EXPECT_EQ(queue.size(), 1);
    
    queue.pop();
    EXPECT_TRUE(queue.empty());
}

TEST(QueueTest, PopEmptyThrows) {
    Queue<int> queue;
    EXPECT_THROW(queue.pop(), std::out_of_range);
}

TEST(QueueTest, FrontEmptyThrows) {
    Queue<int> queue;
    EXPECT_THROW(queue.front(), std::out_of_range);
}

TEST(QueueTest, BackEmptyThrows) {
    Queue<int> queue;
    EXPECT_THROW(queue.back(), std::out_of_range);
}

TEST(QueueTest, Clear) {
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    queue.clear();
    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);
}

// Тесты для BracketChecker
TEST(BracketCheckerTest, EmptyString) {
    EXPECT_TRUE(BracketChecker::check(""));
}

TEST(BracketCheckerTest, SimpleValid) {
    EXPECT_TRUE(BracketChecker::check("()"));
    EXPECT_TRUE(BracketChecker::check("[]"));
    EXPECT_TRUE(BracketChecker::check("{}"));
}

TEST(BracketCheckerTest, MixedValid) {
    EXPECT_TRUE(BracketChecker::check("()[]{}"));
    EXPECT_TRUE(BracketChecker::check("({[]})"));
    EXPECT_TRUE(BracketChecker::check("[{()}]"));
    EXPECT_TRUE(BracketChecker::check("({})[]"));
}

TEST(BracketCheckerTest, ComplexValid) {
    EXPECT_TRUE(BracketChecker::check("((()))"));
    EXPECT_TRUE(BracketChecker::check("{[()]}"));
    EXPECT_TRUE(BracketChecker::check("({[][]})"));
}

TEST(BracketCheckerTest, SimpleInvalid) {
    EXPECT_FALSE(BracketChecker::check("("));
    EXPECT_FALSE(BracketChecker::check(")"));
    EXPECT_FALSE(BracketChecker::check("["));
    EXPECT_FALSE(BracketChecker::check("]"));
    EXPECT_FALSE(BracketChecker::check("{"));
    EXPECT_FALSE(BracketChecker::check("}"));
}

TEST(BracketCheckerTest, MixedInvalid) {
    EXPECT_FALSE(BracketChecker::check("(]"));
    EXPECT_FALSE(BracketChecker::check("([)]"));
    EXPECT_FALSE(BracketChecker::check("({[}])"));
    EXPECT_FALSE(BracketChecker::check("{[}]"));
}

TEST(BracketCheckerTest, WrongOrder) {
    EXPECT_FALSE(BracketChecker::check(")("));
    EXPECT_FALSE(BracketChecker::check("]["));
    EXPECT_FALSE(BracketChecker::check("}{"));
}

// Тесты для QueueFromStacks
TEST(QueueFromStacksTest, IsEmptyOnCreation) {
    QueueFromStacks<int> queue;
    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);
}

TEST(QueueFromStacksTest, PushAndFront) {
    QueueFromStacks<int> queue;
    queue.push(42);
    EXPECT_FALSE(queue.empty());
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(queue.front(), 42);
}

TEST(QueueFromStacksTest, MultiplePush) {
    QueueFromStacks<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    EXPECT_EQ(queue.size(), 3);
    EXPECT_EQ(queue.front(), 1); 
}

TEST(QueueFromStacksTest, Pop) {
    QueueFromStacks<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    queue.pop();
    EXPECT_EQ(queue.front(), 2);
    EXPECT_EQ(queue.size(), 2);
    
    queue.pop();
    EXPECT_EQ(queue.front(), 3);
    EXPECT_EQ(queue.size(), 1);
    
    queue.pop();
    EXPECT_TRUE(queue.empty());
}

TEST(QueueFromStacksTest, ComplexOperations) {
    QueueFromStacks<int> queue;
    
    queue.push(1);
    queue.push(2);
    
    queue.pop();
    
    queue.push(3);
    queue.push(4);
    
    EXPECT_EQ(queue.front(), 2);
    queue.pop();
    EXPECT_EQ(queue.front(), 3);
    
    queue.push(5);
    queue.pop();
    EXPECT_EQ(queue.front(), 4);
    
    queue.pop();
    EXPECT_EQ(queue.front(), 5);
    
    queue.pop();
    EXPECT_TRUE(queue.empty());
}

TEST(QueueFromStacksTest, PopEmptyThrows) {
    QueueFromStacks<int> queue;
    EXPECT_THROW(queue.pop(), std::out_of_range);
}

TEST(QueueFromStacksTest, FrontEmptyThrows) {
    QueueFromStacks<int> queue;
    EXPECT_THROW(queue.front(), std::out_of_range);
}

// Интеграционные тесты
TEST(IntegrationTest, StackAndQueueTogether) {
    Stack<int> stack;
    Queue<int> queue;
    
    stack.push(10);
    queue.push(stack.top());
    stack.pop();
    
    stack.push(20);
    queue.push(stack.top());
    
    EXPECT_EQ(queue.front(), 10);
    EXPECT_EQ(queue.back(), 20);
}

TEST(IntegrationTest, BracketCheckerWithQueue) {
    Queue<std::string> test_cases;
    test_cases.push("()");
    test_cases.push("(");
    test_cases.push("({[]})");
    
    EXPECT_TRUE(BracketChecker::check(test_cases.front()));
    test_cases.pop();
    EXPECT_FALSE(BracketChecker::check(test_cases.front()));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
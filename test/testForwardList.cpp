#include <gtest/gtest.h>
#include "../include/ForwardList.h"
#include "../include/Task.h"
#include <vector>
#include <algorithm>
#include <string>

// Тесты конструкторов
TEST(ForwardListTest, DefaultConstructor) {
    ForwardList<int> list;
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(ForwardListTest, SizeValueConstructor) {
    ForwardList<int> list(5, 42);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.size(), 5);
    
    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(list[i], 42);
    }
}

TEST(ForwardListTest, ZeroSizeConstructor) {
    ForwardList<int> list(0, 100);
    EXPECT_TRUE(list.empty());
}

// Тесты копирования
TEST(ForwardListTest, CopyConstructor) {
    ForwardList<int> original(3, 10);
    original[1] = 20;
    original[2] = 30;
    
    ForwardList<int> copy(original);
    EXPECT_EQ(copy.size(), original.size());
    
    for (size_t i = 0; i < original.size(); ++i) {
        EXPECT_EQ(copy[i], original[i]);
    }
}

TEST(ForwardListTest, CopyAssignment) {
    ForwardList<int> original(3, 10);
    original[1] = 20;
    original[2] = 30;
    
    ForwardList<int> copy;
    copy = original;
    EXPECT_EQ(copy.size(), original.size());
    
    for (size_t i = 0; i < original.size(); ++i) {
        EXPECT_EQ(copy[i], original[i]);
    }
}

TEST(ForwardListTest, SelfAssignment) {
    ForwardList<int> list(3, 10);
    list = list;
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list[0], 10);
}

// Тесты перемещения
TEST(ForwardListTest, MoveConstructor) {
    ForwardList<std::string> original(3, "test");
    size_t original_size = original.size();
    
    ForwardList<std::string> moved(std::move(original));
    EXPECT_EQ(moved.size(), original_size);
    EXPECT_TRUE(original.empty());
}

TEST(ForwardListTest, MoveAssignment) {
    ForwardList<std::string> original(3, "test");
    size_t original_size = original.size();
    
    ForwardList<std::string> moved;
    moved = std::move(original);
    EXPECT_EQ(moved.size(), original_size);
    EXPECT_TRUE(original.empty());
}

// Тесты методов доступа
TEST(ForwardListTest, OperatorBracket) {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
}

TEST(ForwardListTest, AtMethod) {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    
    EXPECT_EQ(list.at(0), 1);
    EXPECT_EQ(list.at(1), 2);
    EXPECT_EQ(list.at(2), 3);
}

TEST(ForwardListTest, AtMethodThrowsException) {
    ForwardList<int> list(2, 10);
    
    EXPECT_THROW(list.at(5), std::out_of_range);
    EXPECT_THROW(list.at(100), std::out_of_range);
}

TEST(ForwardListTest, FrontMethod) {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    
    EXPECT_EQ(list.front(), 1);
    
    const ForwardList<int>& const_list = list;
    EXPECT_EQ(const_list.front(), 1);
}

TEST(ForwardListTest, FrontMethodThrowsException) {
    ForwardList<int> empty_list;
    
    EXPECT_THROW(empty_list.front(), std::out_of_range);
    
    const ForwardList<int>& const_empty_list = empty_list;
    EXPECT_THROW(const_empty_list.front(), std::out_of_range);
}

// Тесты итераторов
TEST(ForwardListTest, IteratorBasic) {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    
    std::vector<int> result;
    for (auto it = list.begin(); it != list.end(); ++it) {
        result.push_back(*it);
    }
    
    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(result, expected);
}

TEST(ForwardListTest, IteratorRangeBasedFor) {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    
    std::vector<int> result;
    for (int val : list) {
        result.push_back(val);
    }
    
    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(result, expected);
}

TEST(ForwardListTest, IteratorOperators) {
    ForwardList<int> list;
    list.push_front(2);
    list.push_front(1);
    
    auto it = list.begin();
    EXPECT_EQ(*it, 1);
    
    ++it;
    EXPECT_EQ(*it, 2);
    
    EXPECT_TRUE(list.begin() != list.end());
    EXPECT_FALSE(list.begin() == list.end());
}

// Тесты модификаторов
TEST(ForwardListTest, PushFront) {
    ForwardList<int> list;
    
    list.push_front(1);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 1);
    
    list.push_front(2);
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), 2);
    EXPECT_EQ(list[1], 1);
}

TEST(ForwardListTest, PushFrontMove) {
    ForwardList<std::string> list;
    
    std::string str = "test";
    list.push_front(std::move(str));
    
    EXPECT_EQ(list.front(), "test");
    EXPECT_TRUE(str.empty());
}

TEST(ForwardListTest, PopFront) {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    
    list.pop_front();
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), 2);
    
    list.pop_front();
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 3);
    
    list.pop_front();
    EXPECT_TRUE(list.empty());
}

TEST(ForwardListTest, PopFrontEmptyList) {
    ForwardList<int> list;
    
    EXPECT_NO_THROW(list.pop_front());
    EXPECT_TRUE(list.empty());
}

TEST(ForwardListTest, InsertAfter) {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(1);
    
    auto it = list.begin();
    list.insert_after(it, 2);
    
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
}

TEST(ForwardListTest, InsertAfterAtBeginning) {
    ForwardList<int> list;
    list.push_front(1);
    
    auto it = list.end();
    list.insert_after(it, 2);
    
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), 2);
}

TEST(ForwardListTest, EraseAfter) {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    
    auto it = list.begin();
    list.erase_after(it);
    
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 3);
}

TEST(ForwardListTest, Clear) {
    ForwardList<int> list(5, 10);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.size(), 5);
    
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(ForwardListTest, ClearEmptyList) {
    ForwardList<int> list;
    EXPECT_TRUE(list.empty());
    
    list.clear();
    EXPECT_TRUE(list.empty());
}

// Стресс-тесты
TEST(ForwardListTest, StressTestLargeInsertion) {
    ForwardList<int> list;
    const int COUNT = 1000;
    
    for (int i = 0; i < COUNT; ++i) {
        list.push_front(i);
    }
    
    EXPECT_EQ(list.size(), COUNT);
    
    auto it = list.begin();
    for (int i = COUNT - 1; i >= 0; --i) {
        EXPECT_EQ(*it, i);
        ++it;
    }
}

TEST(ForwardListTest, StressTestManyOperations) {
    ForwardList<int> list;
    const int OPERATIONS = 1000;
    
    for (int i = 0; i < OPERATIONS; ++i) {
        list.push_front(i);
        if (i % 10 == 0 && !list.empty()) {
            list.pop_front();
        }
    }
    
    EXPECT_GT(list.size(), 0);
}

TEST(ForwardListTest, StressTestCopyLargeList) {
    const int SIZE = 500;
    ForwardList<int> original;
    
    for (int i = 0; i < SIZE; ++i) {
        original.push_front(i);
    }
    
    ForwardList<int> copy1(original);
    ForwardList<int> copy2 = original;
    ForwardList<int> copy3;
    copy3 = copy1;
    
    EXPECT_EQ(original.size(), SIZE);
    EXPECT_EQ(copy1.size(), SIZE);
    EXPECT_EQ(copy2.size(), SIZE);
    EXPECT_EQ(copy3.size(), SIZE);
    
    for (int i = 0; i < SIZE; ++i) {
        EXPECT_EQ(original[i], copy1[i]);
    }
}

// Тесты с разными типами данных
TEST(ForwardListTest, StringType) {
    ForwardList<std::string> list;
    
    list.push_front("world");
    list.push_front("hello");
    
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[0], "hello");
    EXPECT_EQ(list[1], "world");
}

TEST(ForwardListTest, DoubleType) {
    ForwardList<double> list;
    
    list.push_front(3.14);
    list.push_front(2.71);
    
    EXPECT_EQ(list.size(), 2);
    EXPECT_DOUBLE_EQ(list[0], 2.71);
    EXPECT_DOUBLE_EQ(list[1], 3.14);
}

// Тесты исключений
TEST(ForwardListTest, ExceptionSafety) {
    ForwardList<int> list(5, 10);
    
    EXPECT_NO_THROW(list[0]);
    EXPECT_NO_THROW(list[4]);
    
    EXPECT_THROW(list.at(5), std::out_of_range);
    EXPECT_THROW(list.at(100), std::out_of_range);
}

TEST(ForwardListTest, EmptyListOperations) {
    ForwardList<int> list;
    
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    
    EXPECT_NO_THROW(list.pop_front());
    EXPECT_NO_THROW(list.clear());
    
    EXPECT_EQ(list.begin(), list.end());
    
    EXPECT_THROW(list.front(), std::out_of_range);
    EXPECT_THROW(list.at(0), std::out_of_range);
}

TEST(ForwardListTest, ComplexOperationSequence) {
    ForwardList<int> list;
    
    for (int i = 0; i < 10; ++i) {
        list.push_front(i);
    }
    EXPECT_EQ(list.size(), 10);
    
    for (int i = 0; i < 3; ++i) {
        list.pop_front();
    }
    EXPECT_EQ(list.size(), 7);
    
    list.clear();
    EXPECT_TRUE(list.empty());
    
    for (int i = 0; i < 5; ++i) {
        list.push_front(i * 2);
    }
    EXPECT_EQ(list.size(), 5);
    
    int expected_value = 8;
    for (auto it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, expected_value);
        expected_value -= 2;
    }
}

// Тесты для printReverse
TEST(PrintReverseRaw, EmptyList) {
    ForwardList<int> list;
    testing::internal::CaptureStdout();
    Task::printReverse(list);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}

TEST(PrintReverseRaw, SingleElement) {
    ForwardList<int> list;
    list.push_front(42);
    testing::internal::CaptureStdout();
    Task::printReverse(list);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "42 \n");
}

TEST(PrintReverseRaw, TwoElements) {
    ForwardList<int> list;
    list.push_front(2);
    list.push_front(1);          // список: 1 → 2
    testing::internal::CaptureStdout();
    Task::printReverse(list);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "2 1 \n");
}

TEST(PrintReverseRaw, ThreeElements) {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);          // 1 → 2 → 3
    testing::internal::CaptureStdout();
    Task::printReverse(list);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "3 2 1 \n");
}

TEST(PrintReverseRaw, FiveElements) {
    ForwardList<int> list;
    for (int i = 5; i >= 1; --i) list.push_front(i);   // 1 2 3 4 5
    testing::internal::CaptureStdout();
    Task::printReverse(list);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "5 4 3 2 1 \n");
}

TEST(PrintReverseRaw, StringType) {
    ForwardList<std::string> list;
    list.push_front("world");
    list.push_front("hello");
    testing::internal::CaptureStdout();
    Task::printReverse(list);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "world hello \n");
}

TEST(PrintReverseRaw, DoubleType) {
    ForwardList<double> list;
    list.push_front(3.14);
    list.push_front(2.71);
    testing::internal::CaptureStdout();
    Task::printReverse(list);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "3.14 2.71 \n");
}

TEST(PrintReverseRaw, ListIntegrityAfterPrint) {
    ForwardList<int> list;
    for (int i = 0; i < 100; ++i) list.push_front(i);
    auto copy = list;
    Task::printReverse(list);       
    EXPECT_EQ(list.size(), copy.size());
    for (size_t i = 0; i < 100; ++i) EXPECT_EQ(list[i], copy[i]);
}

TEST(PrintReverseRaw, MixedOperations) {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.pop_front();   // 1
    list.push_front(3);
    list.push_front(4); // 4 3 1
    testing::internal::CaptureStdout();
    Task::printReverse(list);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1 3 4 \n");
}

TEST(ForwardListTest, EmptyListOperationsDetailed) {
    ForwardList<int> list;
    
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.begin(), list.end());
    
    EXPECT_NO_THROW(list.pop_front());
    EXPECT_TRUE(list.empty());
    
    EXPECT_NO_THROW(list.clear());
    EXPECT_TRUE(list.empty());
    
    EXPECT_THROW(list.front(), std::out_of_range);
    EXPECT_THROW(list.at(0), std::out_of_range);
    EXPECT_THROW(list[0], std::out_of_range); 
}

TEST(ForwardListTest, EmptyListAfterOperations) {
    ForwardList<int> list;
    
    list.push_front(1);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.size(), 1);
    
    list.pop_front();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    
    EXPECT_EQ(list.begin(), list.end());
    
    list.push_front(1);
    list.push_front(2);
    EXPECT_EQ(list.size(), 2);
    
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.begin(), list.end());
}

TEST(ForwardListTest, SingleElementList) {
    ForwardList<int> list;
    
    list.push_front(50);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 50);
    EXPECT_EQ(list[0], 50);
    EXPECT_EQ(list.at(0), 50);
    
    auto it = list.begin();
    EXPECT_NE(it, list.end());
    EXPECT_EQ(*it, 50);
    
    it++;
    EXPECT_EQ(it, list.end());
    
    EXPECT_NO_THROW(list.end());
}

TEST(ForwardListTest, SingleElementOperations) {
    ForwardList<int> list;
    list.push_front(100);
    
    EXPECT_EQ(list.front(), 100);
    EXPECT_EQ(list[0], 100);
    EXPECT_EQ(list.at(0), 100);
    
    ForwardList<int> copy1(list);
    EXPECT_EQ(copy1.size(), 1);
    EXPECT_EQ(copy1.front(), 100);
    
    ForwardList<int> copy2;
    copy2 = list;
    EXPECT_EQ(copy2.size(), 1);
    EXPECT_EQ(copy2.front(), 100);
    
    ForwardList<int> moved(std::move(list));
    EXPECT_EQ(moved.size(), 1);
    EXPECT_EQ(moved.front(), 100);
    EXPECT_TRUE(list.empty());
    
    list = std::move(moved);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 100);
}

TEST(ForwardListTest, SingleElementInsertAfter) {
    ForwardList<int> list;
    list.push_front(1);
    
    auto it = list.begin();
    list.insert_after(it, 2);
    
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);

    list.clear();
    list.insert_after(list.end(), 10);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 10);
}

TEST(ForwardListTest, SingleElementEraseAfter) {
    ForwardList<int> list;
    list.push_front(1);
    
    auto it = list.begin();
    list.erase_after(it); 
    
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 1);
    
    
    list.erase_after(list.end()); 
    EXPECT_TRUE(list.empty());
}

TEST(ForwardListTest, SingleElementAfterMultipleOperations) {
    ForwardList<int> list;
    
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    
    list.pop_front(); 
    list.pop_front(); 
    
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 1);
    
    EXPECT_FALSE(list.empty());
    EXPECT_NE(list.begin(), list.end());
    EXPECT_EQ(*list.begin(), 1);
    
    auto it = list.begin();
    list.insert_after(it, 4);
    
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 4);
}


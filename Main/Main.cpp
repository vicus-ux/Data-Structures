#include <iostream>
#include "../test/test_structures.cpp"
#include "../include/Queue.h"
#include "../include/Stack.h"
#include "../include/Task.h"



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
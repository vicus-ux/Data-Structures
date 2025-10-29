#ifndef TASKS_H
#define TASKS_H

#include "Stack.h"
#include "Queue.h"
#include <string>

// Задача 1: Проверка баланса скобок
class BracketChecker {
public:
    static bool check(const std::string& expression) {
        Stack<char> stack;
        
        for (char ch : expression) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stack.push(ch);
            }
            else if (ch == ')' || ch == ']' || ch == '}') {
                if (stack.empty()) return false;
                
                char top = stack.top();
                if ((ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{')) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        
        return stack.empty();
    }
};

// Задача 2: Очередь на двух стеках
template<class T>
class QueueFromStacks {
    Stack<T> inStack;
    Stack<T> outStack;
    
    void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
    
public:
    void push(const T& value) {
        inStack.push(value);
    }
    
    void pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        
        if (outStack.empty()) {
            transfer();
        }
        outStack.pop();
    }
    
    T& front() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        
        if (outStack.empty()) {
            transfer();
        }
        return outStack.top();
    }
    
    bool empty() const {
        return inStack.empty() && outStack.empty();
    }
    
    size_t size() const {
        return inStack.size() + outStack.size();
    }
};

#endif
#ifndef QUEUE_H
#define QUEUE_H

#include "MyVector.h"
#include <stdexcept>

template<class T, template<class U> class TContainer = MyVector>
class Queue {
private:
    TContainer<T> data;

public:
    Queue() = default;
    
    // Добавление в конец
    void push(const T& value) {
        data.push_back(value);
    }
    
    void push(T&& value) {
        data.push_back(std::move(value));
    }
    
    // Удаление из начала
    void pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        data.erase(0);
    }
    
    // Доступ к первому элементу
    T& front() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data[0];
    }
    
    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data[0];
    }
    
    // Доступ к последнему элементу
    T& back() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data[data.size() - 1];
    }
    
    const T& back() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data[data.size() - 1];
    }
    
    // Состояние
    bool empty() const {
        return data.empty();
    }
    
    size_t size() const {
        return data.size();
    }
    
    // Очистка
    void clear() {
        data.clear();
    }
};

#endif // QUEUE_H
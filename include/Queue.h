#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <stdexcept>

template<class T>
class Queue {
private:
    std::vector<T> data;
    size_t head = 0;
    size_t count = 0;

    size_t tail() const {
        return (head + count) % data.size();
    }

public:
    Queue() : data(8) {} //задаю какой-то начальный размер
    
    void push(const T& value) {
        if (count == data.size()) {
            std::vector<T> new_data(data.size() * 2);
            for (size_t i = 0; i < count; ++i) {
                new_data[i] = std::move(data[(head + i) % data.size()]);
            }
            data = std::move(new_data);
            head = 0;
        }
        data[tail()] = value;
        count++;
    }
    
    void pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        head = (head + 1) % data.size();
        count--;
    }
    
    T& front() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data[head];
    }
    
    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data[head];
    }
    
    T& back() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data[(head + count - 1) % data.size()];
    }
    
    const T& back() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data[(head + count - 1) % data.size()];
    }
    
    bool empty() const {
        return count == 0;
    }
    
    size_t size() const {
        return count;
    }
    
    void clear() {
        head = 0;
        count = 0;
    }
};

#endif // QUEUE_H
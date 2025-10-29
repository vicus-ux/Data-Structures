    #include <iostream>
    #include <cmath>

    #define FACTOR 2

    template <typename T>
    class MyVector {
    private:
        T* data = nullptr;
        size_t sizeVector = 0;
        size_t capacity = 0;

    public:
        MyVector() {};
        MyVector(size_t size, T value);

        // Rule of three
        ~MyVector();
        MyVector(const MyVector& copy);
        MyVector& operator=(const MyVector& v);

        T& operator[](size_t index);
        T operator[](size_t index) const;
        T& at(size_t index);
        T at(size_t index) const;

        T& back();
        const T& back() const;

        bool empty() const;
        size_t length() const;
        size_t size() const;
        void print() const;
        void clear();

        void reserve(size_t newCapacity);
        size_t help(size_t sizeVector) {
            return (sizeVector > 0) ? sizeVector * 2 : 1;
        }
        void swap(MyVector& other);
        void resize(size_t count);
        size_t insert(size_t pos, T value);
        size_t insert(size_t pos, const MyVector& subv);
        size_t erase(size_t pos);
        void push_back(T value);
        void pop_back();
    };

    template <typename T>
    MyVector<T>::MyVector(size_t size, T value) {
        resize(size);
        for (size_t i = 0; i < sizeVector; i++) {
            data[i] = value;
        }
        capacity = size;
    }

    template <typename T>
    MyVector<T>::~MyVector() {
        delete[] data;
    }

    template <typename T>
    MyVector<T>::MyVector(const MyVector& copy)
        : data(nullptr), sizeVector(0), capacity(0)
    {
        if (copy.data && copy.sizeVector <= copy.capacity)
        {
            data = new T[copy.capacity];
            sizeVector = copy.sizeVector;
            capacity = copy.capacity;

            for (size_t i = 0; i < sizeVector; i++)
            {
                data[i] = copy.data[i];
            }
        }
        else
        {
            sizeVector = 0;
            capacity = 0;
            data = nullptr;
        }
    }

    template <typename T>
    MyVector<T>& MyVector<T>::operator=(const MyVector& v) {
        if (&v != this) {
            resize(v.sizeVector);
            for (size_t i = 0; i < sizeVector; i++) {
                data[i] = v.data[i];
            }
        }
        return *this;
    }

    template <typename T>
    T& MyVector<T>::operator[](size_t index) {
        return data[index];
    }

    template <typename T>
    T MyVector<T>::operator[](size_t index) const {
        return data[index];
    }

    template <typename T>
    T& MyVector<T>::at(size_t index) {
        if (index >= sizeVector) {
            throw "Index out of range";
        }
        return data[index];
    }

    template <typename T>
    T MyVector<T>::at(size_t index) const {
        if (index >= sizeVector) {
            throw "Index out of range";
        }
        return data[index];
    }

    template <typename T>
T& MyVector<T>::back() {
    if (empty()) {
        throw "Vector is empty";
    }
    return data[sizeVector - 1];
}

template <typename T>
const T& MyVector<T>::back() const {
    if (empty()) {
        throw "Vector is empty";
    }
    return data[sizeVector - 1];
}

    template <typename T>
    bool MyVector<T>::empty() const {
        return sizeVector == 0;
    }

    template <typename T>
    size_t MyVector<T>::length() const {
        return sizeVector;
    }

    template <typename T>
    size_t MyVector<T>::size() const {
        return sizeVector;
    }

    template <typename T>
    void MyVector<T>::print() const {
        for (size_t i = 0; i < sizeVector; i++) std::cout << data[i] << " ";
        std::cout << std::endl;
    }

    template <typename T>
    void MyVector<T>::clear() {
        if (data != nullptr) {
            delete[] data;
            data = nullptr;
        }
        sizeVector = 0;
        capacity = 0;
    }

    template <typename T>
    void MyVector<T>::swap(MyVector& other) {
        std::swap(sizeVector, other.sizeVector);
        std::swap(data, other.data);
        std::swap(capacity, other.capacity);
    }

    template <typename T>
    void MyVector<T>::resize(size_t count) {
        if (capacity >= count) {
            sizeVector = count;
            return;
        }
        reserve(FACTOR * count);
        sizeVector = count;
    }

    template <typename T>
    void MyVector<T>::reserve(size_t newCapacity) {
        if (capacity >= newCapacity) return;
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < sizeVector; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    template <typename T>
    size_t MyVector<T>::insert(size_t pos, T value) {
        resize(sizeVector + 1);
        for (size_t i = sizeVector - 1; i > pos; i--) {
            data[i] = data[i - 1];
        }
        data[pos] = value;
        return pos;
    }

    template <typename T>
    size_t MyVector<T>::insert(size_t pos, const MyVector& subv) {
        if (pos > sizeVector) {
            std::cout << "Error: Out-of-bounds" << "\n";
            return sizeVector;
        }
        if (sizeVector + subv.sizeVector > capacity) {
            resize(std::max(capacity * 2, sizeVector + subv.sizeVector));
        }

        for (size_t i = sizeVector; i > pos; i--) {
            data[i + subv.sizeVector - 1] = data[i - 1];
        }

        for (size_t i = 0; i < subv.sizeVector; i++) {
            data[pos + i] = subv.data[i];
        }
        sizeVector += subv.sizeVector;
        return pos;
    }

    template <typename T>
    size_t MyVector<T>::erase(size_t pos) {
        if (pos >= sizeVector) {
            throw "Error erase";
        }
        for (size_t i = pos; i < sizeVector - 1; i++) {
            data[i] = data[i + 1];
        }
        resize(sizeVector - 1);
        return pos; 
    }

    template <typename T>
    void MyVector<T>::push_back(T value) {
        resize(sizeVector + 1);
        data[sizeVector - 1] = value;
    }

    template <typename T>
    void MyVector<T>::pop_back() {
        if (sizeVector > 0) {
            sizeVector--;
        }
    }
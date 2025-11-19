#ifndef TASKS_H
#define TASKS_H

#include "Stack.h"
#include "Queue.h"
#include <string>
#include "ForwardList.h"

// task 1 , которое про скобочки
class BracketChecker {
public:
    static bool check(const std::string& str) {
        Stack<char> stack;
        
        for (char ch : str) {
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

// task 2 , которое очередь на двух стеках
//в inStack добавляем , из outStack извлекаем
//если outStack пусто переложим из inStack туда, элементы перевернутся по дефолту, можем извлечь элемент который лежал в самом низу первым
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


//////для листа задачка

namespace Task {
/*  Печать элементов списка в обратном порядке за O(n) времени и O(1) памяти
    список в конце должен быть не поломанным */


/*идея решения: первым проходом разворачиваю все указатели next
    вторым проходом вывожу все элементы в нужном порядке
    третьим проходом возвращаю всё на места*/


/*попробую доказать, что время O(n) , а память O(1):
    1) по памяти короче, использую prev -указатель , O(1) cur -указатель , O(1),next -указатель , O(1)
    всего три прохода , во втором переиспользуется cur, в третьем переиспользуется next and prev
    по сути ни массивов ничего такого я не создаю, три прохода используют одни и те же указатели, но просто переиспользованные,
    значит по идее по памяти O(1) выполняется
    
    2) по времени: делаю 3 цикла, которые проходят по списку длиной n:
    while(cur != nullprt) - n итераций, таких 3, значит 3n, значит O(3n), значит O(n), значит круто
    
    3)ну а за 3 прохода, я перевернула указатели,вывела список, ну и вернула на место всё, так что список не ломала*/
template <typename T>
void printReverse(const ForwardList<T>& list)
{
    if (list.empty()) return;

    // Временно снимаем const для модификации (осторожно!)
    using Node = typename ForwardList<T>::Node;
    Node* head = const_cast<Node*>(list.first);
    
    if (head == nullptr) return;

    // 1. Разворот списка
    Node* prev = nullptr;
    Node* cur = head;
    Node* next = nullptr;
    
    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    // Теперь prev - новая голова перевернутого списка

    // 2. Печать перевернутого списка (который теперь в прямом порядке)
    cur = prev;
    while (cur != nullptr) {
        std::cout << cur->data << ' ';
        cur = cur->next;
    }
    std::cout << '\n';

    // 3. Восстанавливаем исходный порядок, снова разворачивая список
    cur = prev;
    prev = nullptr;
    next = nullptr;
    
    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    // Теперь prev снова указывает на исходную голову
    
    // Восстанавливаем указатель в исходном списке
    const_cast<ForwardList<T>&>(list).first = prev;
}
}
#endif // TASKS_H
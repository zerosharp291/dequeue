#pragma once
#include <iostream>
#include <ostream>

// узел
template<typename T>
struct node {
    T info; // содержимое узла
    node *next; // ссылка не следующий узел

    explicit node(T x) : info(x), next(nullptr) {
    }

    ~node() = default;
};

// очередь
template<typename T>
class queue {
public:
    queue() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~queue() {
        node<T> *tmp = nullptr;
        while (head != nullptr) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
    }

    void push(T x) {
        // добавление элементов в очередь
        node<T> *tmp = new node(x);
        if (head == nullptr) {
            // проверка, пустая ли очередь
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }
        count++; // подсчет количества элементов в очереди
    }

    T pop() {
        if (head == nullptr) {
            std::cout << "Empty Queue" << std::endl;
        }
        node<T> *tmp = head;
        T value = tmp->info;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr; // Исправлено: tail = nullptr вместо tail == nullptr
        }
        delete tmp;
        count--; // уменьшить счетчик
        return value;
    }

    node<T> *get_head() const {
        return head;
    }

    [[nodiscard]] int get_count() const { return count; }

private:
    node<T> *head; // голова очереди
    node<T> *tail; // ее хвост
    int count; // число элементов в очереди
};

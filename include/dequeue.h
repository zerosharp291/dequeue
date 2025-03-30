//
// Created by zeros on 29.03.2025.
//

#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <iostream>

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
class dequeue {
public:
    dequeue() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~dequeue() {
        node<T> *tmp = nullptr;
        while (head != nullptr) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
    }

    void push_back(T x) {
        // добавление элемента в конец дека
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

    void push_front(T x) {
        // добавление элемента в начало декa
        node<T> *tmp = new node(x);
        if (head == nullptr) {
            // проверка, пустая ли очередь
            head = tmp;
            tail = tmp;
        } else {
            tmp->next = head;
            head = tmp;
        }
        count++; // подсчет количества элементов в очереди
    }

    T pop_front() {
        // возвращение с удалением элемента из начала дека
        if (head == nullptr) {
            std::cout << "Empty dequeue" << std::endl;
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
    T pop_back() {
        // возвращение с удалением элемента из конца дека
        if (head == nullptr) {
            std::cout << "Empty dequeue" << std::endl;
        }
        node<T> *tmp = tail;
        T value = tmp->info;
        head = head->next; // NEED FIX
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



#endif //DEQUEUE_H

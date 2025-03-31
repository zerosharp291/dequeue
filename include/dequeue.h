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
    node *prev;

    explicit node(T x) : info(x), next(nullptr), prev(nullptr) {}

    ~node() = default;
};

template<typename T>
class dequeue {
    // Реализация структуры Дек с элементами произвольного типа
public:
    dequeue(): head(nullptr), tail(nullptr), size(0) {}

    ~dequeue() {
        // удаление узлов через перебор
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
            // если очередь пустая, то элемент будет и начальным, и конечным
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp; // ссылка на новый хвостовой элемент
            tmp->prev = tail; // в новый хвостовой элемент добавляем ссылку на предыдущий
            tail = tmp;
        }
        size++; // подсчет количества элементов в очереди
    }

    void push_front(T x) {
        // добавление элемента в начало дека
        node<T> *tmp = new node(x);
        if (head == nullptr) {
            // если очередь пустая, то элемент будет и начальным, и конечным
            head = tmp;
            tail = tmp;
        } else {
            tmp->next = head; // старый головной элемент смещается
            head->prev = tmp;
            head = tmp;
        }
        size++; // подсчет количества элементов в очереди
    }

    T pop_front() {
        // возвращение с удалением элемента из начала дека
        if (head == nullptr) {
            std::cout << "Empty dequeue" << std::endl;
        }
        node<T> *tmp = head; // сохраним указатель на удаляемый элемент
        T value = tmp->info; // скопируем содержимое удаляемого элемента для того чтобы его вернуть
        head = head->next; // обновим головной элемент
        if (head == nullptr) {
            // на случай достижения конца дека
            tail = nullptr;
        }
        head->prev = nullptr; // удалим указатель на предыдущий головной элемент
        delete tmp; // удаляем головной узел
        size--; // уменьшаем счетчик
        return value;
    }

    T pop_back() {
        // возвращение с удалением элемента из конца дека
        if (head == nullptr) {
            std::cout << "Empty dequeue" << std::endl;
        }
        node<T> *tmp = tail; // сохраним указатель на удаляемый элемент
        T value = tmp->info; // скопируем содержимое удаляемого элемента для того чтобы его вернуть

        tail = tail->prev; // новый хвостовой элемент
        tail->next = nullptr; // удалим связь с предыдущим хвостовым элементом

        if (tail == nullptr) {
            // на случай достижения начала дека
            head = nullptr;
        }

        delete tmp; // удаляем
        size--; // уменьшаем счетчик
        return value;
    }

    T &get_head() const {
        // получить значение головного элемента
        return head->info;
    }

    T &get_tail() const {
        // получить значение хвостового элемента
        return tail->info;
    }

    [[nodiscard]] size_t get_count() const { return size; }

private:
    node<T> *head; // голова очереди
    node<T> *tail; // ее хвост
    size_t size; // размер дека
};


#endif //DEQUEUE_H

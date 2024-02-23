//
// Created by ivanh on 22.02.2024.
//

#include <iostream>

// Шаблон класса для односвязного линейного списка
template<typename T>
class LinkedList {
private:
    // Внутренний класс для представления узла списка
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* head; // Указатель на начало списка
    Node* tail; // Указатель на конец списка
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Деструктор для освобождения памяти
    ~LinkedList() {
        clear();
    }

    // Метод для добавления элемента в конец списка
    void add(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Метод для очистки списка (освобождение памяти)
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    // Метод для вывода списка
    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Пример использования шаблонного класса LinkedList
    LinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.print(); // Вывод: 1 2 3

    LinkedList<std::string> strList;
    strList.add("Hello");
    strList.add("World");
    strList.print(); // Вывод: Hello World

    return 0;
}
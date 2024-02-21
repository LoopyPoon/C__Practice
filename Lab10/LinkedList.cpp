//
// Created by ivanh on 21.02.2024.
//

#include <iostream>

// Структура узла списка
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Функция для создания нового узла списка
Node* createNode(int d) {
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Функция для формирования первого элемента
void first(Node** pbeg, Node** pend, int d) {
    Node* newNode = createNode(d);
    *pbeg = newNode;
    *pend = newNode;
}

// Функция для добавления в конец списка
void add(Node** pend, int d) {
    Node* newNode = createNode(d);
    (*pend)->next = newNode;
    newNode->prev = *pend;
    *pend = newNode;
}

// Функция для поиска по ключу
Node* find(Node* const pbeg, int d) {
    Node* current = pbeg;
    while (current != nullptr) {
        if (current->data == d) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Возвращаем nullptr, если элемент не найден
}

// Функция для удаления элемента
void remove(Node** pbeg, Node** pend, int key) {
    Node* current = *pbeg;
    while (current != nullptr) {
        if (current->data == key) {
            if (current == *pbeg) {
                *pbeg = (*pbeg)->next;
                if (*pbeg != nullptr) {
                    (*pbeg)->prev = nullptr;
                } else {
                    *pend = nullptr;
                }
                delete current;
                return;
            } else if (current == *pend) {
                *pend = (*pend)->prev;
                (*pend)->next = nullptr;
                delete current;
                return;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                return;
            }
        }
        current = current->next;
    }
}

// Функция для вставки элемента
void insert(Node* const pbeg, Node** pend, int key, int d) {
    Node* current = pbeg;
    while (current != nullptr) {
        if (current->data == key) {
            Node* newNode = createNode(d);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            } else {
                *pend = newNode;
            }
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

// Функция для вывода списка
void printList(Node* pbeg) {
    Node* current = pbeg;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* pbeg = nullptr; // Указатель на начало списка
    Node* pend = nullptr; // Указатель на конец списка

    // Формируем список
    first(&pbeg, &pend, 1); // Первый элемент
    add(&pend, 2); // Добавляем в конец
    add(&pend, 3);
    add(&pend, 4);
    add(&pend, 5);

    std::cout << "Initial list: ";
    printList(pbeg);

    // Поиск элемента по ключу
    int key = 3;
    Node* foundNode = find(pbeg, key);
    if (foundNode != nullptr) {
        std::cout << "Element with key " << key << " found!" << std::endl;
    } else {
        std::cout << "Element with key " << key << " not found!" << std::endl;
    }

    // Удаление элемента
    key = 2;
    remove(&pbeg, &pend, key);
    std::cout << "List after removing " << key << ": ";
    printList(pbeg);

    // Вставка элемента после указанного ключа
    key = 4;
    int newData = 6;
    insert(pbeg, &pend, key, newData);
    std::cout << "List after inserting " << newData << " after " << key << ": ";
    printList(pbeg);

    return 0;
}
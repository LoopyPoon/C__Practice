//
// Created by ivanh on 22.02.2024.
//

#include <iostream>

// Структура узла списка
struct Node {
    int data;
    Node* next;
};

// Функция для создания нового узла списка
Node* createNode(int d) {
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = nullptr;
    return newNode;
}

// Функция для формирования первого элемента
void first(Node** pbeg, int d) {
    Node* newNode = createNode(d);
    *pbeg = newNode;
}

// Функция для добавления в конец списка
void add(Node** pend, int d) {
    Node* newNode = createNode(d);
    if (*pend == nullptr) {
        *pend = newNode;
    } else {
        Node* current = *pend;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функция для поиска по ключу
Node* find(Node* pbeg, int d) {
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
void remove(Node** pbeg, int key) {
    if (*pbeg == nullptr) {
        return;
    }

    if ((*pbeg)->data == key) {
        Node* temp = *pbeg;
        *pbeg = (*pbeg)->next;
        delete temp;
        return;
    }

    Node* prev = *pbeg;
    Node* current = prev->next;

    while (current != nullptr) {
        if (current->data == key) {
            prev->next = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Функция для вставки элемента
void insert(Node* pbeg, int key, int d) {
    Node* current = pbeg;
    while (current != nullptr) {
        if (current->data == key) {
            Node* newNode = createNode(d);
            newNode->next = current->next;
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
    first(&pbeg, 1); // Первый элемент
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
    remove(&pbeg, key);
    std::cout << "List after removing " << key << ": ";
    printList(pbeg);

    // Вставка элемента после указанного ключа
    key = 4;
    int newData = 6;
    insert(pbeg, key, newData);
    std::cout << "List after inserting " << newData << " after " << key << ": ";
    printList(pbeg);

    return 0;
}
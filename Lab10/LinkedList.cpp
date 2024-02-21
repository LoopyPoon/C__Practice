//
// Created by ivanh on 21.02.2024.
//

#include <iostream>

// ��������� ���� ������
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// ������� ��� �������� ������ ���� ������
Node* createNode(int d) {
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// ������� ��� ������������ ������� ��������
void first(Node** pbeg, Node** pend, int d) {
    Node* newNode = createNode(d);
    *pbeg = newNode;
    *pend = newNode;
}

// ������� ��� ���������� � ����� ������
void add(Node** pend, int d) {
    Node* newNode = createNode(d);
    (*pend)->next = newNode;
    newNode->prev = *pend;
    *pend = newNode;
}

// ������� ��� ������ �� �����
Node* find(Node* const pbeg, int d) {
    Node* current = pbeg;
    while (current != nullptr) {
        if (current->data == d) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // ���������� nullptr, ���� ������� �� ������
}

// ������� ��� �������� ��������
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

// ������� ��� ������� ��������
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

// ������� ��� ������ ������
void printList(Node* pbeg) {
    Node* current = pbeg;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* pbeg = nullptr; // ��������� �� ������ ������
    Node* pend = nullptr; // ��������� �� ����� ������

    // ��������� ������
    first(&pbeg, &pend, 1); // ������ �������
    add(&pend, 2); // ��������� � �����
    add(&pend, 3);
    add(&pend, 4);
    add(&pend, 5);

    std::cout << "Initial list: ";
    printList(pbeg);

    // ����� �������� �� �����
    int key = 3;
    Node* foundNode = find(pbeg, key);
    if (foundNode != nullptr) {
        std::cout << "Element with key " << key << " found!" << std::endl;
    } else {
        std::cout << "Element with key " << key << " not found!" << std::endl;
    }

    // �������� ��������
    key = 2;
    remove(&pbeg, &pend, key);
    std::cout << "List after removing " << key << ": ";
    printList(pbeg);

    // ������� �������� ����� ���������� �����
    key = 4;
    int newData = 6;
    insert(pbeg, &pend, key, newData);
    std::cout << "List after inserting " << newData << " after " << key << ": ";
    printList(pbeg);

    return 0;
}
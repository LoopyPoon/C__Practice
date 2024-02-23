//
// Created by ivanh on 22.02.2024.
//

#include <iostream>

// ������ ������ ��� ������������ ��������� ������
template<typename T>
class LinkedList {
private:
    // ���������� ����� ��� ������������� ���� ������
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* head; // ��������� �� ������ ������
    Node* tail; // ��������� �� ����� ������
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // ���������� ��� ������������ ������
    ~LinkedList() {
        clear();
    }

    // ����� ��� ���������� �������� � ����� ������
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

    // ����� ��� ������� ������ (������������ ������)
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    // ����� ��� ������ ������
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
    // ������ ������������� ���������� ������ LinkedList
    LinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.print(); // �����: 1 2 3

    LinkedList<std::string> strList;
    strList.add("Hello");
    strList.add("World");
    strList.print(); // �����: Hello World

    return 0;
}
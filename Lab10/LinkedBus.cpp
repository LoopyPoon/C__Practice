//
// Created by ivanh on 22.02.2024.
//

#include <iostream>
#include <string>

// ��������� ��� ������������� ������ �� ��������
struct BusInfo {
    int busNumber; // ����� ��������
    std::string driverName; // ��� ��������
    int routeNumber; // ����� ��������

    // ���������� ��������� == ��� ��������� BusInfo
    bool operator==(const BusInfo& other) const {
        return (busNumber == other.busNumber &&
                driverName == other.driverName &&
                routeNumber == other.routeNumber);
    }
};

// ������ ������ ��� ������������ ��������� ������
template<typename T>
class LinkedList {
private:
    // ���������� ����� ��� ������������� ���� ������
    struct Node {
        T data; // ������ ����
        Node* next; // ��������� �� ��������� ����
        Node(const T& d) : data(d), next(nullptr) {} // ����������� ����
    };

    Node* head; // ��������� �� ������ ������
    Node* tail; // ��������� �� ����� ������
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // ���������� ��� ������������ ������
    ~LinkedList() {
        clear(); // ������������ ������
    }

    // ����� ��� ���������� �������� � ����� ������
    void add(const T& value) {
        Node* newNode = new Node(value); // �������� ������ ����
        if (!head) {
            head = newNode; // ���� ������ ����, ����� ���� ���������� ��������
            tail = newNode; // � ���������
        } else {
            tail->next = newNode; // ����� ��������� ����� ���� � ����� ������
            tail = newNode;
        }
    }

    // ����� ��� �������� �������� �� ������
    void remove(const T& value) {
        if (!head)
            return; // ���� ������ ����, �������

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp; // ������� ������ ���� ������
            if (!head)
                tail = nullptr; // ���� ��������� ���� ��� ���������, �������� �����
            return;
        }

        Node* prev = head;
        Node* current = head->next;

        while (current) {
            if (current->data == value) {
                prev->next = current->next;
                delete current; // ������� ������� ���� ������
                if (!prev->next)
                    tail = prev; // ���� ��������� ���� ��� ���������, ��������� �����
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // ����� ��� ������� ������ (������������ ������)
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp; // ������� ���� � ��������� � ����������
        }
        tail = nullptr; // �������� �����
    }

    // ����� ��� ������ ������
    void print() const {
        Node* current = head;
        while (current) {
            std::cout << "Bus number: " << current->data.busNumber << ", Driver: " << current->data.driverName << ", Route: " << current->data.routeNumber << std::endl;
            current = current->next;
        }
    }
};

int main() {
    // Create lists for buses in the park and on the route
    LinkedList<BusInfo> parkBuses;
    LinkedList<BusInfo> routeBuses;

    // Add initial data about buses in the park
    parkBuses.add({101, "John Doe", 1});
    parkBuses.add({102, "Jane Smith", 2});
    parkBuses.add({103, "Bob Johnson", 3});

    char choice;
    do {
        std::cout << "Choose an action:\n"
                     "1. Bus leaving the park\n"
                     "2. Bus entering the park\n"
                     "3. Display buses in the park\n"
                     "4. Display buses on the route\n"
                     "5. Exit\n"
                     "Your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                int busNumber;
                std::cout << "Enter the bus number leaving the park: ";
                std::cin >> busNumber;
                BusInfo bus = {busNumber, "", 0};
                parkBuses.remove(bus);
                routeBuses.add(bus);
                break;
            }
            case '2': {
                int busNumber;
                std::cout << "Enter the bus number entering the park: ";
                std::cin >> busNumber;
                BusInfo bus = {busNumber, "", 0};
                routeBuses.remove(bus);
                parkBuses.add(bus);
                break;
            }
            case '3':
                std::cout << "Buses in the park:\n";
                parkBuses.print();
                break;
            case '4':
                std::cout << "Buses on the route:\n";
                routeBuses.print();
                break;
            case '5':
                std::cout << "Program terminated.\n";
                break;
            default:
                std::cout << "Invalid input. Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}
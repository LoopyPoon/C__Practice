//
// Created by ivanh on 22.02.2024.
//

#include <iostream>
#include <string>

// Структура для представления данных об автобусе
struct BusInfo {
    int busNumber; // Номер автобуса
    std::string driverName; // ФИО водителя
    int routeNumber; // Номер маршрута

    // Перегрузка оператора == для сравнения BusInfo
    bool operator==(const BusInfo& other) const {
        return (busNumber == other.busNumber &&
                driverName == other.driverName &&
                routeNumber == other.routeNumber);
    }
};

// Шаблон класса для односвязного линейного списка
template<typename T>
class LinkedList {
private:
    // Внутренний класс для представления узла списка
    struct Node {
        T data; // Данные узла
        Node* next; // Указатель на следующий узел
        Node(const T& d) : data(d), next(nullptr) {} // Конструктор узла
    };

    Node* head; // Указатель на начало списка
    Node* tail; // Указатель на конец списка
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Деструктор для освобождения памяти
    ~LinkedList() {
        clear(); // Освобождение памяти
    }

    // Метод для добавления элемента в конец списка
    void add(const T& value) {
        Node* newNode = new Node(value); // Создание нового узла
        if (!head) {
            head = newNode; // Если список пуст, новый узел становится головным
            tail = newNode; // и хвостовым
        } else {
            tail->next = newNode; // Иначе добавляем новый узел в конец списка
            tail = newNode;
        }
    }

    // Метод для удаления элемента из списка
    void remove(const T& value) {
        if (!head)
            return; // Если список пуст, выходим

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp; // Удаляем первый узел списка
            if (!head)
                tail = nullptr; // Если удаляемый узел был последним, обнуляем хвост
            return;
        }

        Node* prev = head;
        Node* current = head->next;

        while (current) {
            if (current->data == value) {
                prev->next = current->next;
                delete current; // Удаляем текущий узел списка
                if (!prev->next)
                    tail = prev; // Если удаляемый узел был последним, обновляем хвост
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Метод для очистки списка (освобождение памяти)
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp; // Удаляем узел и переходим к следующему
        }
        tail = nullptr; // Обнуляем хвост
    }

    // Метод для вывода списка
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
//
// Created by ivanh on 21.02.2024.
//

#include <iostream>
#include <vector>
#include <stack>

// ���� ����� ������������ ����, ������� ������������ � �������� ����������
template <class T>
class TStack {
protected:
    T* item;
public:
    TStack(int size = 10) {
        numItem = 0; // ����������� ���������� ��������� � �����
        item = new T[size]; // ������������ ��� �������� ��������� �����
    }
    ~TStack() {
        delete[] item;
    }
    void push(T t);
    T pop();

    int numItem;
};
// ������������ ��� ���������� �������� � ����
template <class T>
void TStack<T>::push(T t) {
    item[numItem++] = t;
}
// ������������ ��� ���������� �������� �� �����
template <class T>
T TStack<T>::pop() {
    return item[--numItem];
}

// ��� �������, ������� ��������� ���������� ���������������� �������
template <class T>
void sortTrain(std::vector<T>& train) {
    // ��������� ������ station ���� TStack,
    // ������� ����� �������������� � �������� ������ ��� ���������� �������� ������� � �������� ����������
    TStack<T> station(train.size());

    std::vector<T> sortedTrain; // ����� ������� ��������������� ������

    // ������ �� ���� �������
    for (const auto& wagon : train) {
        // ���� sortedTrain ���� ��� ������� ����� ������ ���������� ������ � sortedTrain, ������� ����� ����������� � ����� sortedTrain.
        if (sortedTrain.empty() || wagon > sortedTrain.front()) {
            sortedTrain.insert(sortedTrain.begin(), wagon);
        } else {
            // ���� ������� ����� ������ ���������� ������ � sortedTrain, �� ������������� ������ �� sortedTrain � station,
            // ���� �� ������ ����� ��� �������� ������ � sortedTrain. ����� ��������� ������� ����� � sortedTrain.
            while (!sortedTrain.empty() && wagon < sortedTrain.front()) {
                station.push(sortedTrain.front());
                sortedTrain.erase(sortedTrain.begin());
            }
            sortedTrain.insert(sortedTrain.begin(), wagon);
            while (station.numItem > 0) {
                sortedTrain.insert(sortedTrain.begin(), station.pop());
            }
        }
    }

    // ����� ���������� ����� �� ��������� ��� ������ �� station � ��������� �� � sortedTrain, ����� ��������� ����������.
    while (station.numItem > 0) {
        sortedTrain.insert(sortedTrain.begin(), station.pop());
    }

    train = sortedTrain;
}

int main() {
    std::vector<int> train = {1, 5, 3}; // ��������������� ������

    sortTrain(train);

    std::cout << "Sorted train: ";
    for (const auto& wagon : train) {
        std::cout << wagon << " ";
    }
    std::cout << std::endl;

    return 0;
}
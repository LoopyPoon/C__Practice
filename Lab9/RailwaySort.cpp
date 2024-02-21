//
// Created by ivanh on 21.02.2024.
//

#include <iostream>
#include <vector>
#include <stack>

// Этот класс представляет стек, который используется в процессе сортировки
template <class T>
class TStack {
protected:
    T* item;
public:
    TStack(int size = 10) {
        numItem = 0; // отслеживает количество элементов в стеке
        item = new T[size]; // используется для хранения элементов стека
    }
    ~TStack() {
        delete[] item;
    }
    void push(T t);
    T pop();

    int numItem;
};
// используется для добавления элемента в стек
template <class T>
void TStack<T>::push(T t) {
    item[numItem++] = t;
}
// используется для извлечения элемента из стека
template <class T>
T TStack<T>::pop() {
    return item[--numItem];
}

// Это функция, которая выполняет сортировку железнодорожного состава
template <class T>
void sortTrain(std::vector<T>& train) {
    // Создается объект station типа TStack,
    // который будет использоваться в качестве тупика для временного хранения вагонов в процессе сортировки
    TStack<T> station(train.size());

    std::vector<T> sortedTrain; // будет хранить отсортированный состав

    // проход по всем вагонам
    for (const auto& wagon : train) {
        // Если sortedTrain пуст или текущий вагон больше последнего вагона в sortedTrain, текущий вагон добавляется в конец sortedTrain.
        if (sortedTrain.empty() || wagon > sortedTrain.front()) {
            sortedTrain.insert(sortedTrain.begin(), wagon);
        } else {
            // Если текущий вагон меньше последнего вагона в sortedTrain, мы перекладываем вагоны из sortedTrain в station,
            // пока не найдем место для текущего вагона в sortedTrain. Затем добавляем текущий вагон в sortedTrain.
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

    // После завершения цикла мы извлекаем все вагоны из station и добавляем их в sortedTrain, чтобы завершить сортировку.
    while (station.numItem > 0) {
        sortedTrain.insert(sortedTrain.begin(), station.pop());
    }

    train = sortedTrain;
}

int main() {
    std::vector<int> train = {1, 5, 3}; // железнодорожный состав

    sortTrain(train);

    std::cout << "Sorted train: ";
    for (const auto& wagon : train) {
        std::cout << wagon << " ";
    }
    std::cout << std::endl;

    return 0;
}
//
// Created by ivanh on 20.02.2024.
//
#include <iostream>


// Создаем шаблон
template <class T>
    void Sort(T array[], int size) {
        int i, j;
        T tmp;
        for (i = 0; i < size - 1; i++) {
            for (j = size - 1; i < j; j--) {
                if (array[i] > array[j]) {
                    // Обмен значениями
                    tmp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = tmp;
                }
            }
        }
    }

int main() {

    int intArray[] = {5, 2, 9, 1, 6};
    double doubleArray[] = {3.5, 1.2, 7.8, 2.4, 5.9};
    char charArray[] = {'e', 'g', 'a', 'c', 'f'};

    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    int charSize = sizeof(charArray) / sizeof(charArray[0]);

    Sort(intArray, intSize);
    Sort(doubleArray, doubleSize);
    Sort(charArray, charSize);

    std::cout << "Sorted int array:";
    for (int i = 0; i < intSize; ++i) {
        std::cout << " " << intArray[i];
    }
    std::cout << std::endl;

    std::cout << "Sorted double array:";
    for (int i = 0; i < doubleSize; ++i) {
        std::cout << " " << doubleArray[i];
    }
    std::cout << std::endl;

    std::cout << "Sorted char array:";
    for (int i = 0; i < charSize; ++i) {
        std::cout << " " << charArray[i];
    }
    std::cout << std::endl;

    return 0;
}
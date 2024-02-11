//
// Created by ivanh on 11.02.2024.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Функция для сортировки массива по возрастанию четных и по убыванию нечетных значений
void sortArray(vector<int>& arr) {
    // Фильтруем четные элементы и сортируем их по возрастанию
    sort(arr.begin(), arr.end(), [](int a, int b) {
        // Возвращаем true, если a и b оба четные, иначе false
        if (a % 2 == 0 && b % 2 == 0)
            return a < b;
        // Возвращаем false, если a и b оба нечетные, иначе true
        if (a % 2 != 0 && b % 2 != 0)
            return a > b;
        // Возвращаем true, если a четное, иначе false
        return a % 2 == 0;
    });
}

int main() {
    // Создаем исходный массив
    vector<int> arr = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};

    // Выводим исходный массив
    cout << "Array before sorting: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Сортируем массив
    sortArray(arr);

    // Выводим отсортированный массив
    cout << "Array after sorting: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
//
// Created by ivanh on 09.02.2024.
//
#include <iostream>
#include <vector>

#include <iostream>

using namespace std;

int main()
{
    int arr[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};

    // Ввод количества элементов массива
    int n = sizeof(arr) / sizeof(int);
    cout << "n = " << n << endl;

    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    int temp; // временная переменная для обмена элементов местами

    // Сортировка массива пузырьком
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // меняем элементы местами
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Вывод отсортированного массива на экран
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


//
// Created by ivanh on 11.02.2024.
//

#include <iostream>
using namespace std;

void ascendingSort(int *arr, int start, int end, int size) {
    // Количества элементов массива
    int n = size;

    int temp; // временная переменная для обмена элементов местами

    // Сортировка массива пузырьком
    for (int i = start; i < end; i++) {
        for (int j = start; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // меняем элементы местами
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};

    // Ввод количества элементов массива
    int n = sizeof(arr) / sizeof(int);
    cout << "n = " << n << endl;

    cout << "Array before sorting:" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    cout << "Enter start index:";
    int s;
    cin >> s;

    cout << "Enter end index:";
    int e;
    cin >> e;

    cout << "Sort by interval between " << s << " and " << e << endl;
    ascendingSort(arr, s, e, n);

    // Вывод отсортированного массива на экран
    cout << "Array after sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

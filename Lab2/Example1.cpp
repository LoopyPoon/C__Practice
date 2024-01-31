//
// Created by ivanh on 29.01.2024.
//

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <vector>

#define N 5
using namespace std;

// Функция для нахождения минимума матрицы
float findMinMatrix(float m[N][N]) {
    float minVal = m[0][0]; // Объявляем значение с индексом [0][0] за минимум матрицы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { // Если находим значение меньше объявляем его минимальным
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
    }
    return minVal;
}

// Функция для нахождения максимума матрицы
float findMaxMatrix(float m[N][N]) {
    float maxVal = m[0][0]; // Объявляем значение с индексом [0][0] за максимум матрицы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { // Если находим значение больше объявляем его максимальным
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
    }
    return maxVal;
}

// Функция для нахождения максимума нижнетреугольной части матрицы
float findMaxLowerTriangular(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) { // Делаем цикл до второго индекса, тем самым проходим ниже главной диагонали
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
    }
    return maxVal;
}

// Функция для нахождения максимума верхнетругольной части матрицы
float findMaxUpperTriangular(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) { // Присваиваем переменной счетчику j значение i => Проходим по верхней диагонали
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
    }
    return maxVal;
}

// Функция для нахождения минимума нижнетреугольной части матрицы
float findMinLowerTriangular(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
    }
    return minVal;
}

// Функция для нахождения минимума верхнетругольной части матрицы
float findMinUpperTriangular(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
    }
    return minVal;
}

// Функция для нахождения максимума главной диагональной матрицы
float findMaxMainDiagonal(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) { // Цикл прохода по главной диагонали, путем повторения индексов матрицы
        if (m[i][i] > maxVal) {
            maxVal = m[i][i];
        }
    }
    return maxVal;
}

// Функция для нахождения минимума главной диагональной матрицы
float findMinMainDiagonal(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        if (m[i][i] < minVal) {
            minVal = m[i][i];
        }
    }
    return minVal;
}

// Функция для нахождения максимума второстепенной диагонали матрицы
float findMaxSecondaryDiagonal(float m[N][N]) {
    float maxVal = m[0][N - 1]; // Обозначаем за начальный индекс последний элемент первой строки
    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] > maxVal) {
            maxVal = m[i][N - 1 - i];
        }
    }
    return maxVal;
}

// Функция для нахождения минимума второстепенной диагонали матрицы
float findMinSecondaryDiagonal(float m[N][N]) {
    float minVal = m[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] < minVal) {
            minVal = m[i][N - 1 - i];
        }
    }
    return minVal;
}

// Функция для нахождения среднеарифметического значения элементов матрицы
float findAverage(float m[N][N]) {
    float sum = 0; // Начальная сумма
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += m[i][j]; // Проходим циклом по всем элементам и находим их сумму
        }
    }
    return sum / (N * N); // Делим сумму на количество элементов
}

// Функция для нахождения среднеарифметического значения элементов нижнетреугольной части матрицы
float findAverageLowerTriangular(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// Функция для нахождения среднеарифметического значения элементов верхнетреугольной части матрицы
float findAverageUpperTriangular(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// Функция для нахождения суммы элементов строк матрицы
vector<float> findSumRows(float m[N][N]) { // функция будет возвращать коллекцию "vector"
    vector<float> rowSums(N, 0); // Колллекция будет состоять из 5 элементов
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { // В нее будут записываться суммы строк
            rowSums[i] += m[i][j];
        }
    }
    return rowSums;
}

// Функция для нахождения суммы элементов столбцов матрицы
vector<float> findSumColumns(float m[N][N]) {
    vector<float> colSums(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            colSums[j] += m[i][j];
        }
    }
    return colSums;
}

// Функция для нахождения минимального значения строк
vector<float> findMinRows(const float m[N][N]) {
    vector<float> rowMins(N, m[0][0]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] < rowMins[i]) {
                rowMins[i] = m[i][j];
            }
        }
    }
    return rowMins;
}

// Функция для нахождения минимального значения столбцов
vector<float> findMinColumns(const float m[N][N]) {
    vector<float> colMins(N, m[0][0]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] < colMins[j]) {
                colMins[j] = m[i][j];
            }
        }
    }
    return colMins;
}

// Функция для нахождения максимального значения строк
vector<float> findMaxRows(const float m[N][N]) {
    vector<float> rowMaxs(N, m[0][0]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] > rowMaxs[i]) {
                rowMaxs[i] = m[i][j];
            }
        }
    }
    return rowMaxs;
}

// Функция для нахождения максимального значения столбцов
vector<float> findMaxColumns(const float m[N][N]) {
    vector<float> colMaxs(N, m[0][0]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] > colMaxs[j]) {
                colMaxs[j] = m[i][j];
            }
        }
    }
    return colMaxs;
}

// Функция для нахождения среднеарифметического значения строк
vector<float> findAverageRows(const float m[N][N]) {
    vector<float> rowAverages(N, 0);
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
        rowAverages[i] = sum / N;
    }
    return rowAverages;
}

// Функция для нахождения среднеарифметического значения столбцов
vector<float> findAverageColumns(const float m[N][N]) {
    vector<float> colAverages(N, 0);
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < N; i++) {
            sum += m[i][j];
        }
        colAverages[j] = sum / N;
    }
    return colAverages;
}

int main() {

//    srand(time(0)); // Отключает псевдорандом

    float m[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = rand() / 10;
        }
    }

    float minVal = findMinMatrix(m);
    float maxVal = findMaxMatrix(m);
    float maxLowerTriangle = findMaxLowerTriangular(m);
    float maxUpperTriangle = findMaxUpperTriangular(m);
    float minLowerTriangle = findMinLowerTriangular(m);
    float minUpperTriangle = findMinUpperTriangular(m);
    float maxMainDiagonal = findMaxMainDiagonal(m);
    float minMainDiagonal = findMinMainDiagonal(m);
    float maxSecondaryDiagonal = findMaxSecondaryDiagonal(m);
    float minSecondaryDiagonal = findMinSecondaryDiagonal(m);
    float average = findAverage(m);
    float averageLowerTriangular = findAverageLowerTriangular(m);
    float averageUpperTriangular = findAverageUpperTriangular(m);
    vector<float> sumRows = findSumRows(m);
    vector<float> sumColumns = findSumColumns(m);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(8) << setprecision(5) << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Minimal value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;
    cout << "Maximum lower triangle value: " << maxLowerTriangle << endl;
    cout << "Maximum upper triangle value: " << maxUpperTriangle << endl;
    cout << "Minimum lower triangle value: " << minLowerTriangle << endl;
    cout << "Minimum upper triangle value: " << minUpperTriangle << endl;
    cout << "Maximum main diagonal value: " << maxMainDiagonal << endl;
    cout << "Minimum main diagonal value: " << minMainDiagonal << endl;
    cout << "Maximum secondary diagonal value: " << maxSecondaryDiagonal << endl;
    cout << "Minimum secondary diagonal value: " << minSecondaryDiagonal << endl;
    cout << "Average value: " << average << endl;
    cout << "Average lower triangle value: " << averageLowerTriangular << endl;
    cout << "Average upper triangle value: " << averageUpperTriangular << endl;
    cout << "Sum of row elements: ";
    for (float el : sumRows) {
        cout << el << " ";
    }
    cout << endl;
    cout << "Sum of column elements: ";
    for (float el : sumColumns) {
        cout << el << " ";
    }
    cout << endl;

//    getch(); // Не дает программе завершиться, пока не будет введен символ
    return 0;
}




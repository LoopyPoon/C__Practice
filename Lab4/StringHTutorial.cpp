//
// Created by ivanh on 12.02.2024.
//

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char ourStr[128] = "";	// для сохранения строки
    char ourSecondStr[128] = "";

    cout << "Enter string 1:\n";
    cin.getline(ourStr, 128);

    cout << "Enter string 2:\n";
    cin.getline(ourSecondStr, 128);

    // Реализация функции strlen
        // В выходном потоке cout мы передали в функцию строку – strlen(ourStr).
        // Она посчитала длину этой строки и вернула в программу число.
    cout << "String 1 \"" << ourStr << "\" contains "
         << strlen(ourStr) << " symbols!\n\n";

    cout << "String 2 \"" << ourSecondStr << "\" contains "
         << strlen(ourSecondStr) << " symbols!\n\n";

    // Реализация функции strcat
    strcat(ourStr , ourSecondStr); // передаём вторую в функцию, тем самым конкатенируем ее с первой

    cout << "String ourStr after concatenation with ourSecondStr - \"" << ourStr << "\" \n\n";

    // Реализация функции strcpy
    strcpy(ourStr, ourSecondStr); // передаём ourStr и ourSecondStr в функцию

    // Реализуем копирование одной строки и её вставку на место другой строки.
    cout << "String ourStr after copy ourSecondStr - \"" << ourStr << "\" \n\n";

    // Реализуем функцию strcmp
        // Если строки идентичны (и по символам и по их количеству) – функция возвращает в программу число 0.
        // Если первая строка  длиннее второй – возвращает в программу число 1, а если меньше, то -1.
        // Число -1 возвращается и  тогда, когда длина строк равна, но символы строк не совпадают.
    cout << strcmp(ourStr, ourSecondStr) << endl;
    return 0;
}
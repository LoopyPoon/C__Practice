//
// Created by ivanh on 26.01.2024.
//

#include <iostream>
using namespace std;

int power(int x, int n);

int main() {

    int base, exponent;

    cout << "Enter base: ";
    cin >> base; // Вводим основание

    cout << "Enter exponent: ";
    cin >> exponent; // Вводим показатель

    int result = power(base, exponent); // Передаем в функцию основание и показатель

    cout << base << " to the power of " << exponent << " is equal to " << result << endl; // Выводим результаты

    return 0;
}

int power(int x, int n) { // Функция power, которая возводит в степень переданное число
    int p = 1;

    for(int i = 1; i <= n; i++) {
        p *= x;
    }

    return p;
}
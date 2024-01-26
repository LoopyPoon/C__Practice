#include <iostream>
using namespace std;

int main() {
    int k; // k = 0
    int power(int, int); // Объявление функции
    for (int j = 0; j < 10; j++) { // Цикл, который перебирает показатели числа от 0 до 9
        k = power(2, j); // Для числа 2 вызывается функцию power с различными показателями степени
        cout<<"j = "<<j<<", k = "<<k<<endl; // Вывод результатов
    }
    return 0;
}

int power(int x, int n) { // Функция power, которая в цикле от 0 до j возводит в степень число p
    int p = 1;
    for(int i = 1; i <= n; i++) {
        p *= x;
    }
    return p;
}
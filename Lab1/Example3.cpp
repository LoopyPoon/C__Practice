//
// Created by ivanh on 29.01.2024.
//
#include <iostream>
using namespace std;

void obmen1(int, int);
void obmen2(int*, int*);
void obmen3(int&, int&);

int main() {
    int a = 2, b = 5;
    cout << "Before exchange: a = " << a << ", b = " << b << endl;
    obmen1(a, b);
    cout << "After exchange 1: a = " << a << ", b = " << b << endl;
    obmen2(&a, &b);
    cout << "After exchange 2: a = " << a << ", b = " << b << endl;
    obmen3(a, b);
    cout << "After exchange 3: a = " << a << ", b = " << b << endl;
}

void obmen1(int x, int y) { // Принимает 2 значения типа int
    int temp = x;
    x = y;
    y = temp;
}

void obmen2(int* x, int* y) { // Принимает 2 указателя на значения типа int
    int temp = *x;
    *x = *y;
    *y = temp;
}

void obmen3(int& x, int& y) { // Принимает 2 ссылки на значения типа int
    int temp = x;
    x = y;
    y = temp;
}
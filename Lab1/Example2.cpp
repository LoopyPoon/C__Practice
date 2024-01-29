//
// Created by ivanh on 26.01.2024.
//

#include <iostream>
#include <stdio.h>
#define PR(x) printf("x=%u, *x=%d, &x=%u\n", x, *x, &x) // Функция PR(x) выводит на экран значение указателя x
#define PF(x) printf("x=%u, *x=%f, &x=%u\n", x, *x, &x)
#define PC(x) printf("x=%u, *x=%c, &x=%u\n", x, *x, &x)
using namespace std;

int main() {
    int mas[] = {100, 200, 300}; // Создание массива
    int *ptr1, *ptr2; // Определение двух указателей
    ptr1 = mas; // Указатель указывает на начало массива
    ptr2 = &mas[2]; // Указатель указывает на третий элемент массива
    cout<<"Example with variables of type integer:"<<endl;
    PR(ptr1); // Выводит информацию о первом указателе ptr1
    ptr1++; // Указатель ptr1 инкрементируется оператором ++, он начинает указывать на следующий элемент массива mas.
    PR(ptr1); // Вывод информации о новом значении указателя ptr1.
    ++ptr2; // Указатель ptr2 также инкрементируется оператором ++
    printf("ptr2 - ptr1 = %u\n", ptr2 - ptr1); // Выводится разница между указателями ptr2 и ptr1

    // Изменение типа данных на float
    float masf[] = {1.1, 2.2, 3.3};
    float *ptrf1, *ptrf2;
    ptrf1 = masf;
    ptrf2 = &masf[2];
    cout<<"Example with variables of type float:"<<endl;
    PF(ptrf1);
    ptrf1++;
    PF(ptrf1);
    ++ptrf2;
    printf("ptrf2 - ptrf1 = %u\n", ptrf2 - ptrf1);

    // Изменение типа данных на char
    char masc[] = {'a', 'b', 'c'};
    char *ptrc1, *ptrc2;
    ptrc1 = masc;
    ptrc2 = &masc[2];
    cout<<"Example with variables of type char:"<<endl;
    PC(ptrc1);
    ptrc1++;
    PC(ptrc1);
    ++ptrc2;
    printf("ptrc2 - ptrc1 = %u\n", ptrc2 - ptrc1);
}


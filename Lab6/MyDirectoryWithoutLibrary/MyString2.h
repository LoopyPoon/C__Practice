//
// Created by ivanh on 15.02.2024.
//

#ifndef C__PRACTICE_MYSTRING2_H
#define C__PRACTICE_MYSTRING2_H

#include <iostream>

class MyString2 {
private:
    char* str; // переменная для хранения символов строки

public:
    // Конструкторы
    MyString2();
    MyString2(const char* s);
    MyString2(const MyString2& other);
    MyString2(size_t size); // Новый конструктор

    // Деструктор
    ~MyString2();

    // Перегрузка операторов
    MyString2& operator=(const MyString2& other);
    MyString2 operator+(const MyString2& other) const;
    bool operator==(const MyString2& other) const;

    // Методы для определения длины строки
    int length() const;

    // Методы для ввода и вывода строки
    friend std::ostream& operator<<(std::ostream& os, const MyString2& obj);
    friend std::istream& operator>>(std::istream& is, MyString2& obj);

private:
    // Аналогичные функции для работы со строками
    static char* strcpy_custom(char* dest, const char* src);
    static char* strcat_custom(char* dest, const char* src);
    static int strcmp_custom(const char* str1, const char* str2);
    static size_t strlen_custom(const char* str);
};

#endif //C__PRACTICE_MYSTRING2_H

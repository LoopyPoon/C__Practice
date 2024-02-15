//
// Created by ivanh on 15.02.2024.
//

#ifndef C__PRACTICE_MYSTRING_H
#define C__PRACTICE_MYSTRING_H

#include <iostream>

class MyString {
private:
    char* str; // переменная для хранения символов строки

public:
    // Конструкторы
    MyString();
    MyString(const char* s);
    MyString(const MyString& other);

    // Деструктор
    ~MyString();

    // Перегрузка операторов
    MyString& operator=(const MyString& other);
    MyString operator+(const MyString& other) const;
    bool operator==(const MyString& other) const;

    // Методы для определения длины строки
    int length() const;

    // Методы для ввода и вывода строки
    friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
    friend std::istream& operator>>(std::istream& is, MyString& obj);
};

#endif //C__PRACTICE_MYSTRING_H

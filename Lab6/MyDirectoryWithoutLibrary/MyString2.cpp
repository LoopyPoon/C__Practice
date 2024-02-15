//
// Created by ivanh on 15.02.2024.
//

#include "MyString2.h"

// Конструкторы
MyString2::MyString2() : str(nullptr) {}

MyString2::MyString2(const char* s) {
    str = new char[strlen_custom(s) + 1];
    strcpy_custom(str, s);
}

MyString2::MyString2(const MyString2& other) {
    str = new char[strlen_custom(other.str) + 1];
    strcpy_custom(str, other.str);
}

// Новый конструктор
MyString2::MyString2(size_t size) {
    str = new char[size + 1]; // дополнительный байт для завершающего нуля
    str[0] = '\0'; // пустая строка
}

// Деструктор
MyString2::~MyString2() {
    delete[] str;
}

// Перегрузка операторов
MyString2& MyString2::operator=(const MyString2& other) {
    if (this != &other) {
        delete[] str;
        str = new char[strlen_custom(other.str) + 1];
        strcpy_custom(str, other.str);
    }
    return *this;
}

MyString2 MyString2::operator+(const MyString2& other) const {
    MyString2 result;
    result.str = new char[strlen_custom(str) + strlen_custom(other.str) + 1];
    strcpy_custom(result.str, str);
    strcat_custom(result.str, other.str);
    return result;
}

bool MyString2::operator==(const MyString2& other) const {
    return strcmp_custom(str, other.str) == 0;
}

// Метод для определения длины строки
int MyString2::length() const {
    return strlen_custom(str);
}

// Методы для ввода и вывода строки
std::ostream& operator<<(std::ostream& os, const MyString2& obj) {
    return os << obj.str;
}

std::istream& operator>>(std::istream& is, MyString2& obj) {
    char temp[1000]; // предположим, что строка не превышает 1000 символов
    is >> temp;
    delete[] obj.str;
    obj.str = new char[MyString2::strlen_custom(temp) + 1];
    MyString2::strcpy_custom(obj.str, temp);
    return is;
}

// Реализация аналогичных функций для работы со строками
char* MyString2::strcpy_custom(char* dest, const char* src) {
    char* tmp = dest;
    while (*src) {
        *tmp++ = *src++;
    }
    *tmp = '\0';
    return dest;
}

char* MyString2::strcat_custom(char* dest, const char* src) {
    char* tmp = dest;
    while (*tmp) {
        tmp++;
    }
    while (*src) {
        *tmp++ = *src++;
    }
    *tmp = '\0';
    return dest;
}

int MyString2::strcmp_custom(const char* str1, const char* str2) {
    while (*str1 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

size_t MyString2::strlen_custom(const char* str) {
    const char* s = str;
    while (*s) {
        s++;
    }
    return s - str;
}
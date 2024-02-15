//
// Created by ivanh on 15.02.2024.
//

#include "MyString.h"
#include <cstring>

// Конструкторы
MyString::MyString() : str(nullptr) {}

MyString::MyString(const char* s) {
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

MyString::MyString(const MyString& other) {
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}

// Деструктор
MyString::~MyString() {
    delete[] str;
}

// Перегрузка операторов
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] str;
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }
    return *this;
}

MyString MyString::operator+(const MyString& other) const {
    MyString result;
    result.str = new char[strlen(str) + strlen(other.str) + 1];
    strcpy(result.str, str);
    strcat(result.str, other.str);
    return result;
}

bool MyString::operator==(const MyString& other) const {
    return strcmp(str, other.str) == 0;
}

// Метод для определения длины строки
int MyString::length() const {
    return strlen(str);
}

// Методы для ввода и вывода строки
std::ostream& operator<<(std::ostream& os, const MyString& obj) {
    return os << obj.str;
}

std::istream& operator>>(std::istream& is, MyString& obj) {
    char temp[1000]; // предположим, что строка не превышает 1000 символов
    is >> temp;
    delete[] obj.str;
    obj.str = new char[strlen(temp) + 1];
    strcpy(obj.str, temp);
    return is;
}
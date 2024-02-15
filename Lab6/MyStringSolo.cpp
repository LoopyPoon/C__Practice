//
// Created by ivanh on 15.02.2024.
//

#include <iostream>
#include <cstring>
using namespace std;


// Этот код реализует класс MyStringSolo, который позволяет работать со строкой как с обычным типом данных в C++.
// Он включает конструкторы, деструкторы, перегруженные операторы, методы для определения длины строки,
// а также методы для ввода и вывода строки.
class MyStringSolo {
private:
    char* str; // переменная для хранения символов строки

public:
    // Конструкторы
    MyStringSolo() : str(nullptr) {}

    MyStringSolo(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Конструктор копирования
    MyStringSolo(const MyStringSolo& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Деструктор
    ~MyStringSolo() {
        delete[] str;
    }

    // Перегрузка операторов
    MyStringSolo& operator=(const MyStringSolo& other) {
        if (this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    MyStringSolo operator+(const MyStringSolo& other) const {
        MyStringSolo result;
        result.str = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    bool operator==(const MyStringSolo& other) const {
        return strcmp(str, other.str) == 0;
    }

    // Методы для определения длины строки
    int length() const {
        return strlen(str);
    }

    // Методы для ввода и вывода строки
    friend ostream& operator<<(ostream& os, const MyStringSolo& obj) {
        return os << obj.str;
    }

    friend istream& operator>>(istream& is, MyStringSolo& obj) {
        char temp[1000]; // предположим, что строка не превышает 1000 символов
        is >> temp;
        delete[] obj.str;
        obj.str = new char[strlen(temp) + 1];
        strcpy(obj.str, temp);
        return is;
    }
};

int main() {
    MyStringSolo str1("Hello");
    MyStringSolo str2("World");

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;

    MyStringSolo str3 = str1 + str2;
    cout << "str3 (str1 + str2): " << str3 << endl;

    cout << "Length of str3: " << str3.length() << endl;

    if (str1 == str2)
        cout << "str1 and str2 are equal" << endl;
    else
        cout << "str1 and str2 are not equal" << endl;

    return 0;
}
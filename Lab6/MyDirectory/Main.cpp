//
// Created by ivanh on 15.02.2024.
//

#include "MyString.h"
#include <iostream>
#include "MyString.cpp"

int main() {
    MyString str1("Hello");
    MyString str2("World");

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    MyString str3 = str1 + str2;
    std::cout << "str3 (str1 + str2): " << str3 << std::endl;

    std::cout << "Length of str3: " << str3.length() << std::endl;

    if (str1 == str2)
        std::cout << "str1 and str2 are equal" << std::endl;
    else
        std::cout << "str1 and str2 are not equal" << std::endl;

    return 0;
}
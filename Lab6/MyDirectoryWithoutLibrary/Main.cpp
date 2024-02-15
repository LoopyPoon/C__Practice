//
// Created by ivanh on 15.02.2024.
//

#include "MyString2.h"
#include "MyString2.cpp"
#include <iostream>

int main() {
    MyString2 str1("Hello");
    MyString2 str2("World");

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    MyString2 str3 = str1 + str2;
    std::cout << "str3 (str1 + str2): " << str3 << std::endl;

    std::cout << "Length of str3: " << str3.length() << std::endl;

    if (str1 == str2)
        std::cout << "str1 and str2 are equal" << std::endl;
    else
        std::cout << "str1 and str2 are not equal" << std::endl;

    return 0;
}
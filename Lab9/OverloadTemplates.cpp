//
// Created by ivanh on 20.02.2024.
//

#include <iostream>
#include <cstring>

template <class T>
// ¬озвращает больший из двух значений
T getmax(T t1, T t2) {
    return t1 > t2 ? t1 : t2;
}

const char * getmax(const char *s1, const char *s2) {
    return strcmp(s1, s2) > 0 ? s1 : s2;
}

template <class T>
T getmax(T t[], size_t size) {
    T retval = t[0];
    int i;
    for(i = 0; i < size; i++) {
        if (t[i] > retval) {
            retval = t[i];
        }
    }
    return retval;
}

int main() {
    int i1 = 3;
    int i2 = 5;
    int mas[] = {3,9,5,8};
    int intSize = sizeof(mas) / sizeof(mas[0]);
    std::cout << "max int = " << getmax(i1,i2) << std::endl;
    std::cout << "max int = " << getmax(mas,intSize) << std::endl;
    char *s1 = "String 1";
    char *s2 = "String 2";
    std::cout << "max str = " << getmax(s1,s2) << std::endl;
}
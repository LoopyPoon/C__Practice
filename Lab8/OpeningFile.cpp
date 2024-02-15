//
// Created by ivanh on 15.02.2024.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char fname[15], c;
    std::cout << "Enter the input file name:";
    std::cin >> fname;

    // Открытие входного файла
    std::ifstream ifs(fname);

    // Проверям поток
    if (!ifs) {
        std::cout << "Input file " << fname << " not open" << std::endl;
    }

    std::cout << "Enter the output file name:";
    std::cin >> fname;

    // Открытие выходного файла
    std::ofstream ofs(fname);

    // Проверяем поток
    if (!ofs) {
        std::cout << "Output file " << fname << "not open";
    }

    // Пока не произойдет ошибки, делаем:
    while (ifs && ofs) {
        ifs.get(c); // Чтение символов из файла
        // Переводим прочитанный символ в верхний регистр
        c = toupper(c);
        ofs.put(c); // Запись символа в файл
        // Выходной файл является копией входного файла в верхнем регистре
    }
    return 0;
}
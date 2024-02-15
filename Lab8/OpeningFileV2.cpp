//
// Created by ivanh on 15.02.2024.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>

int main() {
    char name[12];
    std::fstream fin; // Неоткрытый объект поток
    std::cout << "Enter file name:";
    std::cin >> name;

    // Открыли входной поток
    fin.open(name, std::ios::in);

    // Проверям состояние потока
    if(fin) {
        std::cout << "File is open " << name << std::endl;
        fin.close(); // Закрываем файл
    } else {
        std::cout << "Output file is not open " << name << std::endl;
    }
    return 0;
}
//
// Created by ivanh on 16.02.2024.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>

const char fname[] = "New File";

int main() {
    // Создаем новый файл, если только он уже не существует
    std::ofstream ofs(fname, std::ios::out);

    // Проверям состояние потока
    if(!ofs) {
        std::cout << "Error! File " << fname << "already exists" << std::endl;
        return 0;
    } else {
        ofs << "Эта строка записывается в новый файл";
        ofs.close(); // Закрываем файл
        std::ofstream fs; // Определяем новый объект
        // Открывает файл и устанавливает на EOF
        fs.open(fname, std::ios::out);
        fs << "Added entry";
        fs.close(); // Закрываем файл
        std::ifstream ifs(fname);
        if(ifs) {
            std::cout << "The old file contains" << std::endl;
            char Line[80];
            ifs.getline(Line, sizeof(Line));
            std::cout << Line;
        } else {
            std::cout << "Error after reopening " << fname << std::endl;
        }
    }
    return 0;
}
//
// Created by ivanh on 15.02.2024.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>

int main() {
    char name[12];
    std::fstream fin; // ���������� ������ �����
    std::cout << "Enter file name:";
    std::cin >> name;

    // ������� ������� �����
    fin.open(name, std::ios::in);

    // �������� ��������� ������
    if(fin) {
        std::cout << "File is open " << name << std::endl;
        fin.close(); // ��������� ����
    } else {
        std::cout << "Output file is not open " << name << std::endl;
    }
    return 0;
}
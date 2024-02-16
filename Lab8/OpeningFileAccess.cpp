//
// Created by ivanh on 16.02.2024.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>

const char fname[] = "New File";

int main() {
    // ������� ����� ����, ���� ������ �� ��� �� ����������
    std::ofstream ofs(fname, std::ios::out);

    // �������� ��������� ������
    if(!ofs) {
        std::cout << "Error! File " << fname << "already exists" << std::endl;
        return 0;
    } else {
        ofs << "��� ������ ������������ � ����� ����";
        ofs.close(); // ��������� ����
        std::ofstream fs; // ���������� ����� ������
        // ��������� ���� � ������������� �� EOF
        fs.open(fname, std::ios::out);
        fs << "Added entry";
        fs.close(); // ��������� ����
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
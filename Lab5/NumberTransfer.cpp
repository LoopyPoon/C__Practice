//
// Created by ivanh on 14.02.2024.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Функция для обработки текстового файла: перенос номеров страниц в последнюю строку страницы
void processFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Cannot open file: " << filename << endl;
        return;
    }

    ofstream outputFile("C:\\Users\\ivanh\\CLionProjects\\C++Practice\\Lab5\\testCopy.txt");
    if (!outputFile) {
        cout << "Cannot open output file" << endl;
        file.close();
        return;
    }

    string line;
    string pageNumber;
    while (getline(file, line)) {
        if (!line.empty()) {
//            if (line[line.length() - 1] == '\f') {
//                pageNumber = line.substr(2, line.length() - 5); // Ищем номер страницы в формате "- XX - " и удаляем знаки переноса
//            }
            outputFile << line << endl;
        }
    }

    outputFile << pageNumber; // Добавляем номер страницы в последнюю строку файла
    cout << "Processed file saved as: " << filename << endl;

    file.close();
    outputFile.close();
}



int main() {
    processFile("C:\\Users\\ivanh\\CLionProjects\\C++Practice\\Lab5\\test.txt");
    return 0;
}
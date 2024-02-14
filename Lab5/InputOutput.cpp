//
// Created by ivanh on 14.02.2024.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

// Функция для подсчета "пустых" и "непустых" символов в текстовом файле
void countCharacters(char *filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Cannot open file: " << filename << endl;
        return;
    }

    int emptyCount = 0;
    int nonEmptyCount = 0;
    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            emptyCount++;
        } else {
            nonEmptyCount++;
        }
    }

    cout << "Empty lines count: " << emptyCount << endl;
    cout << "Non-empty lines count: " << nonEmptyCount << endl;

    file.close();
}

// Функция для поиска искомой подстроки в текстовом файле и сохранения результатов в отдельном файле
void findSubstring(string& filename, string& searchString, string& outputFilename) {
    ifstream file(filename);
    if (!file) {
        cout << "Cannot open file: " << filename << endl;
        return;
    }

    ofstream outputFile(outputFilename);
    if (!outputFile) {
        cout << "Cannot open output file: " << outputFilename << endl;
        file.close();
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.find(searchString) != string::npos) {
            outputFile << line << endl;
        }
    }

    cout << "Search results saved to: " << outputFilename << endl;

    file.close();
    outputFile.close();
}

int main() {
    char ch, name[50];
    FILE *in;
    // Программа просит пользователя ввести имя файла, который нужно просмотреть, с помощью функции printf.
    printf("Enter file name to view: ");
    // Затем она считывает введенное имя с помощью функции scanf и сохраняет его в переменной name.
    scanf("%s", name);
    // Далее программа пытается открыть указанный файл в режиме чтения с помощью функции fopen.
    // Если файл не удалось открыть (например, из-за того, что его не существует или нет доступа к нему),
    // программа выводит сообщение "File %s is not open", где %s заменяется на введенное имя файла.
    if ((in = fopen(name, "r")) == NULL) {
        printf("File %s is not open", name);
    } else {
        // Если файл успешно открыт, программа начинает читать из него символы с помощью функции getc в цикле while.
        // Каждый считанный символ затем выводится на экран с помощью функции putchar.
        // Цикл продолжается, пока программа не достигнет конца файла (с помощью функции feof),
        // после чего выполнение программы завершается.
        while (!feof(in)) {
            ch = getc(in);
            putchar(ch);
        }
    }
    countCharacters(name);
    findSubstring(name, "test", test2.txt)
}
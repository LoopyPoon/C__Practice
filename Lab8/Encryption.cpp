//
// Created by ivanh on 15.02.2024.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encryptFile(const string& inputFile, const string& outputFile, const string& key) {

    // Передаем в поток два файла для чтения и записи
    ifstream fin(inputFile);
    ofstream fout(outputFile);

    // Проверка, что файл для чтения открыт
    if (!fin.is_open()) {
        cerr << "Error: Unable to open input file: " << inputFile << endl;
        return;
    }

    // Проверка, что файл для записи открыт
    if (!fout.is_open()) {
        cerr << "Error: Unable to open output file: " << outputFile << endl;
        return;
    }

    int keyLength = key.length();
    int keyIndex = 0;
    char c;

    while (fin.get(c)) {
        c = c ^ key[keyIndex]; // Выполняем заданный алгоритм шифрования
        fout << c;

        keyIndex = (keyIndex + 1) % keyLength;
    }

    fin.close();
    fout.close();
}

int main() {

    // Объявляем пути к файлам
    string inputFile = "C:\\Users\\ivanh\\CLionProjects\\C++Practice\\Lab5\\testEncrypt.txt";
    string outputFile = "C:\\Users\\ivanh\\CLionProjects\\C++Practice\\Lab5\\testEncrypt2.txt";
    string key = "key";

    // Вызываем функцию
    encryptFile(inputFile, outputFile, key);

    cout << "Encryption and decryption completed successfully." << endl;

    return 0;
}
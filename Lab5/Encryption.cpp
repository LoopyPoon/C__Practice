//
// Created by ivanh on 15.02.2024.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encryptFile(const string& inputFile, const string& outputFile, const string& key) {
    ifstream fin(inputFile);
    ofstream fout(outputFile);

    if (!fin.is_open()) {
        cerr << "Error: Unable to open input file: " << inputFile << endl;
        return;
    }

    if (!fout.is_open()) {
        cerr << "Error: Unable to open output file: " << outputFile << endl;
        return;
    }

    int keyLength = key.length();
    int keyIndex = 0;
    char c;

    while (fin.get(c)) {
        c = c ^ key[keyIndex]; // Perform XOR encryption
        fout << c;

        // Move to the next character in the key, or cycle back to the beginning if necessary
        keyIndex = (keyIndex + 1) % keyLength;
    }

    fin.close();
    fout.close();
}

int main() {

    string inputFile = "C:\\Users\\ivanh\\CLionProjects\\C++Practice\\Lab5\\testEncrypt.txt";
    string outputFile = "C:\\Users\\ivanh\\CLionProjects\\C++Practice\\Lab5\\testEncrypt2.txt";
    string key = "key";

    // Encrypt the input file
    encryptFile(inputFile, outputFile, key);

    cout << "Encryption and decryption completed successfully." << endl;

    return 0;
}
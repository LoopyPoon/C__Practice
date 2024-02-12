//
// Created by ivanh on 13.02.2024.
//

#include <iostream>
using namespace std;

int dlina(char str[]) {
    int amountOfSymbol = 0; // счетчик символов
    while (str[amountOfSymbol] != '\0')
    {
        amountOfSymbol++;
    }

    return amountOfSymbol;
}

void copyStr(char str1[], char str2[])
{
    int count = 0;
    while (true) // запускаем бесконечный цикл
    {
        str1[count] = str2[count]; // копируем посимвольно

        if (str2[count] == '\0') // если нашли \0 у второй строки
        {
            break; // прерываем цикл
        }

        count++;
    }
}

void compareStr(char str1[], char str2[])
{
    int compare = 0; // для сравнения длины строк

    int count = 0;
    while (true)
    {
        if (dlina(str1) < dlina(str2))
        {
            cout << "Strings are NOT equal: " << --compare << endl;
            break;
        }
        else if (dlina(str1) > dlina(str2))
        {
            cout << "Strings are NOT equal: " << ++compare << endl;
            break;
        }
        else // если по количеству символов строки равны
        {
            if (str1[count] == str2[count]) // сравниваем посимвольно включая \0
            {
                count++;
                if (str1[count] == '\0' && str2[count] == '\0')
                {
                    cout << "Strings are equal: " << compare << endl;
                    break;
                }
            }
            else // если все же где-то встретится отличный символ
            {
                cout << "Strings are NOT equal: " << --compare << endl;
                break;
            }
        }
    }
}

void concat(char str1[], char str2[])
{
    int count1 = 0; // для индекса ячейки где хранится '\0' первой строки
    while (str1[count1] != 0)
    {
        count1++; // ищем конец первой строки
    }

    int count2 = 0; // для прохода по символам второй строки начиная с 0-й ячейки
    while (str2[count2] != 0)
    { // дописываем вконец первой строки символы второй строки
        str1[count1] = str2[count2];
        count1++;
        count2++;
    }
}

int main() {
    char str1[] = "qwerty";
    char str2[] = "1234567890";

    // Использование функций длины строки
    cout << "Length str1 = " << dlina(str1) << endl;
    cout << "Length str2 = " << dlina(str2) << endl;

    // Использование функции копирования строки
    copyStr(str1, str2);
    cout << "Copy str1 = " << str1 << endl;
    cout << "Copy str2 = " << str2 << endl;

    // Использование функции сравнения строк
    compareStr(str1, str2);

    // Использование функции конкатенирования строк
    concat(str1, str2);
    cout << "Concat str1 = " << str1 << endl;
    cout << "Concat str2 = " << str2 << endl;

}
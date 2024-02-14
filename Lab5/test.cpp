//
// Created by ivanh on 15.02.2024.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void reorder(char* str1,char* str2)
{
    int j=0;
    for(int i=0;str1[i];i++)
        if( str1[i]<'0' || str1[i]>'9') // если не цифра
            str2[j++]=str1[i];
    for(int i=0;str1[i];i++)
        if( str1[i]>='0' && str1[i]<='9') // если цифра
            str2[j++]=str1[i];
    str2[j]=0; // терминальный ноль
}
int main()
{
    char x1[100],x2[100];
    ifstream f1("C:\\Users\\ivanh\\CLionProjects\\C++Practice\\Lab5\\test.txt");
    ofstream f2("C:\\Users\\ivanh\\CLionProjects\\C++Practice\\Lab5\\testCopy.txt");
    while(f1.getline(x1,100))
    {
        reorder(x1,x2);
        f2<<x2<<endl;
    }
    f2.close();
}
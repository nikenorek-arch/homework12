#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    string text;

    fstream file("Files/in1.txt", ios::in);
    if (file.is_open()){
        while(file >> text) cout << text << endl;
    }
    else{
        cout << "Файл Files/in1.txt не найден!";
    }
}
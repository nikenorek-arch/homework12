#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
using namespace std;


void reverse(int* arr, int size){
    for (int i = 0; i < size/2; i++){
        swap(arr[i], arr[size-(i+1)]);
    }
}


void writeArr(int* myArr, int size){
    fstream file("Files/out.txt", ios::out);
    if (file.is_open()){
        file << size << "\n";
        for (int i = 0; i < size; i++) file << myArr[i] << " ";

        cout << "Массив успешно записан в файл Files/out.txt!";
        file.close();
    }
    else{
        cout << "Файл Files/out.txt не найден!";
    }
}


int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int size = 0;
    int* myArr = nullptr;

    cout << "Введите размер массива: ";
    cin >> size;

    if (size > 0){
        
        myArr = new int[size];

        for (int i = 0; i < size; i++){
            cout << "arr [" << i << "] = ";
            cin >> myArr[i];
        }


        reverse(myArr,size);
        writeArr(myArr,size);

        delete[] myArr;
    }
    else{
        cout << "Неверный размер массива";
    }


}
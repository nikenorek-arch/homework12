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

void print(int* arr, int size)
{
    for (int i = 0; i < size; i++)std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    fstream file("Files/in2.txt", ios::in);
    if (file.is_open()){

        int size = 0;
        int* myArr = nullptr;
        
        if (file >> size){

            if (size <= 0) {
                 cout << "Неверный размер массива!";
                 return 0;
            }

            myArr = new int[size];
            for (int i = 0; i < size; i++) file >> myArr[i];

            reverse(myArr, size);
            print(myArr, size);
            delete[] myArr;

        }
    }
    else{
        cout << "Файл Files/in2.txt не найден!";
    }
}
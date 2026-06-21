#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
using namespace std;

int** create_two_dim_array(int row, int col){
    int** arr = new int *[row];
    for (int i = 0; i < row; i++){
        arr[i] = new int [col];
    }
    return arr;
}

void print_two_dim_array(int** arr, int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void reverse_two_dim_array(int** arr, int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col/2; j++){
            swap(arr[i][j], arr[i][col-(j+1)]);
        }
    }
}


void delete_two_dim_array(int** arr, int row, int col){
    for (int i = 0; i < row; i++) delete[] arr[i];
    delete[] arr;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    fstream file("Files/in3.txt", ios::in);
    if (file.is_open()){

        int i = 0, row = 0, col = 0;
        int** myArr;
        
        while(!file.eof()){

            if (i == 0){
                file >> row;
            }         
            else if (i == 1){
                file >> col;
                myArr = create_two_dim_array(row, col);
            }    
            else{
                int j = i-2;
                file >> myArr[j/col][j%col];
            }
            i++;
        }
        reverse_two_dim_array(myArr, row, col);
        print_two_dim_array(myArr, row, col);
        delete_two_dim_array(myArr, row, col);

    }
    else{
        cout << "Файл Files/in3.txt не найден!";
    }
}
/*Stwórz prostą strukturę do obsługi macierzy. Zdefiniuj funkcje write_mat() i read_mat() do zapisu/odczytu macierzy do/z pliku tekstowego (formatowanego).
Plik tekstowy ma być sformatowany w ten sposób, że w pierwszym wierszu są dwie liczby całkowite:
szerokość i wysokość macierzy a w następnych liniach są zapisane kolejno elementy macierzy rozdzielone spacją w postaci liczb zmiennoprzecinkowych.

Przykładowy plik wejściowy:
5 3
1.0 2.0 3.0 4.0 5.0
6.0 7.0 8.0 9.0 0.0
3.0 5.0 7.0 9.0 1.0*/
#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

struct Matrix{
    int columns;
    int rows;
    float* data;
};

void writeMat(Matrix matrix){
    ofstream File("test.txt");
    if(File.is_open()){
        File << matrix.columns << " " << matrix.rows << endl;
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.columns; ++j) {
                File << matrix.data[i * matrix.columns + j] << " ";
            }
            File << endl;
        }
        File.close();
    }
    else{
        cout<<"Nie można zapisac pliku!"<<endl;
    }

}

void readMat(Matrix matrix){
    ifstream File("test.txt");
    if(File.is_open()){
        File >> matrix.columns >> matrix.rows;
        //matrix.data=new float[matrix.columns*matrix.rows];
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.columns; ++j) {
                File >> matrix.data[i * matrix.columns +j];
            }
        }
        File.close();
    }
    else{
        cout<<"Nie można zapisac!"<<endl;
    }
}

int main()
{
    Matrix m1;
    m1.columns=5;
    m1.rows=3;
    m1.data=new float[15]{1.0,2.0,3.0,4.0,5.0, 6.0,7.0,8.0,9.0,0.0, 3.0,5.0,7.0,9.0,1.0};
    writeMat(m1);
    Matrix m2;
    m2.columns=5;
    m2.rows=3;
    m2.data=new float[15];
    readMat(m2);
    for (int i = 0; i < m2.rows; ++i) {
        for (int j = 0; j < m2.columns; ++j) {
                printf("%.1f\t", m2.data[i * m2.columns + j]);
        }
        cout << endl;
    }
    return 0;
}

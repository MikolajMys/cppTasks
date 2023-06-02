/*Napisz program, który obliczy i wyświetli długości dwuwymiarowych
wektorów zapisanych w jednowymiarowej tablicy liczb zmiennoprzecinkowych.
Tablica z wektorami wejściowymi ma być skonstruowana w ten sposób,
że kolejne współrzędne (x, y) każdego wektora zajmują kolejne elementy tablicy, czyli:  [x1,y1, x2,y2, x3,y3, …, xn,yn].

Zdefiniuj funkcję arr_fun, która w parametrach przyjmie:
(1) wskaźnik na początek tablicy wektorów,
(2) wskaźnik na za-ostatni element tej tablicy,
(3) wskaźnik na początek tablicy wynikowej z obliczonymi długościami oraz
(4) wskaźnik na funkcję pomocniczą, która zwraca wartość zmiennoprzecinkową a w parametrach bierze dwie wartości zmiennoprzecinkowe.
Zdefiniuj funkcję pomocniczą, która zwróci długość wektora przy podaniu przez parametry jego dwóch współrzędnych.
W funkcji głównej stwórz przykładową dynamiczną tablicę wektorów, wyznacz za pomocą stworzonej funkcji arr_fun ich długości
i wyświetl powstałą w ten sposób tablicę wynikową. W zadaniu nie można używać funkcji z biblioteki <algorithm>.
Przykład:
IN:     [1.0,1.0  2.0,1.0  1.0,3.0  3.0,1.0]
OUT:    [1.414214 2.236068 3.162278 3.162278]*/

#include <iostream>
#include <cmath>
using namespace std;

void arr_fun(float *ptr_first, float *ptr_last, float *arr_result, float(*fun_length)(float, float)){
    for(int i=0; i<4; ++i){
        *(arr_result+i)=fun_length(*(ptr_first+i*2), *(ptr_first+i*2+1));
    }
}

float fun_length(float x, float y){
    return sqrt(x*x+y*y);
}

int main(){
    const int size=8;
    float* arr_vec=new float[size]{1.0,1.0,   2.0,1.0,    1.0,3.0,    3.0,1.0};
    float* arr_result=new float[size/2];
    arr_fun(arr_vec, arr_vec+size-1, arr_result, fun_length);
    for(int i=0; i<size/2; ++i){
        cout.precision(7);
        cout<<*(arr_result+i)<<"\t";
    }
    delete[] arr_vec;
    delete[] arr_result;
    return 0;
}

/*Dane są dwie tablice liczb zmiennoprzecinkowych o długościach: (1) 3*N oraz (2) N, gdzie N jest liczbą naturalną.
Zdefiniuj funkcję fun_arr, która w parametrze przyjmie dwie tablice (o podanej wyżej specyfikacji)
oraz wskaźnik na pewną dodatkową funkcję fun_aux.
Funkcja fun_arr z każdych trzech sąsiadujących elementów (o indeksach {3i, 3i+1, 3i+2}) z pierwszej tablicy ma obliczyć,
za pomocą fun_aux, pojedynczą wartość i wstawić ją do drugiej tablicy w element o indeksie i.
Funkcja pomocnicza fun_aux, dla trzech podanych liczb, ma zwracać wartość największą.
W funkcji głównej stwórz przykładowe dynamiczne tablice (1) i (2) spełniające warunki z początku zadania i
wykorzystując funkcje fun_arr i fun_aux, uzupełnij tablicę wyjściową (2).
Wypisz na ekranie jej wartości. Zadbaj o właściwe zarządzanie pamięcią dynamiczną.
Przykład:
IN:     [1.0,1.0,2.5,   2.0,1.0,-0.5,   -1.5,-3.0,-4.0,   0.0,0.0,0.0]
OUT:    [2.5            2.0             -1.5              0.0]*/
#include <iostream>
#include <algorithm>
using namespace std;

void fun_arr(float *arr1, float *arr2, float(*fun_aux_ptr)(float*), int N)
{
    for(int i=0; i<N; ++i)
    {
        float arr3[3];
        for(int j=0; j<N-1; ++j)
        {
            arr3[j] = *(arr1+i*3+j);
        }
        *(arr2+i) = fun_aux_ptr(arr3);
    }
}

float fun_aux(float arr3[])
{
    return *max_element(arr3, arr3+3);
}

int main()
{
    const int N = 4;
    float* arr1 = new float[3*N]{1.0,1.0,2.5,   2.0,1.0,-0.5,   -1.5,-3.0,-4.0,   0.0,0.0,0.0};
    float* arr2 = new float[N];
//    for(int i=0; i<3 * N; ++i)
//        {
//            cin >> arr1[i];
//        }
    fun_arr(arr1, arr2, fun_aux, N);
    for(int i=0; i<N; ++i)
    {
        cout<<arr2[i]<<"\t";
    }

    delete[] arr1;
    delete[] arr2;
    return 0;
}

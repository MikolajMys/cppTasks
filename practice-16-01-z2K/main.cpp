/*Napisz program w języku C++, który stworzy dynamiczną tablicę dwuwymiarową trójkątną arr
o rozmiarze NxN wybranego typu liczbowego i wypełni ją dowolnymi wartościami.
Zdefiniuj funkcję, która w parametrze przyjmie wskaźnik na wskaźnik na typ void (do tablicy trójkątnej arr),
rozmiar N, wielkość w bajtach pojedynczego elementu sizen tablicy przekazanej w pierwszym parametrze oraz
dwie współrzędne x, y typu całkowitego. Funkcja ma zwrócić wskaźnik typu void
ustawiony na podany we współrzędnych x, y element tablicy lub nullptr jeżeli nie ma takiego elementu.
Pokaż użycie tej funkcji i wykonaj dealokację tablicy arr.
Przykład:
 0  1  2  3  4
 5  6  7  8
 9  10 11
 12 13
 14
OUT: 7 (dla x=2, y=1)*/

#include <iostream>
using namespace std;

void* get_element(void** arr,int n, int sizen, int x, int y)
{
    if (x < 0 or y < 0 or y > n - 1){
        return nullptr;
    }
    if (x > n - y - 1) {
        return nullptr;
    }

    int **pom = (int **) arr;
    return (void*) &pom[y][x];
}

int main()
{
    // inicjalizacja tablicy wielowymiarowej NxN
    int n=5, index=0, x=-1, y=1;
    int** arr=new int*[n];
    for(int i=0; i<n; ++i)
    {
        *(arr+i)=new int[n - i];
        for(int j=0; j<n - i; ++j)
        {
            arr[i][j]=index++;
        }
    }

    // wyświetlenie tablicy
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n -i; ++j)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }

    // wywołanie funkcji get_element
    int* pom=(int*)get_element((void**)arr, n, sizeof(int), x, y);
    if (pom != nullptr) {
            cout << *pom << endl;
        } else {
            cout << "nullptr" << endl;
        }

    for(int i=0; i<n; ++i)
        delete[] arr[i];
    delete[] arr;
    return 0;
}

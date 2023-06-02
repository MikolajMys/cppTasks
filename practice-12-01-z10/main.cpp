/*Dynamiczna alokacja pamięci - Zadanie 10.
Napisz program, który wczytuje od użytkownika trzy liczby całkowite n, m, o,
a następnie dynamicznie alokuje pamięć dla n-elementowej,
m-elementowej i o-elementowej tablicy liczb całkowitych.
W kolejnym kroku program powinien uzupełnić tablice losowymi wartościami
z przedziału <0;5> i je posortować.
Na koniec z tak posotowanych tablic algorytm powinien
wypisać elementy powtarzające się we wszystkich tablicach.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void sort_print(int arr[], int size)
{
    cout<<endl;
    sort(arr, arr+size);
    for(int i=0; i<size; ++i)
    {
        cout<<arr[i]<<"\t";
    }
}


int main()
{
    int n,m,o;
    cin>>n>>m>>o;
    int* arr1 = new int[n];
    int* arr2 = new int[m];
    int* arr3 = new int[o];
    srand(time(NULL));
    cout<<"Nieposortowane:"<<endl;
    for(int i=0; i<n; ++i)
    {
        *(arr1+i)=rand()%6;
        cout<<*(arr1+i)<<"\t";
    }
    cout<<endl;
    for(int i=0; i<m; ++i)
    {
        *(arr2+i)=rand()%6;
        cout<<*(arr2+i)<<"\t";
    }
    cout<<endl;
    for(int i=0; i<o; ++i)
    {
        *(arr3+i)=rand()%6;
        cout<<*(arr3+i)<<"\t";
    }
    cout<<endl<<"Posortowane:";
    sort_print(arr1, n);
    sort_print(arr2, m);
    sort_print(arr3, o);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}

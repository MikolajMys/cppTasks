/*Napisz funkcję, która przyjmuje w argumentach: wskaźnik arr na tablicę liczb całkowitych,
rozmiar tej tablicy n, liczbę całkowitą k oraz wskaźnik na tablicę liczb całkowitych result.
Funkcja powinna wprowadzić do tablicy result k największych elementów z tablicy arr przekazanej w argumencie.
Funkcja nie powinna modyfikować oryginalnej tablicy.*/
#include <iostream>
#include <algorithm>
using namespace std;

void func(int* arr, const int n, const int k, int* result)
{
    int arr2[n];
    copy(arr, arr+n, arr2);
    sort(arr2, arr2+n, greater<int>());
    copy_n(arr2, k, result);
}

int main()
{
    const int n=6,k=2;
    int arr[n]={4,2,6,1,5,3};
    int result[k];
    func(arr, n, k, result);
    for(int i=0; i<=k-1; ++i)
        cout<<result[i]<<"\t";
    return 0;
}

/*Dynamiczna alokacja pamięci - Zadanie 9.
Napisz program, który wczytuje od użytkownika dwie liczby całkowite n i m,
a następnie dynamicznie alokuje pamięć dla n-elementowej tablicy liczb całkowitych.
W kolejnym kroku program powinien uzupełnić tablicę losowymi wartościami z przedziału <-50;50> i je posortować.
Na koniec program powinien znaleźć wszystkie pary liczb całkowitych,
których suma jest równa liczbie m, wyświetlić je i podać ich ilość.*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int n, m, sum=0;
    cin>>n>>m;
    int* arr=new int[n];
    for(int i=0; i<n; ++i)
    {
        *(arr+i)=rand()%101-50;
        cout<<*(arr+i)<<"\t";
    }
    sort(arr, arr+n);
    cout<<endl;
    for(int i=0; i<n; ++i)
    {
        cout<<*(arr+i)<<"\t";
    }
    cout<<endl;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(arr[i]+arr[j]==m)
            {
                cout<<arr[i]<<"+"<<arr[j]<<endl;
                sum++;
            }
        }
    }
    cout<<"suma:"<<sum;
    delete[] arr;
    return 0;
}

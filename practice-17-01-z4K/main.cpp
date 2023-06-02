/*Zadanie 4.
(1)Napisz program, który przyjmie od użytkownika liczbę całkowitą n.
(2)Utwórz dynamiczną tablicę liczb całkowitych arr i wypełnij ją wartościami od użytkownika większymi od 0.
Liczby te reprezentują liczbę elementów dla kolejnych wierszy nieregularnej tablicy dwuwymiarowej arr2d.
(3)Następnie utwórz dynamiczną n-elementową tablicę wskaźników na tablice liczb zmiennoprzecinkowych arr2d.
Każdemu wskaźnikowi zarezerwuj pamięć zgodnie z korespondującą indeksowo wartością tablicy arr.
Wypełnij wszystkie tablice liczbami zmiennoprzecinkowymi pobranymi od użytkownika.
(4)Utwórz dynamiczną n-elementową tablicę liczb zmiennoprzecinkowych result,
której elementami są sumy elementów poszczególnych wierszy tablicy arr2d, a następnie wyświetl jej zawartość.
Przykład:
IN:
    n:       4
    arr:     [3 5 4 1]
    arr2d:   [1.3 2.5 7.1]
             [1.1 3.4 2.2 4.7 1.9]
             [0.4 2.1 7.1 3.9]
             [3.5]
OUT:
    result:  [10.9 13.3 13.5 3.5]*/

#include <iostream>
using namespace std;

int main()
{
    int num;
    cin>>num;
    int* arr=new int[num];
    for(int i=0; i<num; ++i){
        cin>>*(arr+i);
    }
    float** arr2d=new float*[num];
    for(int i=0; i<num; ++i){
        *(arr2d+i)=new float[arr[i]];
        for(int j=0; j<arr[i]; ++j){
            cin>>arr2d[i][j];
        }
        cout<<endl;
    }
    for(int i=0; i<num; ++i){
        for(int j=0; j<arr[i]; ++j){
            cout<<arr2d[i][j]<<"\t";
        }
        cout<<endl;
    }
    float* result=new float[num];
    for(int i=0; i<num; ++i){
        *(result+i)=0;
        for(int j=0; j<arr[i]; ++j){
        *(result+i)+=arr2d[i][j];
        }
    }
    for(int i=0; i<num; ++i){
        cout.precision(3);
        cout<<*(result+i)<<"\t";
    }
    delete[] result;
    for(int i=0; i<num; ++i){
        delete[] arr2d[i];
    }
    delete[] arr2d;
    delete[] arr;
    return 0;
}

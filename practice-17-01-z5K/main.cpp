/*(1)Napisz program, który przyjmuje od użytkownika dwie liczby całkowite n i m.
(2)Utwórz dynamiczną tablicę dwuwymiarową liczb całkowitych nieujemnych arr2d o rozmiarze nx2m
i wypełnij ją losowymi wartościami z przedziału <0,10).
(3)Następnie utwórz drugą dynamiczną tablicę dwuwymiarową liczb zmiennoprzecinkowych arr2d_2 o n wierszach.
Korzystając z kolejnych elementów tablicy arr2d wypełnij kolejne wiersze tablicy arr2d_2 w następujący sposób:
kolejne dwa elementy z każdego wiersza scal w liczbę zmiennoprzecinkową,
w której mniejsza z tych dwóch liczb będzie częścią całkowitą, a większa - częścią ułamkową.
Następnie wyświetl zawartość tablicy arr2d_2.
Przykład:
IN:
    n: 3
    m: 4
    arr2d:  [3 5 2 3 5 0 3 3]
            [0 4 1 2 0 1 9 1]
            [3 1 6 0 1 2 2 9]
OUT:
    arr2d_2:      [3.5 2.3 0.5 3.3]
                  [0.4 1.2 0.1 1.9]
                  [3.1 0.6 1.2 2.9]*/

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    srand(time(NULL));
    //pierwsza dynamiczną tablicę dwuwymiarową arr2d i wypełnienie <0,10)
    int** arr2d=new int*[n];
    for(int i=0; i<n; ++i){
        *(arr2d+i)=new int[2*m];
        for(int j=0; j<2*m; ++j){
            *(*(arr2d+i)+j)=rand()%10;
        }
    }
    //print arr2d
    for(int i=0; i<n; ++i){
        for(int j=0; j<2*m; ++j){
            cout<<arr2d[i][j]<<"\t";
        }
        cout<<endl;
    }
    //druga dynamiczna tablica dwuwymiarowa arr2d_2
    float** arr2d_2=new float*[n];
    for(int i=0; i<n; ++i){
        *(arr2d_2+i)=new float[m];
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(arr2d[i][j*2]<arr2d[i][j*2+1])
                arr2d_2[i][j]=(float)(arr2d[i][j*2]+((float)(arr2d[i][j*2+1])/10));
            else
                arr2d_2[i][j]=(float)((float)(arr2d[i][j*2])/10+arr2d[i][j*2+1]);        }
    }
    //print arr2d_2
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cout<<(float)arr2d_2[i][j]<<"\t";
        }
        cout<<endl;
    }
    //usuwanko
    for(int i=0; i<n; ++i){
        delete[] arr2d_2[i];
    }
    delete[] arr2d_2;
    for(int i=0; i<n; ++i){
        delete[] arr2d[i];
    }
    delete[] arr2d;
    return 0;
}

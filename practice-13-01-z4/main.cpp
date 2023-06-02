/*Tablice dynamiczne wielowymiarowe, zarządzanie pamięcią i projektem - Zadanie 4.
Napisz funkcję, która wykona transpozycję macierzy przekazanej w parametrze.
Macierz ma być reprezentowana za pomocą dynamicznie alokowanej tablicy dwuwymiarowej.
Jaką sygnaturę zaproponujesz dla implementowanej funkcji?
*/
#include <iostream>
using namespace std;

void transposition(int** mat)
{
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            cout<<mat[j][i];
            //mat[i][j]=mat[j][i];???
            //cout<<mat[i][j];???
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    int** mat;
    mat=new int*[3];
    for(int i=0; i<3; ++i)
    {
        mat[i]=new int[3];
        for(int j=0; j<3; ++j)
        {
            cin>>n;
            mat[i][j]=n;
        }
    }
    transposition(mat);
    for(int i=0; i<3; i++)
        delete[] mat[i];
    delete[] mat;

    return 0;
}

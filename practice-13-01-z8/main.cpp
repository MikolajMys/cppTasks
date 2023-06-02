/*Tablice dynamiczne wielowymiarowe, zarządzanie pamięcią i projektem - Zadanie 8.
Napisz funkcję, która przyjmie jako argumenty dwa napisy - przeszukiwany i poszukiwany.
Jeżeli w napisie przeszukiwanym znajduje się napis będący zgodny z napisem poszukiwanym,
funkcja powinna zwrócić wskaźnik na indeks pierwszego znaku odnalezionego podnapisu.
W przeciwnym razie funkcja powinna zwrócić NULL.*/
#include <iostream>
using namespace std;

bool compare(char sign1[], char sign2[]){
    for (int i = 0; i < 4; ++i)
        if (sign1[i]!=sign2[i])
            return false;
    return true;
}

void func(char sign1[], char sign2[])
{
    char* ptr=sign1;
    if(compare(sign1, sign2))
        cout<<*ptr<<endl;
    else
        cout<<NULL<<endl;
}

int main()
{
    char sign1[]="dupa";
    char sign2[]="dupa";
    func(sign1, sign2);

    return 0;
}

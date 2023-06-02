/*(1)Napisz funkcję, która przyjmuje dwie równoliczne dynamiczne tablice wskaźników na napisy (c-string).
W pierwszej tablicy, w każdym napisie zapisana jest tablica rejestracyjna, która została przechwycona przez fotoradar.
Zakładamy że każda tablica rejestracyjna rozpoczyna się od dwóch lub trzech liter wskazujących miejscowość rejestracji,
a następnie biały znak oraz ciąg cyfr (długość ciągu to 4 lub 5 cyfr). 3+space+5
Należy pomóc jednostce policji w pogrupowaniu rejestracji według miejscowości,
aby odpowiednio rozesłać poszczególnym jednostkom numery rejestracji wskazane do wystawienia mandatu.
Funkcja powinna zapisać do drugiej tablicy napisy, które są połączeniem tablic rejestracyjnych dla konkretnego województwa (zobacz przykład).
Funkcja ma zwrócić liczbę napisów w wyjściowej tablicy. Kolejność województw i rejestracji pojazdów w tablicy wynikowej nie ma znaczenia.
Napisz program testujący zaimplementowaną funkcję.
IN:
[
LRY 1234
LU 87654
WA 1234
LRY 888
LU 999
]
OUT:
[
“LRY 1234 888”,
“LU 87654 999”,
“WA 1234”
]*/
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

bool compare(char a, char b){
    return a==b;
}

int main()
{
    int n = 5;

    char** reg = new char*[n]{
        new char[10]{"LRY 1234"},
        new char[10]{"LU 87654"},
        new char[10]{"WA 1234"},
        new char[10]{"LRY 888"},
        new char[10]{"LU 999"}
    };
    char* plate1=strtok(*reg, " ");
    char* plate2=strtok(*(reg+1), " ");
    cout<<plate2;

    char a = 'a';
    char b = 'b';

    bool result = compare(a, b);

    if(result){
        cout<<"tak";
    }
    else {
        cout<<"nie";
    }






//    for(int i=0; i<n; ++i){
//        cout<<*(reg+i)<<endl;
//    }

    return 0;
}

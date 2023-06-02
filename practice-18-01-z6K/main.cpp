/*Ranking gry NewCSShooter przechowywany jest  na serwerze w następujący sposób:
MystiqueHero;1365;6890;15210
Frizz;5400;6200;11000
Każdy wiersz reprezentuje statystyki rozegranych meczy dla danego użytkownika.
Pojedynczy wiersz zawiera następujące informacje oddzielone od siebie średnikiem:
nazwa użytkownika, ilość wygranych meczy, ilość rozegranych meczy, ilość dokonanych likwidacji.
Przykład:
MystiqueHero;1365;6890;15210,
można zinterpretować, że gracz MystiqueHero wygrał 1365 meczy na 6890 wszystkich rozegranych meczy i dokonał 15210 likwidacji.
(1)Zbuduj ranking graczy obliczając ich wynik rankingowy. (2)Napisz funkcję, która przyjmuje dynamiczną tablicę napisów (c-string),
w której w każdym elemencie przechowywany jest zapis statystyki danego gracza oraz
(3)drugą taką tablicę  wyjściową na wyniki. Funkcja powinna w drugą tablicę wyjściową wpisać informacje o graczu oraz
jego wynik liczony w następujący sposób: wygrane mecze  + wszystkie mecze + ilość likwidacji.
Możesz założyć że nazwa użytkownika to nie więcej niż 12 znaków oraz całkowity wynik to liczba całkowita złożona z maksymalnie 10 cyfr.
Napisz program testujący zaimplementowaną funkcję.
IN:
[
MystiqueHero;1365;6890;15210
Frizz;5400;6200;11000
Ziemniak;9965;11000;73000
Evel00na;10;10;90
]
OUT:
[
“MystiqueHero 23465”, //(bo 1365 + 6890 + 15210 = 23465)
“Frizz 22600”,
“Ziemniak 93965”,
“Evel00na 110”,
]*/
Zadania do drugiego kolokwium
Zadanie 5.

#include <iostream>
#include <cstdio>
#include <cstring>//strcpy strcpr strlen strtok(start,";") strtok(NULL,"?")
using namespace std;

void add_data(char** ranking, char** result, int n){
    for(int i=0; i<n; ++i){
        char* nick=strtok(ranking[i],";");
        char* wins=strtok(NULL,";");
        char* played=strtok(NULL,";");
        char* kills=strtok(NULL,";");

        int Iwins=atoi(wins);
        int Iplayed=atoi(played);
        int Ikills=atoi(kills);
        int sum=(Iwins+Iplayed+Ikills);
        char* data=new char[n*23];
        sprintf(data,"%s %d",nick, sum);
        *(result+i)=data;
    }
}

int main()
{
    int n;
    cin>>n;
    char** ranking=new char*[n];
    for(int i=0; i<n; ++i){
        char* data=new char[n*23];
        cin>>data;
        *(ranking+i)=data;
    }
    char** result=new char*[n];
    add_data(ranking, result, n);
    for(int i=0; i<n; ++i){
        cout<<result[i]<<endl;
    }
    for(int i = 0; i < n; ++i) {
        delete[] ranking[i];
        delete[] result[i];
    }
    delete[] ranking;
    delete[] result;
    return 0;
}

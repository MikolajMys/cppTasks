/*Stwórz funkcję, która przyjmuje ścieżkę do pliku tekstowego.
W pliku tekstowym znajdują się posortowane rosnąco liczby całkowite oddzielone pojedynczymi spacjami.
Funkcja powinna wczytać te liczby do tablicy i znaleźć w nich wartość minimalną i maksymalną.*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

void funct(){
    FILE* file=fopen("test.txt", "r");
    if(file==0){
        printf("Nie mozna otworzyc pliku!");
    }
    int n=0, num[4];
    //fscanf() - pobiera wartości i omija ' '
    while((fscanf(file, "%d", &num[n]))!=EOF){
        n++;
    }
    int minimum=*min_element(num,num+4);
    cout<<"Minimalna: "<<minimum<<endl;;
    int maximum=*max_element(num,num+4);
    cout<<"Maksymalna: "<<maximum<<endl;
    fclose(file);
}

int main()
{
    //tworzenie pliku
    FILE* file=fopen("test.txt", "w");
    fprintf(file, "%d %d %d %d", 7, 6, 18, 36);
    fclose(file);
    funct();
    return 0;
}

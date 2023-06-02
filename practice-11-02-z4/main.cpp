/*Stwórz funkcję, która przyjmuje ścieżkę do pliku tekstowego.
W pliku tekstowym znajdują się liczby całkowite oddzielone pojedynczymi spacjami.
Funkcja powinna wczytać te liczby zwiększyć o jeden i ponownie zapisać do pliku.*/
#include <iostream>
using namespace std;

void add(){
    int arr[4];
    FILE* file=fopen("test.txt", "r");
    if(!file){
        cout<<"Nie mozna otworzyc pliku!"<<endl;
        return;
    }
    int n=0;
    while(fscanf(file, "%d", &arr[n])!=EOF){n++;}
    fclose(file);
    file=fopen("test.txt", "w");
    if(!file){
        cout<<"Nie mozna otworzyc pliku!"<<endl;
        return;
    }
    for(int i=0; i<4; ++i){
        arr[i]+=1;
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

int main()
{
    //tworzenie pliku
    FILE* file=fopen("test.txt", "w");
    fprintf(file, "%d %d %d %d", 2, 4, 6, 8);
    fclose(file);
    add();
    return 0;
}

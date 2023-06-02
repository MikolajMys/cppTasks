/*(1)Stwórz funkcję write_array(), która zapisze podaną w argumencie tablicę liczb zmiennoprzecinkowych (float)
do pliku (nazwa podana w argumencie funkcji) w postaci binarnej (nieformatowanej),
gdzie każdy element tablicy jest kodowany na czterech bajtach.
(2)Stwórz analogiczną funkcję read_array(), która wczyta z takiego pliku (nazwa podana w argumencie funkcji)
dane do przekazanej w argumencie tablicy liczb zmiennoprzecinkowych (float).
Funkcja powinna wczytać nie więcej elementów niż zadeklarowana wielkość tablicy i zwrócić rzeczywistą ilość wczytanych elementów.*/
#include <iostream>
#include <cstdio>
using namespace std;

void writeArray(char* fileName, float arr[], int size){
    FILE* file=fopen(fileName, "wb");
    if(!file){
        cout<<"Nie mozna otworzyc pliku!"<<endl;
        return;
    }
    fwrite(arr, sizeof(float), size, file);
    fclose(file);
}

int readArray(char* fileName, float arr[], int size){
    FILE* file=fopen(fileName, "rb");
    if(!file){
        cout<<"Nie mozna otworzyc pliku!"<<endl;
        return 0;
    }
    int numElements=fread(arr, sizeof(float), size, file);
    fclose(file);
    return numElements;
}

int main()
{
    const int size=5, sizeRes=100;
    float arr[size]={1.0, 2.5, 3.14, 4.67, 5.89};
    float arrRes[sizeRes];
    writeArray("test.bin", arr, size);
    cout<<readArray("test.bin", arrRes, sizeRes);

    return 0;
}

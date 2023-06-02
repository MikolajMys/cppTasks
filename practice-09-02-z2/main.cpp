/*Napisz program, który zapisze do pliku 10 dowolnych liczb całkowitych.*/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int num;
    FILE* file=fopen("test.txt", "w");
    if(!file){
        printf("Nie mozna otworzyc pliku!");
        return 1;
    }
    for(int i=0; i<10; ++i){
        scanf("%d", &num);
        fprintf(file, "%d", num);
    }
    fclose(file);
    return 0;
}

/*Wskaźniki i biblioteka standardowa - Zadanie 2.
Napisz program, który wyświetli wszystkie elementy tablicy za pomocą funkcji std::for_each.*/
#include <iostream>
#include <algorithm>
using namespace std;

void print(char i) {cout<<i<<"\t";}
int main()
{
    const int n = 5;
    char word[] = "dupa";
    for_each(word, word+n, print);
    return 0;
}

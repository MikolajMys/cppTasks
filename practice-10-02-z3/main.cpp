/*Napisz program, który usunie plik stworzony w poprzednim zadaniu.*/
#include <iostream>
using namespace std;

int main()
{
    if(remove("C:/Users/Dell/Desktop/c++/build-practice-09-02-z2-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/test.txt")==0)
        cout<<"Udalo sie usunac plik!"<<endl;
    else
        cout<<"Nie udalo sie usunac pliku!"<<endl;
    return 0;
}

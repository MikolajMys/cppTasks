/*Zdefiniuj klasę Vector, która będzie realizowała podstawową funkcjonalność dynamicznej tablicy liczb całkowitych typu int.
W klasie zdefiniuj metody:
- init() - inicjującą elementy składowe obiektu,
- int& at(int i) - zwracającą referencję na i-ty element tablicy,
- void append(int v) - dodającą element na koniec tablicy,
- void resize(int size) - zmieniającą rozmiar tablicy na nowy, zachowując elementy już dodane do tablicy,
- int size() - zwracającą rozmiar tablicy,
- void clear() - czyszczącą całą zawartość obiektu.
Napisz program, w którym przetestujesz implementację tej klasy.*/
#include <iostream>
using namespace std;

class Vector{
    int* arr;
    int size;
public:
    Vector(){
        arr=nullptr;
        size=0;
    }
    void init(int size){
        arr=new int[size];
        this->size=size;
        for(int i=0; i<size; ++i){
            arr[i]=i;
        }
    }
    int& at(int i){
        return arr[i];
    }
    void append(int v){
        arr[size-1]=v;
    }
    void resize(int size){
        int* newArr=new int[size];
        for(int i=0; i<this->size; ++i){
           newArr[i]=arr[i];
        }
        this->size=size;
        delete []arr;
        arr=newArr;
    }
    int getSize(){
        return size;
    }
    void clear(){
        arr=nullptr;
        size=0;
    }

};

int main()
{
    Vector v1;
    v1.init(6);
    v1.resize(7);
    //cout<<v1.at(0);
    v1.append(2);
    //cout<<v1.at(6);
    //cout<<v1.getSize();
    v1.clear();
    cout<<v1.at(0);
    return 0;
}

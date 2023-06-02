/*Zaimplementuj klasę List realizującą funkcjonalność jednokierunkowej listy wskaźnikowej. W klasie zdefiniuj metody:
- konstruktory - domyślny, (konstruktor kopiujący uczyń prywatnym)
- int size() - zwracającą rozmiar tablicy,
- int& at(int i) - zwracającą referencję na i-ty element tablicy,
- int* find(int v) - zwracającą wskaźnik na znaleziony element v lub nullptr jeżeli takiego elementu nie ma na liście
- void append(int v) - dodającą element na koniec listy,
- void insert(int i, int v) - wstawiającą element v za i-tym elementem,
- void remove(int i) - usuwającą i-ty element z listy
- void clear() - czyszczącą całą zawartość obiektu.
Napisz program, w którym przetestujesz implementację tej klasy.*/
#include <iostream>
using namespace std;

class List{
    int value;
    List* next;
    List (List& copy){
        value=copy.value;
        next=copy.next;
    }
public:
    List(){
        value=0;
        next=nullptr;
    };
    void makeList(int size){
        List* list = this;
        for (int i = 0; i <=size; ++i) {
            list->value = i;

            List* newList = new List();

            list->next = newList;

            list = newList;
        }
    }
    int size(){
        int counter=0;
        List* list = this;
        while(list->next!=nullptr){
            list=list->next;
            counter++;
        }
        return counter;
    }
    int& at(int index){
        List* list = this;
        for (int i=0; i<index; ++i) {
            list = list->next;
        }
        return list->value;
    }
    int* find(int v){
        List* list = this;
        while(list->next!=nullptr){
            if(list->value==v){
                return &list->value;
            }
            list=list->next;
        }
        return nullptr;
    }
    void append(int v){
        List* list = this;
        while(list->next!=nullptr){
            list=list->next;
        }
        list->next=new List();
        list->value=v;
    }
    void insert(int index, int v){
        List* list = this;
        for (int i=0; i<index+1; ++i) {
            list = list->next;
        }
        list->value=v;
    }
    void remove(int index){
        List* list = this;
        for (int i=0; i<index-1; ++i) {
            list = list->next;
        }
        List* remove=list->next;
        list->next=remove->next;
        delete remove;
    }
    void clear(){
        List* list = this;
        while(list->next!=nullptr){
            list->value=NULL;
            list=list->next;
        }
    }
};

int main()
{
    List list1;
    list1.makeList(6);
    cout<<list1.at(1)<<endl;
    cout<<list1.size()<<endl;
    cout<<*list1.find(3)<<endl;
    list1.append(9);
    cout<<list1.at(7)<<endl;
    list1.insert(0, 8);
    cout<<list1.at(1)<<endl;
    list1.remove(6);
    cout<<list1.at(6)<<endl;
    list1.clear();
    cout<<list1.at(2)<<endl;
    return 0;
}

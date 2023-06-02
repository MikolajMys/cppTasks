/*Zdefiniuj typ wyliczeniowy AnimalType zawierający kilka typowych nazw zwierząt domowych.
Zaprojektuj klasę Animal, która posiada dwa pola:
(1)zmienną typu wyliczeniowego AnimalType oraz
(2)tablicę będącą maksymalnie 10 znakową nazwą pupila.
Dodatkowo klasa powinna zawierać metodę say_something(int n).
Funkcja say_something() w zależności od typu zwierzęcia powinna wyświetlić odpowiedni komunikat np. dla kota "miał" oraz
powtórzyć go n razy, gdzie n zostało przekazane w argumencie metody.
Uzupełnij klasę o odpowiedni destruktor oraz konstruktor kopiujący.
Napisz program w języku C++, który przetestuje działanie tej klasy.*/
#include <iostream>
#include <cstring>
using namespace std;

enum AnimalType{
    Kot,
    Pies,
    Krowa,
    Owca
};

class Animal{
    AnimalType type;
    char name[11];
public:
    Animal(AnimalType type, const char name[]){
        strncpy(this->name, name, 11);
        this->type=type;
    }

    void say_something(int n){
        if(type==Kot){
            for(int i=0; i<n; ++i){
                cout<<i+1<<".miau!"<<endl;
            }
        }
        else if(type==Pies){
            for(int i=0; i<n; ++i){
                cout<<i+1<<".hau!"<<endl;
            }
        }
        else if(type==Krowa){
            for(int i=0; i<n; ++i){
                cout<<i+1<<".muuu!"<<endl;
            }
        }
        else if(type==Owca){
            for(int i=0; i<n; ++i){
                cout<<i+1<<".beee!"<<endl;
            }
        }
        else{cout<<"Nie znane zwierze!"<<endl;}
    }
    Animal(const Animal& copy){
        strncpy(this->name,copy.name, 11);
        this->type=copy.type;
    }
    ~Animal(){}
};

int main()
{
    int n=3;
    Animal a1(Kot, "Filemon");
    a1.say_something(n);
    //kopia
    Animal a12=a1;
    a12.say_something(n);
    Animal a2(Pies, "Burek");
    a2.say_something(n);
    Animal a3(Krowa, "Basia");
    a3.say_something(n);
    Animal a4(Owca, "Michal");
    a4.say_something(n);

    return 0;
}

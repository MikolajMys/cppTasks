/*Zdefiniuj typ złożony Person mający dwa pola: liczbę całkowitą - age, napis - name. W funkcji głównej stwórz obiekt tego typu,
a następnie stwórz jego głęboką kopię. Klasa Person może mieć dowolną ilość metod pomocniczych.
Następnie stwórz dynamiczny obiekt klasy Person oraz jego głęboką kopię. Jaki problem występuje podczas kasowania tych obiektów.*/
#include <iostream>
#include <string>
using namespace std;

class Person
{
    int age;
    string name;
public:
    //adding new object constructor
    Person(int age, string name){
        this->age=age;
        this->name=name;
    }
    //making copy constructor
    Person(Person &copy){
        this->age=copy.age;
        this->name=copy.name;
    }
    //getters
    int getAge(){
        return age;
    }
    string getName(){
        return name;
    }
    void set(int age, string name){
        this->age=age;
        this->name=name;
    }
};

int main()
{
    Person p1(23, "Stef");
    Person p2=p1;
    cout<<p1.getName()<<" "<<p1.getAge()<<endl;
    cout<<"Copied: "<<p2.getName()<<" "<<p2.getAge()<<endl;
//    Person* p3=new Person(34, "Mike");
//    Person* p4=new Person(*p3);
//    cout<<p3->getName()<<" "<<p3->getAge()<<endl;
//    cout<<"Copied: "<<p4->getName()<<" "<<p4->getAge()<<endl;
//    delete p3;
//    delete p4;
    p2.set(52, "Dave");
    cout<<p2.getName()<<" "<<p2.getAge()<<endl;
    cout<<p1.getName()<<" "<<p1.getAge()<<endl;
    return 0;
}

/*Zaprojektuj i zaimplementuj klasę String do obsługi napisów. Klasa ta powinna mieć metody:
- konstruktor domyślny, konstruktor inicjujący i konstruktor kopiujący
- destruktor
- length() - zwracającą długość napisu
- cstring() - zwracającą wskaźnik na tablicę znakową w tylu c
- append(...) - dodającą do aktualnego napisu inny napis
- clear() - czyszczącą napis
- empty() - zwracającą informację czy napis jest pusty
- print() - drukującą napis na ekranie
- operator przypisania '=' - zadbaj o głęboką kopię obiektu
Przetestuj tworzoną klasę w programie głównym na obiektach automatycznych i dynamicznych.*/
Konstruktory i destruktory
Zadanie 3.

#include <iostream>
#include <cstring>
using namespace std;

class String{
    char str[100];
    int length;
public:
    String(){
        str[0]='\0';
        length=0;
    };
    String(char str[]){
        length=strlen(str);
        strncpy(this->str, str, length+1);
    }
    String(String& copy){
        length=strlen(copy.str);
        strncpy(this->str, copy.str, length+1);
    }
    ~String(){};
    int getLength(){
        return length;
    }
    char* cstring(){
        return str;
    }
    void append(char strAdd[]){
        int len=strlen(strAdd);
        strncat(str, strAdd, len+1);
    }
    void clear(){
//        strcpy(str, 0);
        length = 0;
        str[0] = '\0';
    }
    bool empty(){
        return length == 0;
    }
    void print(){
            cout<<str<<endl;
    }
    String& operator=(String& copy){
        length = copy.length;
        strncpy(str, copy.str, length+1);
        return *this;
    }

};

int main()
{
    String s1("Hello");
    String s2=s1;
    s2.append(", world!");
    s1.print();
    s2.clear();
    cout<<(s2.empty()? "empty":"not empty")<<endl;
    String* s3=new String("Hello");
    s3->print();
    String* s4=new String(*s3);
    cout<<s4->cstring();
    return 0;
}

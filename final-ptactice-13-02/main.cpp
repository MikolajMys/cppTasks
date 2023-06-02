/*Zdefiniuj funkcję str_sort(), która przyjmuje w argumencie napis str.
Napis str może zawierać jedynie małe i wielkie litery oraz spacje.
Funkcja ma zamienić wszystkie wielkie litery na male a następnie posortować znaki w tym napisie oraz zwrócić powstały napis.

Zdefiniuj funkcję letter_count(), która przyjmie w parametrze posortowany napis z funkcji str_sort() i
wyświetli na ekranie unikalne znaki tego napisu (bez powtórzeń) oraz liczbę ich wystąpień (zobacz przykład).
Napisz program, który sprawdzi działanie tych funkcji.
W tym zadaniu nie można używać funkcji/klas bibliotecznych oprócz funkcji wyświetlania na konsoli*/
//A-Z[65-90]
//a-z[97-122]
//różnica miedzy dużą a małą 32
#include <iostream>
using namespace std;

char* strSort(char* str){
    //zmiana z duzych na male
    for(int i=0; str[i]!='\0'; ++i){
        if(*(str+i)>=65&&*(str+i)<=90){
            *(str+i)+=32;
        }
    }
    //sortowanie
    for(int i=0; str[i]!='\0'; ++i){
        for(int j=i+1; str[j]!='\0'; ++j){
            if(*(str+i)>*(str+j)){
                char temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
    }
    return str;
}
//kurestwo
void letterCount(char* str){
    bool printed[256]={false};
    for(int i=0; str[i]!='\0'; ++i){
        if(printed[(int)*(str+i)]==false){
            int counter=1;
            for(int j=i+1; str[j]!='\0'; ++j){
                if(*(str+i)==*(str+j)){
                    counter++;
                }
            }
            cout<<*(str+i)<<"\t"<<counter<<endl;
            printed[(int)*(str+i)]=true;
        }
    }
}

int main()
{
    char str[23]="Practice Makes Perfect";
    strSort(str);//aaccceeeefikmpprrstt
    letterCount(str);
    return 0;
}

/*Napisz program, który policzy wszystkie słowa w podanym napisie.*/
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char arr[20];
    cin.getline(arr, 20);
    char sep[]=" ,.-";
    char* res;
    int counter=0;
    res=strtok(arr, sep);
    while(res!=NULL){
        res=strtok(NULL,sep);
        counter++;
    }
    cout<<counter;

    return 0;
}

/*Napisz program, który uporządkuje alfabetycznie tablicę napisów za pomocą funkcji qsort oraz za pomocą funkcji std::sort. */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int comp(){

}

int main(){
    const int n=4;
    char** str=new char*[n];
    char* temp=new char[9];
    for(int i=0; i<n; ++i){
        cin>>temp;
        int size=strlen(&temp[i]);
        *(str+i)=new char[size];
        for(int j=0; j<=size; ++j){
            str[i][j]=*temp;
        }
    }
    for(int i=0;i<n;i++){
        cout<< str[i] <<endl;
    }
    return 0;
}

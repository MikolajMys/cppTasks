/*Zdefiniuj klasę Matrix3x3 reprezentującą macierz o rozmiarze 3x3 liczb zmiennoprzecinkowych.
Zdefiniuj metodę print() wypisującą na ekranie elementy tej macierzy.
Zdefiniuj metodę add() dodawania liczby do takiej macierzy; funkcja ma zwracać nowo obliczoną macierz. Napisz program testujący.*/
#include <iostream>
#include <cstdio>
using namespace std;

class Matrix
{
    float arr[9];
public:
    Matrix(float arr[]){
        for(int i=0; i<9; ++i){
            this->arr[i]=arr[i];
        }
    }
    void print(){
        for (int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j){
                printf("%.1f\t", arr[j+i*3]);
            }
            cout<<endl;
        }
    }
    Matrix add(float n){
        float mResult[9];
        for (int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j){
                mResult[j+i*3]=arr[j+i*3]+n;
            }

        }
        return Matrix(mResult);
    }
};

int main()
{
    float arr[9]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
    Matrix m1(arr);
    m1.print();
    Matrix m2(m1.add(0.3));
    m2.print();
    return 0;
}

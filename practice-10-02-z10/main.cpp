/*Zdefiniuj strukturę vec2d, składającą się z dwóch pół x i y typu zmiennoprzecinkowego,
która będzie reprezentowała wektor dwuwymiarowy. Utwórz tablicę automatyczną obiektów tego typu.
Z pomocą funkcji z biblioteki <algorithm>:
- wypełnij tę tablicę wektorami, których poszczególne współrzędne spełniają zależność:
    x jest liczbą pseudolosową z zakresu domkniętego <-1, 1> a y jest liczbą przeciwną do x (std::generate);
- wypisz na ekranie wszystkie elementy tej tablicy (std::for_each);
- posortuj wszystkie wektory w tablicy malejąco względem współrzędnej y (std::sort);
- znajdź wektor o najmniejszej współrzędnej x (std::min_element).*/
Klasy i obiekty
Zadanie 10.

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

struct vec2d{
    float x, y;
};

vec2d makeVec(){
    vec2d arr;
    arr.x=rand()%3-1;
    arr.y=-arr.x;
    return arr;
}
void printVec(vec2d arr){
    cout<<"("<<arr.x<<", "<<arr.y<<")"<<endl;
}
bool compareVecY(vec2d arr1, vec2d arr2){
    return arr1.y > arr2.y;
}
bool compareVecX(vec2d arr1, vec2d arr2){
    return arr1.x < arr2.x;
}

int main()
{
    srand(time(0));
    int n=4;
    vec2d arr[n];
    cout<<"Before sort: "<<endl;
    generate(arr, arr+4, makeVec);
    for_each(arr, arr+4, printVec);
    cout<<"After sort: "<<endl;
    sort(arr, arr+4, compareVecY);
    for_each(arr, arr+4, printVec);
    cout<<"Min X: "<<endl;
    vec2d minX=*min_element(arr, arr+4, compareVecX);
    printVec(minX);
    return 0;
}

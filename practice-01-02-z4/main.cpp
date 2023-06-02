/*Napisz funkcję, która otrzymuje jako argumenty tablicę typu Point
i zwraca jako wartość najmniejszą spośród odległości pomiędzy punktami przechowywanymi w tablicy points.
Zakładamy, że otrzymana w argumencie tablica ma co najmniej dwa argumenty.*/
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    float x, y;
public:
    Point(float xx=0, float yy=0){
        x=xx;
        y=yy;
    }
    float getX(){
       return x;
    }
    float getY(){
       return y;
    }
    static float getDistance(Point &a, Point &b){
        return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
    }
};

float minDistance(Point points[], int n){
    float minDist=Point::getDistance(points[0], points[1]);
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            float dist=Point::getDistance(points[i], points[j]);
            if (dist<minDist){
                minDist=dist;
            }
        }
    }
    return minDist;
}

int main()
{
    const int n=3;
    Point points[n]={{0,0}, {4,0}, {2,0}};
    cout<<"Najmniejsza odleglosc: "<<minDistance(points, n)<<endl;
    return 0;
}

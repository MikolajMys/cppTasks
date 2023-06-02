/*Napisz program, który zdefiniuje typ złożony Point reprezentujący punkt w dwuwymiarowej przestrzeni euklidesowej.
Punkt powinien być opisany za pomocą dwóch współrzędnych.
Zadeklaruj wszystkie pola klasy jako prywatne i dodaj odpowiednie akcesory.
Zdefiniuj funkcję globalną do pobierania od użytkownika współrzędnych i wstawiania ich do obiektu klasy Point.
Wczytaj od użytkownika współrzędne dwóch punktów.
Oblicz i wyświetl odległość pomiędzy tymi punktami - czy lepiej to zrobić w funkcji globalnej czy metodzie?*/

#include <iostream>
#include <cmath>
using namespace std;

class Point{
    private:
    float x, y;
    public:
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
    void setX(float x){
        this->x=x;
    }
    void setY(float y){
        this->y=y;
    }
    static float getDistance(Point point1, Point point2){
        float x1 = point1.getX();
        float y1 = point1.getY();
        float x2 = point2.getX();
        float y2 = point2.getY();
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }
//    float getDistance(Point point2){
//        float x1 = this->x;
//        float y1 = this->y;
//        float x2 = point2.getX();
//        float y2 = point2.getY();
//        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
//    }
};
void setPointXY(Point& point){
    float x,y;
    cin>>x;
    point.setX(x);
    cin>>y;
    point.setY(y);
}
//pierwowzór
//float getDistanceOfXY(Point point1, Point point2){
//    float x1 = point1.getX();
//    float y1 = point1.getY();
//    float x2 = point2.getX();
//    float y2 = point2.getY();
//    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
//}
int main()
{
    Point point1, point2;
    setPointXY(point1);
    setPointXY(point2);
    cout<<Point::getDistance(point1, point2);
//    cout<<point1.getDistance(point2);
    return 0;
}

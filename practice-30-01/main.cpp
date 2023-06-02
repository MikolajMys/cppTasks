#include <iostream>
#include <cmath>
using namespace std;

class Point{
    private:
    int x, y;
    public:
    Point(int x=0, int y=0){
        this->x=x;
        this->y=y;
    }
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

};

int main(){


    Point points1[] = {Point(1, 2), Point(3, 4)};
    Point points2[] = {Point(2, 3), Point(4, 5)};


    for (int i = 0; i < 2; ++i) {
        int distance = Point::getDistance(points1[i], points2[i]);
    }


    return 0;
}



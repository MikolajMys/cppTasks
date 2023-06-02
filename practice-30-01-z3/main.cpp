/*Napisz funkcję, która otrzymuje jako argumenty tablice points1 i points2
o argumentach typu Point i przepisuje zwartość tablicy points1 do tablicy points2.*/
#include <iostream>
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
};

void copy_points(Point points1[], Point points2[], int size){
    for (int i = 0; i < size; ++i) {
        points2[i] = points1[i];
    }
}

int main(){

    const int size=3;
    Point points1[size] = {Point(1, 2), Point(3, 4), Point(5, 6)};
    Point points2[size];

    copy_points(points1, points2, size);

    for (int i = 0; i < size; i++) {
        std::cout << "Point " << i + 1 << ": (" << points2[i].getX() << ", " << points2[i].getX() << ")" << std::endl;
    }

    return 0;
}

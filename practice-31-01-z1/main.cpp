/*Zaliczenie z pewnego przedmiotu wygląda tak, że studenci piszą dwa kolokwia, oba za 50 punktów.
Ocena dostateczna przyznawana jest w przedziale (50-60] punktów, i rośnie o połowę oceny co 10 punktów aż do 100.

Student, który nie otrzyma zaliczenia, może poprawić jedno z kolokwiów ale wtedy może otrzymać co najwyżej ocenę dostateczną.
Zakładamy, że student, który nie otrzyma zaliczenia, zawsze będzie poprawiał kolokwium, które gorzej napisał.

Napisz klasę, w której znajduje się: numer indeksu studenta, wynik pierwszego kolokwium, wynik drugiego kolokwium i wynik poprawy.
Numer indeksu musi być przekazany w konstruktorze klasy.  Wszystkie pola tej klasy mają być prywatne.

Napisz funkcję, która przyjmie tablicę obiektów takich klas a zwróci średnią ocen (nie punktów) zdobytych z tego przedmiotu.
Tablicę z wynikami cząstkowymi zainicjuj pseudolosowo.*/
//2x50pkt.  KI+KII
//Ocena dst: 50-60 punktów
//Ocena dst+: 60-70 punktów
//Ocena db: 70-80 punktów
//Ocena db+: 80-90 punktów
//Ocena bdb: 90-100 punktów
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Student{
    private:
        int index;
        int exam1;
        int exam2;
        int examResit;
    public:
        Student(int ind=0, int ex1=0, int ex2=0, int examRes=0){
            index=ind;
            exam1=ex1;
            exam2=ex2;
            examResit=examRes;
        }
        int getIndex(){
            return index;
        }
        int getExam1(){
            return exam1;
        }
        int getExam2(){
            return exam2;
        }
        int getExamResit(){
            return examResit;
        }

        float getMark(){
            int score=0;
            if (exam1+exam2<50){
                score=max(exam1, exam2)+examResit;
                if (score > 50) {
                    return 3;
                } else {
                    return 0;
                }
            } else {
                score = exam1 + exam2;
                if(score<60)
                    return 3;
                else if(score<70)
                    return 3.5;
                else if(score<80)
                    return 4;
                else if(score<90)
                    return 4.5;
                else
                    return 5;
            }
        }
};

float getStudentsAvarage(Student students[], int n){
    float sum=0;
    for (int i = 0; i < n; ++i) {
        sum+=students[i].getMark();
    }
    return sum/n;

}

int main() {
    const int n=4;
//    Student students[n]={
//        {20, 30, 39, 0},
//        {21, 30, 39, 0},
//        {22, 30, 39, 0},
//        {23, 30, 39, 0}
//    };
    srand(time(0));
    Student students[n];
    for (int i = 0; i < n; ++i) {
        students[i]=Student(i, rand()%51, rand()%51, rand()%51);
    }
    cout<<getStudentsAvarage(students, n);

return 0;
}

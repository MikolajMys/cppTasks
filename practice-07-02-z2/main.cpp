/*Napisz klasę Mutex, której obiekty w każdym momencie są w jednym z dwóch stanów wolny lub zajęty.
Bezpośrednio po utworzeniu obiekt typu Mutex powinien być w stanie wolny. Klasa powinna udostępniać następujące publiczne metody:

- lock(), której wywołanie zmienia stan mutexa z wolny na zajęty (w przypadku,
gdy mutex jest już w stanie zajęty, metoda nie powinna zmieniać jego stanu),

- release(), której wywołanie zmienia stan mutexa z zajęty na wolny (w przypadku,
gdy jest już w stanie wolny, metoda nie powinna zmieniać jego stanu),

- state() zwracającą wartość true gdy mutex jest w stanie wolny i false w przeciwnym wypadku.

Zadbaj o odpowiednią hermetyzację klasy i o prawidłową inicjalizację obiektów.
W programie głównym stwórz (1)dynamiczną tablicę obiektów Mutex, (2)automatyczną tablicę dynamicznych obiektów Mutex,
(3)dynamiczną tablicę dynamicznych obiektów Mutex oraz (4)dwuwymiarową tablicę dynamiczną obiektów Mutex. Zadbaj o poprawne zwalnianie pamięci.*/

#include <iostream>
using namespace std;

class Mutex{
        bool state;
    public:
        Mutex(){
            state=true;
        }
        void lock(){
            if(state)
                state=false;
            else
                state=false;
        }
        void release(){
            if(!state)
                state=true;
            else
                state=true;
        }
        bool getState(){
            return state;
        }
};

int main()
{
    cout<<"1.dynamiczna tablica obiektow Mutex:"<<endl;
    Mutex* mutexes1=new Mutex[3];
    for (int i = 0; i < 3; ++i) {
        cout << "Mutex " << i+1 << " state: " << (mutexes1[i].getState() ? "true": "false" ) << endl;
    }
    cout<<endl;
    cout<<"2.automatyczna tablica dynamicznych obiektow Mutex"<<endl;
    Mutex mutexes2[3];
    for (int i = 0; i < 3; ++i) {
        cout << "Mutex " << i+1 << " state: " << (mutexes2[i].getState() ? "true": "false" ) << endl;
    }
    cout<<endl;
    cout<<"3.dynamiczna tablica dynamicznych obiektow Mutex"<<endl;
    Mutex** mutexes3=new Mutex*[3];
    for (int i = 0; i < 3; ++i){
        mutexes3[i]=new Mutex();
    }
    for (int i = 0; i < 3; ++i) {
        cout << "Mutex " << i+1 << " state: " << (mutexes3[i]->getState() ? "true": "false" ) << endl;
    }
    cout<<endl;
    cout<<"4.dwuwymiarowa tablica dynamiczna obiektow Mutex"<<endl;
    Mutex** mutexes4=new Mutex*[3];
    for (int i = 0; i < 3; ++i){
        mutexes4[i]=new Mutex[3];
    }
    for (int i = 0; i < 3; ++i) {
        cout << "Mutex " << i+1 << " state: " << (mutexes4[i]->getState() ? "true": "false" ) << endl;
    }

    delete[] mutexes1;
    for (int i = 0; i < 3; ++i){
        delete mutexes3[i];
    }
    delete[] mutexes3;
    for (int i = 0; i < 3; ++i){
        delete[] mutexes4[i];
    }
    delete[] mutexes4;

    return 0;
}
/*#include <iostream>
using namespace std;

class Mutex{
    bool state;
public:
    Mutex(){
        state=true;
    }
    void lock(){
        if(state){state=false;}
    }
    void release(){
        if(!state){state=true;}
    }
    bool getState(){
        return state;
    }
};

int main()
{
    const int size=5;
    //dynamiczna tablica obiektów Mutex:
    Mutex* mutArr1=new Mutex[size];
    for(int i=0; i<size; ++i){
        cout<<((mutArr1+i)->getState()?"true ":"false ");
    }
    delete[] mutArr1;
    cout<<endl;
    //automatyczna tablica dynamicznych obiektów Mutex:
    Mutex mutArr2[size];//?
    for(int i=0; i<size; ++i){
        mutArr2[i]=*new Mutex();
    }
    for(int i=0; i<size; ++i){
        cout<<(mutArr2[i].getState()?"true ":"false ");
    }
    cout<<endl;
    //dynamiczna tablica dynamicznych obiektów Mutex:
    Mutex** mutArr3=new Mutex*[size];
    for(int i=0; i<size; ++i){
        *(mutArr3+i)=new Mutex();
    }
    for(int i=0; i<size; ++i){
        cout<<(mutArr3[i]->getState()?"true ":"false ");
    }
    for(int i=0; i<size; ++i){
        delete mutArr3[i];
    }
    delete[] mutArr3;
    cout<<endl;
    //dwuwymiarową tablicę dynamiczną obiektów Mutex:
    Mutex** mutArr4=new Mutex*[size];
    for(int i=0; i<size; ++i){
        *(mutArr4+i)=new Mutex[size];
    }
    for(int i=0; i<size; ++i){
        cout<<(mutArr4[i]->getState()?"true ":"false ");
    }
    for(int i=0; i<size; ++i){
        delete mutArr4[i];
    }
    delete[] mutArr4;
    cout<<endl;
    return 0;
}
*/

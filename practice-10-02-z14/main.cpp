/*(1)Zdefiniuj typ wyliczeniowy, służący do przechowywania informacji o stanie połączenia internetowego,
o trzech wartościach odpowiadających trzem stanom:
-połączenie nawiązane (connected),
-połączenie nienawiązane (disconnected) i
-połączenie w trakcie nawiązywania (connecting).
(2)Następnie zdefiniuj strukturę komputer przechowującą:
-stan połączenia,
-IP podłączonego komputera (jako napis) oraz
-nazwę jego właściciela.
Napisz funkcję, która jako argument otrzymuje strukturę komputer
i wyświetla na standardowym wyjściu jej zawartość w sposób przyjazny dla użytkownika.*/
Klasy i obiekty
Zadanie 14.

#include <iostream>
#include <string>
using namespace std;

enum ConnectionStatus{
    connected,
    disconnected,
    connecting
};

class Computer{
    ConnectionStatus status;
    string ip;
    string name;
public:
    Computer(ConnectionStatus status, string ip, string name){
        this->status=status;
        this->ip=ip;
        this->name=name;
    }
    void getInfo(){
        if(status==connected){cout<<"Status: connected"<<endl;}
        else if(status==disconnected){cout<<"Status: disconnected"<<endl;}
        else{cout<<"Status: connecting"<<endl;}
        cout<<"Ip: "<<ip<<endl;
        cout<<"Pc name: "<<name<<endl;
    }
};

void print(Computer pc){
    pc.getInfo();
    cout<<endl;
}

int main()
{
    Computer pc1(connected, "80.29.41.234", "Dell");
    Computer pc2(connecting, "225.151.11.197", "Lenovo");
    print(pc1);
    print(pc2);
    return 0;
}
